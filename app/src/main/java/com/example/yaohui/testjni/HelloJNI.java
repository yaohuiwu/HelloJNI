package com.example.yaohui.testjni;

public class HelloJNI {

    static {
        System.loadLibrary("HelloJNI");
    }

    /**
     * Say hello by native c.
     *
     * @param yourName your name.
     * @return hello string.
     */
    public native String sayHello(String yourName);
}
