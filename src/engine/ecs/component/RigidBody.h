/**
* @file RigidBody.h
* @author Hudson Schumaker
* @brief Defines the RigidBody class.
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
#include "Component.h"
#include "../../math/Vec2.h"

class RigidBody final : public Component {
private:
    void init() {
        if (mass != 0.0f) {
            invMass = 1.0f / mass;
        }
        else {
            invMass = 0.0f;
        }
    }

public:
    Vec2 velocity;
    short dirX = 1;
    short dirY = 0;
    float mass = 1.0f;
    float invMass = 1.0f;
    bool isMoving = true;

    RigidBody() {}
    RigidBody(float x, float y) {
        this->velocity.x = x;
        this->velocity.y = y;
    }

    RigidBody(float x, float y, float mass) {
        this->velocity.x = x;
        this->velocity.y = y;
        this->mass = mass;
        init();
    }

    RigidBody(Vec2 velocity) {
        this->velocity = velocity;
        init();
    }

    RigidBody(Vec2 velocity, float mass) {
        this->velocity = velocity;
        this->mass = mass;
        init();
    }

    ~RigidBody() {}
};
