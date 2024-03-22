plugins {
    id("com.android.library")
    id("org.jetbrains.kotlin.android")
}

android {
    namespace = "com.dz.nativelibndk23"
    compileSdk = 34

    defaultConfig {
        minSdk = 21

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
        consumerProguardFiles("consumer-rules.pro")
        ndk {
            externalNativeBuild {
                cmake {
                    arguments.add("-DANDROID_STL=c++_shared")
                    arguments.add("-DCMAKE_BUILD_TYPE=Release")
//                    arguments.add("-DANDROID_STL=none")
                }
            }
        }

        ndkVersion = "23.2.8568313"
//        ndkVersion = "21.4.7075529"

        externalNativeBuild {
            cmake {
                cppFlags.add("-fno-rtti")
            }
        }
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    externalNativeBuild {
        cmake {
            path("src/main/cpp/CMakeLists.txt")
            version = "3.22.1"
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
    kotlinOptions {
        jvmTarget = "1.8"
    }
}