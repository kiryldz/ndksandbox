#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_dz_nativelibndk23_NativeLibNdk23_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++ (NDK 23)";
    return env->NewStringUTF(hello.c_str());
}