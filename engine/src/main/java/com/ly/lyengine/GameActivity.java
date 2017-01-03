package com.ly.lyengine;

import android.app.Activity;

public class GameActivity extends Activity {
    static {
        System.loadLibrary("LYEngine");
    }

    public native void test();

    public native String getString();

}
