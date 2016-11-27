//
// Created by Minsik on 2016-11-27.
//

#ifndef OPENSL_SOUNDSERVICE_HPP
#define OPENSL_SOUNDSERVICE_HPP

#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
#include <SLES/OpenSLES_AndroidConfiguration.h>

class SoundService {
public:
    SoundService();

    bool start();
    void stop();

    bool playAudio(const char* path);
    void stopAudio();

private:
    SLObjectItf mEngineObj; SLEngineItf mEngine;
    SLObjectItf mOutputMixObj;

    SLObjectItf mAudioPlayerObj; SLPlayItf mAudioPlayer;
    SLSeekItf mAudioPlayerSeek;
};
#endif //OPENSL_SOUNDSERVICE_HPP
