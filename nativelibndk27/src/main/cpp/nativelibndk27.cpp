#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_dz_nativelibndk27_NativeLibNdk27_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}