#pragma once
#include "../ecs/Entity.h"
#include "../math/Dimension.h"
#include "../ecs/component/Component.h"

class Animation final : public Component {
public:
    Dimension<int> bounds;
    SDL_Texture* texture = nullptr;

    unsigned int startTime = 0;
    bool flip = false;
    bool isLoop = true;
    bool isFixed = false;
    bool isPlaying = true;
    short numFrames = 1;
    short currentFrame = 1;
    short skipFrameIndex = -10;
    int frameSpeedRate = 1;

    Animation(const std::string& name, short numFrames, int frameSpeedRate, bool isLoop);
    ~Animation() = default;

    void play();
    void stop();
    Dimension<int> getSize() const;
};
