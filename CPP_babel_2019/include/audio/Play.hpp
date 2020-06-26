#pragma once

#include <portaudio.h>
#include <mutex>
#include "IAudio.hpp"
                                                      
class Play : public IAudio {
public:
        Play();
        ~Play() override;                                                              
        static int PlayCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData);
        bool start() override;
        bool stop() override;
        sound_protocol_t getSound() const override;
        void setSound(const sound_protocol_t &sound) override;

private:
        PaStream *_stream;
        PaStreamParameters _parameters;
        PaError _error;
        std::vector<sound_protocol_t> _sounds;
        mutable std::mutex _lock;
};