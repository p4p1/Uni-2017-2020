#pragma once

#define FRAMES_PER_BUFFER (512)
#define NUM_SECONDS     (1)
#define NUM_CHANNELS    (2)
#define PA_SAMPLE_TYPE  paFloat32
typedef float SAMPLE;
#define SAMPLE_SILENCE  (0.0f)
#define SAMPLE_RAT (41000)

typedef struct
{
    int frameIndex;
    int maxFrameIndex;
    SAMPLE recordedSamples[SAMPLE_RAT];
}
paTestData;