package com.akaon.opensl;

import android.util.Log;

/**
 * Created by Minsik on 2016-11-27.
 */

public class SoundNDKInterface {

    private static String TAG = SoundNDKInterface.class.getSimpleName();

    private static SoundNDKInterface instance = new SoundNDKInterface();

    private SoundNDKInterface() {
        Log.i(TAG, "Eager Init of SoundNDKInterface");
        System.loadLibrary("SoundInterface-lib");
    }

    public static SoundNDKInterface getInstance() {
        return instance;
    }

    native boolean startSoundService();
    native void stopSoundService();
    native boolean startAudioPlay(String path);
    native void stopAudioPlay();
}
