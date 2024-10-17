#include "Gfx.h"
#include "Animation.h"
#include "../core/AssetManager.h"

Animation::Animation(const std::string& name, short numFrames, int frameSpeedRate, bool isLoop) {
	this->numFrames = numFrames;
	this->frameSpeedRate = frameSpeedRate;
	this->isLoop = isLoop;

	texture = AssetManager::getInstance()->getTexture(name);
	bounds = Gfx::getInstance()->getTextureSize(texture);
	bounds.w = bounds.w / numFrames;
	startTime = SDL_GetTicks();
}

void Animation::play() {
	isPlaying = true;
}

void Animation::stop() {
	isPlaying = false;
}

Dimension<int> Animation::getSize() const {
	return Dimension(bounds.w, bounds.h);
}
