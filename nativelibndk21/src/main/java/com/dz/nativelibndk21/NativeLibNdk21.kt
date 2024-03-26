package com.dz.nativelibndk21

class NativeLibNdk21 {

    external fun stringFromJNI(): String

    external fun processPointer(pointer: Long): String

    companion object {
        // Used to load the 'nativelibndk21' library on application startup.
        init {
            System.loadLibrary("nativelibndk21")
        }
    }
}