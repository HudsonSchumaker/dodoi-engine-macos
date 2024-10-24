/**
* @file Playground.cpp
* @author Hudson Schumaker
* @brief Implements the Playground class.
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
#include "Playground.h"
#include "../engine/gfx/Box.h"
#include "../engine/gfx/Circle.h"
#include "../engine/gfx/Sprite.h"
#include "../engine/ecs/EntityManager.h"
#include "../engine/ecs/component/Waypoint.h"
#include "../engine/ecs/component/RigidBody.h"
#include "../engine/ecs/component/Clickable.h"
#include "../engine/ecs/component/BoxCollider.h"

Playground::Playground() : Scene() {
	renderSystem = new RenderSystem();
	renderTextSystem = new RenderTextSystem();
	inputSystem = new InputSystem();
	guiUpdateSystem = new GuiUpdateSystem();
}

Playground::~Playground() {
	unload();
}

void Playground::load() {
	nextScene = "0";
	auto entity = EntityManager::getInstance()->createEntity(450.0f, 450.0f);
	entity->tags.first = Tag::UI;

	auto sprite = entity->addComponent(new Sprite("avatarShadow"));

	auto box = entity->addComponent(new BoxCollider(50, 50));
	auto clickable = entity->addComponent(new Clickable([this](unsigned long entityID, int button) {
		nextScene = "1";
		isRunning = false;
	}));

	isRunning = true;
}

short Playground::run() {
	while (isRunning) {
		input();
		update();
		render();
	}
	return exit;
}

void Playground::input() {

	inputSystem->update();

	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		case SDL_QUIT:
			isRunning = false;
			exit = 1; //TODO: Change to an enum
			break;
		}
	}
}

void Playground::update() {
	//float dt = calculateDeltaTime();
	
}

void Playground::render() {
	beginRender();
	{
		renderSystem->update(&camera);
		renderTextSystem->update(&camera);

	}
	endRender();
}

void Playground::unload() {
	isLoaded = false;
	//SDL_DestroyTexture(logoTexture);
}
