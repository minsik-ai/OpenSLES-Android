//
// Created by Minsik on 2016-11-27.
//

#include "SoundInterface.hpp"
#include "SoundService.hpp"

SoundService *openSLSoundService;

extern "C" {
JNIEXPORT jboolean JNICALL
    Java_com_akaon_opensl_SoundNDKInterface_startSoundService(JNIEnv *env, jobject instance) {
        openSLSoundService = new SoundService;
        if(openSLSoundService -> start()) {
            return true;
        } else {
            return false;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_akaon_opensl_SoundNDKInterface_stopSoundService(JNIEnv *env, jobject instance) {
        openSLSoundService -> stop();
    }

    JNIEXPORT jboolean JNICALL
    Java_com_akaon_opensl_SoundNDKInterface_startAudioPlay(JNIEnv *env, jobject instance,
                                                           jstring path_) {
        const char *path = env->GetStringUTFChars(path_, 0);

        bool result = openSLSoundService -> startAudio(path);

        env->ReleaseStringUTFChars(path_, path);

        return result;
    }

    JNIEXPORT void JNICALL
    Java_com_akaon_opensl_SoundNDKInterface_stopAudioPlay(JNIEnv *env, jobject instance) {

        openSLSoundService -> stopAudio();
    }
}