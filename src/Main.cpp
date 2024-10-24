/**
* @file Main.cpp
* @author Hudson Schumaker
* @brief Defines main function.
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
#include "Main.h"
#include "game/Playground.h"
#include "game/SplashScreen.h"
#include "engine/gfx/Gfx.h"
#include "engine/sfx/Sfx.h"
#include "engine/core/AssetManager.h"
#include "engine/ecs/EntityManager.h"
#include "engine/core/SceneManager.h"

int main(int argc, char* argv[]) {
    setUp();

    SceneManager::getInstance()->addScene("SplashScreen", std::make_unique<SplashScreen>());
    SceneManager::getInstance()->addScene("Playground", std::make_unique<Playground>());
    SceneManager::getInstance()->loadSceneAsync("SplashScreen");

    quit();
    return 0;
}

void setUp() {
    Gfx::getInstance()->setGfxContext();
    Sfx::getInstance()->setSfxContext();
    AssetManager::getInstance()->load();
    EntityManager::getInstance();
}

void quit() {
    delete Gfx::getInstance();
    delete Sfx::getInstance();
    delete AssetManager::getInstance();
    delete EntityManager::getInstance();
    SDL_Quit();
}
