#pragma once

#include <opus.h>
#include "audio.hpp"
#include "ICompressor.hpp"

class Opus : public ICompressor
{
public:
    Opus();
    ~Opus();
    unsigned char *encode(paTestData record);
    paTestData decode(unsigned char *record);
private:
    OpusEncoder *encoder;
    OpusDecoder *decoder;
    int length;
    unsigned char _encoded[960];
};