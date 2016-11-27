//
// Created by Minsik on 2016-11-27.
//

#ifndef OPENSL_LOG_HPP
#define OPENSL_LOG_HPP

#include <iostream>
#include <android/log.h>

namespace Log {
    void info(const char *Message);

    void debug(const char *Message);

    void error(const char *Message);
}
#endif //OPENSL_LOG_HPP
