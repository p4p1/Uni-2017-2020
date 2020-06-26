#include "Opus.hpp"
#include "audio.hpp"
#include <stdlib.h>
#include <iostream>

Opus::Opus()
{
    int error;

    encoder = opus_encoder_create((opus_int32)48000, 2, OPUS_APPLICATION_AUDIO, &error);
    decoder = opus_decoder_create((opus_int32)48000, 2, &error);
}

Opus::~Opus()
{
    opus_encoder_destroy(encoder);
    opus_decoder_destroy(decoder);
}

unsigned char *Opus::encode(paTestData record)
{
    length = opus_encode_float(encoder, record.recordedSamples, 960, _encoded, SAMPLE_RATE);
    std::cout << length << std::endl;
    return (_encoded);
}

paTestData Opus::decode(unsigned char *record)
{
    float getor[SAMPLE_RATE];
    paTestData decoded;
    decoded.maxFrameIndex =  NUM_SECONDS * SAMPLE_RATE;
    decoded.frameIndex = 0;
    //decoded.recordedSamples = (SAMPLE *) malloc(sizeof(SAMPLE) * SAMPLE_RATE);
    int err;

    std::cout << "length:" << length << std::endl;
    
    err = opus_decode_float(decoder, record, length, getor, 960, 0);
    std::cout << "got getor:" << SAMPLE_RATE << std::endl;
    for (int i = 0; i < SAMPLE_RATE; i++) {
        decoded.recordedSamples[i] = getor[i];
    }
    return (decoded);
}