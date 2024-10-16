#pragma once
#include "../ecs/Entity.h"
#include "../math/Dimension.h"
#include "../ecs/component/Component.h"

class Sprite final : public Component {
public:
	float w = 0.0f;
	float h = 0.0f;
	SDL_Rect srcRect;
	bool flipX = false;
	bool flipY = false;
	bool isFixed = false;
	SDL_Texture* texture = nullptr;

	Sprite(const std::string& name);
	Sprite(const std::string& name, bool isFixed);
	Sprite(const std::string& name, int srcX, int srcY, int w, int h);
	Sprite(const std::string& name, int srcX, int srcY, int w, int h, bool isFixed);
	~Sprite() = default;

	void setOnCenter();
	void setOnCenterX();
	void setOnCenterY();
	Dimension<int> getSize() const;
	void setW(float w); // to update the srcRect also.
	void setH(float h); // to update the srcRect also.
};
