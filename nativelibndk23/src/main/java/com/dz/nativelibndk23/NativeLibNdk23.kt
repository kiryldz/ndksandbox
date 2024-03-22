package com.dz.nativelibndk23

class NativeLibNdk23 {

    /**
     * A native method that is implemented by the 'nativelibndk23' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'nativelibndk23' library on application startup.
        init {
            System.loadLibrary("nativelibndk23")
        }
    }
}