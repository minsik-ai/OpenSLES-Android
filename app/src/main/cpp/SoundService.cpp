//
// Created by Minsik on 2016-11-27.
//

#include "SoundService.hpp"
#include "Log.hpp"
#include "WavManipulator.hpp"

SoundService::SoundService() : mEngineObj(NULL), mEngine(NULL), mOutputMixObj(NULL),
                               mAudioPlayerObj(NULL), mAudioPlayer(NULL), mAudioPlayerSeek(NULL) {
    Log::info("SoundService Created");
}

bool SoundService::start() {
    Log::info("SoundService Started");

    SLresult mResult;
    const SLint32 mEngineMixIIDCount = 1;
    const SLInterfaceID mEngineMixIIDs[] = {SL_IID_ENGINE};
    const SLboolean mEngineMixReqs[] = {SL_BOOLEAN_TRUE};
    const SLuint32 mOutputMixIIDCount = 0;
    const SLInterfaceID mOutputMixIIDs[] = {};
    const SLboolean mOutputMixReqs[] = {};

    // Create/Initialize OpenSL Engine Object
    mResult = slCreateEngine(&mEngineObj, 0, NULL, mEngineMixIIDCount,
                             mEngineMixIIDs, mEngineMixReqs);
    if (mResult != SL_RESULT_SUCCESS) goto ERROR;

    // Realize OpenSL Engine Object
    mResult = (*mEngineObj) -> Realize(mEngineObj, SL_BOOLEAN_FALSE);
    if (mResult != SL_RESULT_SUCCESS) goto ERROR;

    // Get Engine Interface from OpenSL Engine Object
    mResult = (*mEngineObj) -> GetInterface(mEngineObj, SL_IID_ENGINE, &mEngine);
    if (mResult != SL_RESULT_SUCCESS) goto ERROR;

    // Create/Initialize Audio Output Mix
    mResult = (*mEngine) -> CreateOutputMix(mEngine, &mOutputMixObj, mOutputMixIIDCount,
                                            mOutputMixIIDs,mOutputMixReqs);
    // Realize Audio Output Mix Object
    mResult = (*mOutputMixObj) -> Realize(mOutputMixObj, SL_BOOLEAN_FALSE);

    return true;

    ERROR:
    Log::error("Error while starting SoundService");
    stop();
    return false;
}

void SoundService::stop() {
    stopAudio();

    if(mOutputMixObj != NULL) {
        (*mOutputMixObj) -> Destroy(mOutputMixObj);
        mOutputMixObj = NULL;
    }

    if(mEngineObj != NULL) {
        (*mEngineObj) -> Destroy(mEngineObj);
        mEngineObj = NULL;
    }
}

bool SoundService::playAudio(const char *path) {
    SLresult mResult;

    //TODO : Look at /native-audio example in Android NDK
    //TODO : Search "Play Audio OpenSL" in Google

    WAV mWav(path);
    wav_hdr mWavHeader = mWav.getHeader();

    // Setting up sound audio source
    SLDataLocator_AndroidSimpleBufferQueue lDataLocatorIn;
    lDataLocatorIn.locatorType = SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE;
    lDataLocatorIn.numBuffers = 1;

    SLDataFormat_PCM lDataFormat;
    lDataFormat.formatType = SL_DATAFORMAT_PCM;
    lDataFormat.numChannels = mWavHeader.NumOfChan;     // etc. 1,2
    lDataFormat.samplesPerSec = mWavHeader.SamplesPerSec * 1000;   // etc. 44100 * 1000
    lDataFormat.bitsPerSample = mWavHeader.bitsPerSample;   // etc. 16
    lDataFormat.containerSize = mWavHeader.ChunkSize;
    lDataFormat.channelMask = SL_SPEAKER_FRONT_CENTER;
    lDataFormat.endianness = SL_BYTEORDER_LITTLEENDIAN;

    SLDataSource lDataSource;
    lDataSource.pLocator = &lDataLocatorIn;
    lDataSource.pFormat = &lDataFormat;

    SLDataLocator_OutputMix lDataLocatorOut;
    lDataLocatorOut.locatorType = SL_DATALOCATOR_OUTPUTMIX;
    lDataLocatorOut.outputMix = mOutputMixObj;

    SLDataSink lDataSink;
    lDataSink.pLocator = &lDataLocatorOut;
    lDataSink.pFormat = NULL;
}