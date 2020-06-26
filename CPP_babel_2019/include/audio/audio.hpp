#pragma once
#include "Aaudio.hpp"
#include "portaudio.h"

class audio : public Aaudio
{
public:
    audio();
    virtual void play(paTestData);
    virtual paTestData record();
private:
    static int playCallback(const void*, void *, unsigned long, const PaStreamCallbackTimeInfo*, PaStreamCallbackFlags, void *);
    static int recordCallback(const void*, void *, unsigned long, const PaStreamCallbackTimeInfo*, PaStreamCallbackFlags, void *);
    PaStreamParameters inputParameters;
    PaStreamParameters outputParameters;
    PaStream *stream;
    PaError err;
    paTestData data;
    int i;
    int totalFrames;
    int numSamples;
    int numBytes;
    SAMPLE max;
    SAMPLE val;
    double average;
};