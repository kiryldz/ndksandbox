package com.dz.ndksandbox

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.dz.nativelibndk23.NativeLibNdk23
import com.dz.ndksandbox.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    @SuppressLint("SetTextI18n")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = "${stringFromJNI()}\n${NativeLibNdk23().stringFromJNI()}"
    }

    /**
     * A native method that is implemented by the 'ndksandbox' native library,
     * which is packaged with this application.
     */
    private external fun stringFromJNI(): String

    companion object {
        // Used to load the 'ndksandbox' library on application startup.
        init {
            System.loadLibrary("ndksandbox")
        }
    }
}