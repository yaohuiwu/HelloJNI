What is HelloJNI
==================

HelloJNI is a simple android project to demonstrate how to use JNI in android platform. 

## requirements

+ os
    + Ubuntu 14.04 LTS

+ jdk
    + 1.7

+ gradle
    + 2.9

+ android sdk

    + Android SDK Tool 24.4.1
    + Android SDK Platform-tools 23.0.1
    + Android SDK Build-tools 23.0.2
    + SDK Platform 4.3.1 (API 18)
    + Android Support Respository 25
    + Android Support Library 23.1.1

+ android ndk

    + r10

+ android stdio
    
    + 141.2422023
    
## how to build

1. build libHelloJNI.so manually.

        cd app/src/main/jni
        /path/to/ndk-build

2. build by gradle.

        gradle build
        

## how to create jni header file

1. compile java source file that contain native methods.

        cd app/src/main/java/com/example/yaohui/testjni
        javac HelloJNI.java

2. create jni header file.

        cd app/src/main/java
        javah -classpath .  -d /path/to/app/src/main/jni -jni com.example.yaohui.testjni.HelloJNI

## some note in developing native code

+ The method signature in jni header ignore method parameters, which should not be ignore in implementation.
        

    
