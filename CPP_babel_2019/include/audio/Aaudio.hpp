#pragma once

#include "portaudio.h"
#include "paTestData.hpp"


class Aaudio
{
public:
    virtual ~Aaudio() {};
    virtual void play(paTestData) = 0;
    virtual paTestData record() = 0;
private:
};