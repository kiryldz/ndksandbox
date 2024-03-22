cmake_minimum_required(VERSION 3.22.1)


project("nativelibndk23")

#message(FATAL_ERROR "11111 ${ANDROID_NDK}")

################ BLOCK FOR USING CUSTOM STL ################

## first disable usage of builtin STL, in order to avoid conflicts
#add_link_options( -nostdlib++ )
#add_compile_options( -nostdinc++ )
#
#string( TOLOWER "${CMAKE_HOST_SYSTEM_NAME}" host_system )
## include definitions
#include_directories(SYSTEM ${ANDROID_NDK}/toolchains/llvm/prebuilt/${host_system}-x86_64/sysroot/usr/include/c++/v1 )
#
## as we build c++ with custom namespace `__mbx1` (see https://android.googlesource.com/toolchain/llvm-project/+/refs/heads/android12-release/libcxx/CMakeLists.txt#173)
## we should also define it correctly here so that things like std:: are resolved correctly
#add_compile_definitions(_LIBCPP_ABI_NAMESPACE=__mbx1)
#
## finally, link the customly built libraries
#link_libraries(
#        ${CMAKE_CURRENT_LIST_DIR}/../libs/${ANDROID_ABI}/libc++.a
#        ${CMAKE_CURRENT_LIST_DIR}/../libs/${ANDROID_ABI}/libc++abi.a
#)
#
## add correct link flags for armv7
## Usually those are added by the official android toolchain, but only when libc++ is selected
#if ( ${ANDROID_ABI} STREQUAL "armeabi-v7a" )
#    add_link_options( "-Wl,--exclude-libs,libunwind.a" )
#endif()
#
## also make sure to link with the default C runtime library
#add_link_options( "-lc" )

################ END OF BLOCK FOR USING CUSTOM STL ################

add_library(${CMAKE_PROJECT_NAME} SHARED
        # List C/C++ source files with relative paths to this CMakeLists.txt.
        nativelibndk23.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
        # List libraries link to the target library
        android
        log)