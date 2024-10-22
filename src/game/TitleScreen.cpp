/**
* @file TitleScreen.cpp
* @author Hudson Schumaker
* @brief Implements the TitleScreen class.
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
#include "TitleScreen.h"
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

TitleScreen::TitleScreen() : Scene() {
	nav = new WaypointNavigationSystem();
}
TitleScreen::~TitleScreen() {
	unload();
}

void TitleScreen::load() {
	parallax = new ParallaxVertical("backyellow1280", "backkunai");
	nextScene = "0";
	auto entity = EntityManager::getInstance()->createEntity(450.0f, 450.0f);
	auto label = entity->addComponent(new TextLabel("pico8.ttf", true, "Dodoi-Engine", 32, Color::getWhite()));
	label->setOnScreenCenter();

	isRunning = true;
}

short TitleScreen::run() {
	while (isRunning) {
		input();
		update();
		render();
	}
	return exit;
}

void TitleScreen::input() {
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

void TitleScreen::update() {
	float dt = calculateDeltaTime();
	
	nav->update(dt);
	parallax->update();
}

void TitleScreen::render() {
	beginRender();
	{
		//parallax->render(renderer);

		//SDL_RenderCopy(renderer, logoTexture, NULL, &rect);
		PrimitiveRenderSystem render;
		render.update(&camera);

		RenderSystem renderSystem;
		renderSystem.update(&camera);

		RenderTextSystem renderTextSystem;
		renderTextSystem.update(&camera);

	}
	endRender();
}

void TitleScreen::unload() {
	isLoaded = false;
	SDL_DestroyTexture(logoTexture);
}
