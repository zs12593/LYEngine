package com.ly.lyengine;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends GameActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        TextView tv = new TextView(this);
        setContentView(tv);
        tv.setTextSize(25);

        tv.setText(getString());
    }
}
