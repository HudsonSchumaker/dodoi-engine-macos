#include "Sfx.h"

Sfx::~Sfx() {
	Mix_FreeMusic(music);
	Mix_HaltChannel(-1);
	Mix_CloseAudio();
	Mix_Quit();
}

Sfx* Sfx::getInstance() {
	if (instance == nullptr) {
		instance = new Sfx();
	}

	return instance;
}

void Sfx::setSfxContext() {
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 8, 1024) < 0) {
		std::cerr << "Error: " << Mix_GetError() << std::endl;
		return;
	}
}

Mix_Chunk* Sfx::loadSound(const std::string& filePath) {
	return Mix_LoadWAV(filePath.c_str());
}

int Sfx::playSound(Mix_Chunk* sound) {
	return playSound(sound, 0);
}

int Sfx::playSound(Mix_Chunk* sound, int loop) {
	return Mix_PlayChannel(-1, sound, loop);
}

void Sfx::stopSound(int channel) {
	Mix_HaltChannel(channel);
}

void Sfx::stopSound(int channel, int delay) {
	Mix_FadeOutChannel(channel, delay);
}

void Sfx::pauseSound(int channel) {
	Mix_Pause(channel);
}

void Sfx::unPauseSound(int channel) {
	Mix_Resume(channel);
}

void Sfx::playMusic(const std::string& filePath, int loop) {
	auto res = std::async(std::launch::async, [&]() {
		music = Mix_LoadMUS(filePath.c_str());
		Mix_PlayMusic(music, loop);
	});
}

void Sfx::stopMusic() {
	Mix_HaltMusic();
}

void Sfx::stopMusic(int delay) {
	Mix_FadeOutMusic(delay);
}

void Sfx::pauseMusic() {
	Mix_PauseMusic();
}

void Sfx::unPauseMusic() {
	Mix_ResumeMusic();
}
