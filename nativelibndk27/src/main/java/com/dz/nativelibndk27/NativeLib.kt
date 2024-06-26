package com.dz.nativelibndk27

class NativeLibNdk27 {

    /**
     * A native method that is implemented by the 'nativelibndk27' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'nativelibndk27' library on application startup.
        init {
            System.loadLibrary("nativelibndk27")
        }
    }
}