/**
* @file Playground.h
* @author Hudson Schumaker
* @brief Defines the Playground class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#pragma once
#include "../engine/core/Scene.h"
#include "../engine/core/ParallaxVertical.h"
#include "../engine/ecs/system/WaypointNavigationSystem.h"
#include "../engine/gfx/Box.h"
#include "../engine/gfx/Circle.h"
#include "../engine/gfx/Sprite.h"
#include "../engine/ecs/EntityManager.h"
#include "../engine/ecs/component/Waypoint.h"
#include "../engine/ecs/component/RigidBody.h"
#include "../engine/ecs/system/RenderSystem.h"
#include "../engine/ecs/component/TextLabel.h"
#include "../engine/ecs/system/PrimitiveRenderSystem.h"
#include "../engine/ecs/system/RenderTextSystem.h"
#include "../engine/ecs/system/WaypointNavigationSystem.h"
#include "../engine/ecs/system/InputSystem.h"
#include "../engine/ecs/system/GuiUpdateSystem.h"

/**
* @class Playground
* @brief The Playground class.
*/
class Playground final : public Scene {
private:
	RenderSystem* renderSystem = nullptr;
	RenderTextSystem* renderTextSystem = nullptr;
	InputSystem* inputSystem = nullptr;
	GuiUpdateSystem* guiUpdateSystem = nullptr;

	void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;

public:
	Playground();
	~Playground();

	short run() override;
};
