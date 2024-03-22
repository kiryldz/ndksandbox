//
// Created by Kiryl Dzehtsiarenka on 22.3.2024.
//

#include "test.hpp"

std::string Test::getError() {
//    try {
//        throw std::runtime_error("runtime_error");
//    } catch (const std::exception & e) {
////        __android_log_print(ANDROID_LOG_ERROR, "TAGG", "CAUGHT EXCEPTION");
//        return e.what();
//    }
    throw MyException("runtime_error");
}

std::string Test::tryCatch() {
    try {
        throw MyException("runtime_error");
    } catch (const std::exception & e) {
//        __android_log_print(ANDROID_LOG_ERROR, "TAGG", "CAUGHT EXCEPTION");
        return e.what();
    }
}
