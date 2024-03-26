package com.dz.ndksandbox

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.dz.nativelibndk21.NativeLibNdk21
import com.dz.nativelibndk23.NativeLibNdk23
import com.dz.ndksandbox.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    @SuppressLint("SetTextI18n")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

//        val libNdk23Instance = NativeLibNdk23()
//        val pointerFromNdk23 = libNdk23Instance.getPointer()
//        val libNdk21Instance = NativeLibNdk21()
//        binding.sampleText.text = libNdk21Instance.processPointer(pointerFromNdk23)

        val libNdk23Instance = NativeLibNdk23()
        libNdk23Instance.stringFromJNI()

        val libNdk21Instance = NativeLibNdk21()
        libNdk21Instance.stringFromJNI()
    }
}