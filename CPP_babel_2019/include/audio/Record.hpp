#define BABEL_Record_H

#include <portaudio.h>
#include <mutex>
#include "IAudio.hpp"
#include "Udp.hpp"
                               
class Record : public IAudio {
public:
        Record(Udp *);
        ~Record() override;
        static int RecordCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData);
        bool start() override;
        bool stop() override;
        sound_protocol_t getSound() const override;
        void setSound(const sound_protocol_t &sound) override;
private:
        PaStream *_stream = nullptr;
        PaStreamParameters _parameters;
        PaError _error;
        Udp * _udp;
};