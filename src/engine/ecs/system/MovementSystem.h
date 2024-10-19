#pragma once
#include "System.h"

class MovementSystem final : public System {
public:
	MovementSystem() = default;
	~MovementSystem() = default;

	void update(float dt);
};
