#pragma once
#include <vector>

#define SAMPLE_RATE (48000)
#define CHAN_NUM   (2)
#define FRAME_PER_BUFFER (5)
#define SAMPLE_SILENCE (0.0f)

typedef struct sound_protocol_t {
        std::vector<float> buffer;
        int                size = 0;
} sound_protocol_t;

class IAudio {
public:
        virtual ~IAudio() = default;
        virtual bool start() = 0;
        virtual bool stop() = 0;
        virtual sound_protocol_t getSound() const = 0;
        virtual void setSound(const sound_protocol_t &sound) = 0;
};