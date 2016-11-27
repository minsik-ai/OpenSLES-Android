//
// Created by Minsik on 2016-11-28.
//

#include <stdio.h>
#include "WavManipulator.hpp"
#include "Log.hpp"

WAV::WAV(const char* path) : mPath(path){
    int headerSize = sizeof(wav_hdr);
    int readSize;
    int fileLength = 0;

    FILE* wavFile = fopen(path, "r");
    if(wavFile == nullptr) goto ERROR;

    readSize = fread(&mWavHeader, 1, headerSize, wavFile);
    if(readSize <= 0) goto ERROR;

    readSize = fread(&mData, 1, mWavHeader.ChunkSize, wavFile);
    if(readSize <= 0) goto ERROR;

    return;

ERROR:
    Log::error("Wav Read Fail");
    //TODO : Throw Exception
}

wav_hdr WAV::getHeader() { return mWavHeader; }

float* WAV::getData() { return mData; }