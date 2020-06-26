#include <stdexcept>
#include <iostream>
#include "Play.hpp"

Play::Play()
{
	_error = Pa_Initialize();
	if (_error != paNoError) {
        exit(84);
    }
	_parameters.device = Pa_GetDefaultOutputDevice();
	if (_parameters.device == paNoDevice) {
        exit(84);
	}
	_parameters.channelCount = CHAN_NUM;
	_parameters.sampleFormat = paFloat32;
	_parameters.suggestedLatency = Pa_GetDeviceInfo(_parameters.device)->defaultHighOutputLatency;
	_parameters.hostApiSpecificStreamInfo = nullptr;
	_error = Pa_OpenStream(&_stream, nullptr, &_parameters, (double)(SAMPLE_RATE), FRAME_PER_BUFFER, paClipOff, PlayCallback, this);
	if (_error != paNoError) {
        exit(84);
	}
}

Play::~Play()
{
	Pa_CloseStream(_stream);
	Pa_Terminate();
}

int Play::PlayCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
	float *output  = reinterpret_cast<float *>(outputBuffer);
	Play  *thisRef = reinterpret_cast<Play *>(userData);
	sound_protocol_t sound;

	(void)timeInfo;
	(void)statusFlags;
	(void)inputBuffer;
	if (thisRef->_sounds.empty()) {
		for (size_t count = 0; count < framesPerBuffer * CHAN_NUM; count++) {
			output[count] = SAMPLE_SILENCE;
		}
	}
	else {
		thisRef->_lock.lock();
		sound = thisRef->_sounds.front();
		for (size_t count = 0; count < framesPerBuffer * CHAN_NUM; count++) {
			output[count] = (count >= sound.buffer.size() ? SAMPLE_SILENCE : sound.buffer[count]);
		}
		thisRef->_sounds.erase(thisRef->_sounds.begin());
		thisRef->_lock.unlock();
	}
	return paContinue;
}

bool Play::start()
{
	_error = Pa_StartStream(_stream);
	return _error == paNoError;
}

bool Play::stop()
{
	_error = Pa_StopStream(_stream);
	_lock.lock();
	_sounds.clear();
	_lock.unlock();
	return _error == paNoError;
}

sound_protocol_t Play::getSound() const
{
	sound_protocol_t sound;
    sound.buffer = std::vector<float>(0);
    sound.size = 0;

	return sound;
}

void Play::setSound(const sound_protocol_t &sound)
{
	if (sound.size == 0)
		return;
	_lock.lock();
	_sounds.emplace_back(sound);
	_lock.unlock();
}
