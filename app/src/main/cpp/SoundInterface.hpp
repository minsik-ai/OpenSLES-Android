//
// Created by Minsik on 2016-11-27.
//

#ifndef OPENSL_SOUNDINTERFACE_HPP
#define OPENSL_SOUNDINTERFACE_HPP

#include <jni.h>

extern "C" {
    JNIEXPORT jboolean JNICALL
    Java_com_akaon_opensl_SoundNDKInterface_startSoundService(JNIEnv *env, jobject instance);

    JNIEXPORT void JNICALL
    Java_com_akaon_opensl_SoundNDKInterface_stopSoundService(JNIEnv *env, jobject instance);
}

#endif //OPENSL_SOUNDINTERFACE_HPP
