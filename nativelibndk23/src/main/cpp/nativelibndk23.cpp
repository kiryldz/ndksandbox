#include <jni.h>
#include <string>

#include "android/log.h"

#include "test.hpp"

extern "C" JNIEXPORT jstring JNICALL
Java_com_dz_nativelibndk23_NativeLibNdk23_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++ (NDK 23): ";

    auto test = std::make_unique<Test>();

    std::exception_ptr eptr;

    try {
        test->getError();
    } catch(...) {
        eptr = std::current_exception();
    }

    std::string error;

    try {
        std::rethrow_exception(eptr);
    } catch (const MyException& e) {
        error = e.what();
    }

    return env->NewStringUTF(error.c_str());

//    try {
//        return env->NewStringUTF((hello + test->getError()).c_str());
//    } catch (const std::exception & e) {
//        return env->NewStringUTF("EXCEPTION");
//    }
}

extern "C" JNIEXPORT jlong JNICALL
        Java_com_dz_nativelibndk23_NativeLibNdk23_getPointer(
                JNIEnv* env,
                jobject /* this */) {
//    auto test = std::make_unique<Test>();
    auto test = new Test();

    auto* func = new std::function<std::string()>([&test] {
        __android_log_print(ANDROID_LOG_ERROR, "KIRYLDD", "111111");
        return test->tryCatch();
//        return "HELLLO";
    });
    auto pointer = reinterpret_cast<jlong>(func);
    __android_log_print(ANDROID_LOG_ERROR, "KIRYLDD", "IN LIB POINTER %p", func);
    return pointer;
}