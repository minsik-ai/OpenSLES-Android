//
// Created by Minsik on 2016-11-27.
//

#include "Log.hpp"

#define TAG "NDK"

void Log::info(const char *Message) { __android_log_print(ANDROID_LOG_INFO, TAG, Message); }
void Log::debug(const char *Message) { __android_log_print(ANDROID_LOG_DEBUG, TAG, Message); }
void Log::error(const char *Message) { __android_log_print(ANDROID_LOG_ERROR, TAG, Message); }