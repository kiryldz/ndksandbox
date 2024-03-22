#include <jni.h>
#include <string>

#include "android/log.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_dz_ndksandbox_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dz_ndksandbox_MainActivity_processPointer(
        JNIEnv* env,
        jobject /* this */,
        jlong pointer) {
    auto* fptr = reinterpret_cast<std::function<std::string()>*>(pointer);

    __android_log_print(ANDROID_LOG_ERROR, "KIRYLDD", "IN APP POINTER %p", fptr);

    return env->NewStringUTF((*fptr)().c_str());
}