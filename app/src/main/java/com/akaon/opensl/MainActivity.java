package com.akaon.opensl;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        SoundNDKInterface.getInstance().startSoundService();
    }

    @Override
    protected void onDestroy() {
        SoundNDKInterface.getInstance().stopSoundService();
    }
}
