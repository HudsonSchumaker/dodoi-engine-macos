#pragma once
#include "Animation.h"
#include "../ecs/component/Component.h"

class AnimationController final : public Component {
public:
	short actualAnimation = -1;
	std::string actualAnimationName;
	std::vector<Animation*> animations;
	std::map<std::string, short> animationNames;

	AnimationController() = default;
	~AnimationController() = default;

	void createAnimation(std::string name, const std::string& assetName, short numFrames, int frameSpeedRate);
	void createAnimation(std::string name, const std::string& assetName, short numFrames, int frameSpeedRate, bool isLoop);
	void addAnimation(std::string name, Animation* animation);
	void playAnimation();
	void playAnimation(std::string name);
	void playAnimation(short index);
	void stopAnimation();
	Animation* getActive();
	std::string getActiveName();
};
