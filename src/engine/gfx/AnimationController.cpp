#include "AnimationController.h"

void AnimationController::createAnimation(std::string name, const std::string& assetName, short numFrames, int frameSpeedRate) {
	createAnimation(name, assetName, numFrames, frameSpeedRate, true);
}

void AnimationController::createAnimation(std::string name, const std::string& assetName, short numFrames, int frameSpeedRate, bool isLoop) {
	Animation* animation = new Animation(assetName, numFrames, frameSpeedRate, isLoop);
	addAnimation(name, animation);
}

void AnimationController::addAnimation(std::string name, Animation* animation) {
	animations.push_back(animation);
	int index = int(animations.size() - 1);
	animationNames[name] = index;
	actualAnimationName = name;
}

void AnimationController::playAnimation() {
	if (actualAnimation > -1) {
		playAnimation(actualAnimation);
	}
}

void AnimationController::playAnimation(std::string name) {
	if (animationNames.count(name) > 0) {
		actualAnimationName = name;
		playAnimation(animationNames[name]);
	}
}

void AnimationController::playAnimation(short index) {
	if (index < animations.size()) {
		actualAnimation = index;
		animations[actualAnimation]->play();
	}
}

void AnimationController::stopAnimation() {
	animations[actualAnimation]->stop();
}

Animation* AnimationController::getActive() {
	return animations[actualAnimation];
}

std::string AnimationController::getActiveName() {
	return actualAnimationName;
}
