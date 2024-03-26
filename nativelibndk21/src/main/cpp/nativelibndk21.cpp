#include <jni.h>
#include <string>

#include "android/log.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_dz_nativelibndk21_NativeLibNdk21_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    try {
        throw std::runtime_error("ERROR NDK 21");
    } catch (const std::exception& e) {
        return env->NewStringUTF(e.what());
    }
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dz_nativelibndk21_NativeLibNdk21_processPointer(
        JNIEnv* env,
        jobject /* this */,
        jlong pointer) {
    auto* fptr = reinterpret_cast<std::function<std::string()>*>(pointer);

    __android_log_print(ANDROID_LOG_ERROR, "KIRYLDD", "IN APP POINTER %p", fptr);

    return env->NewStringUTF((*fptr)().c_str());
}