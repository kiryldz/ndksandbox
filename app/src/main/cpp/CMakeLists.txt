cmake_minimum_required(VERSION 3.22.1)


project("ndksandbox")

#message(FATAL_ERROR "11111 ${ANDROID_NDK}")

add_library(${CMAKE_PROJECT_NAME} SHARED
        # List C/C++ source files with relative paths to this CMakeLists.txt.
        native-lib.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
        # List libraries link to the target library
        android
        log)