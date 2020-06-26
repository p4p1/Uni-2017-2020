#include <stdexcept>
#include <vector>
#include <iostream>
#include "Record.hpp"

Record::Record(Udp *udp) : _udp(udp)
{
	_error = Pa_Initialize();
	if (_error != paNoError) {
        exit(84);
	}
	_parameters.device = Pa_GetDefaultInputDevice();
	if (_parameters.device == paNoDevice) {
        exit(84);
	}
	_parameters.channelCount = CHAN_NUM;
	_parameters.sampleFormat = paFloat32;
	_parameters.suggestedLatency = Pa_GetDeviceInfo(
	_parameters.device)->defaultHighInputLatency;
	_parameters.hostApiSpecificStreamInfo = nullptr;
	_error = Pa_OpenStream(&_stream, &_parameters, nullptr, (double)SAMPLE_RATE, FRAME_PER_BUFFER, paClipOff, RecordCallback, this);
	if (_error != paNoError) {
        exit(84);
	}
}

Record::~Record()
{
	stop();
	Pa_CloseStream(_stream);
	Pa_Terminate();
}

int Record::RecordCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
	const float *input   = reinterpret_cast<const float *>(inputBuffer);
	Record *thisRef = reinterpret_cast<Record *>(userData);
	sound_protocol_t sound   = {};

	(void)outputBuffer;
	(void)timeInfo;
	(void)statusFlags;
	(void)framesPerBuffer;
	if (inputBuffer == nullptr) {
		sound.buffer = std::vector<float>(FRAME_PER_BUFFER * CHAN_NUM, SAMPLE_SILENCE);
	} else {
		for (size_t count = 0; count < framesPerBuffer * CHAN_NUM; count++) {
			sound.buffer.push_back(*input++);
		}
	}
	sound.size = (int)sound.buffer.size();
    // udp control here
	thisRef->_udp->send(sound);
	return paContinue;
}

bool Record::start()
{
	_error = Pa_StartStream(_stream);
	return _error == paNoError;
}

bool Record::stop()
{
	_error = Pa_StopStream(_stream);
	return _error == paNoError;
}

sound_protocol_t Record::getSound() const
{
	sound_protocol_t sound;

	sound.buffer = std::vector<float>(FRAME_PER_BUFFER, SAMPLE_SILENCE);
	sound.size = (int)sound.buffer.size();
	return sound;
}

void Record::setSound(const sound_protocol_t &sound)
{
	(void)sound;
}
