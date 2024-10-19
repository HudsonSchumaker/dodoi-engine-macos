/**
* @file Radar.h
* @author Hudson Schumaker
* @brief Defines the Radar class.
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
#include "../TLG.h"
#include "../../math/Vec2.h"

class Radar final : public Component {
public:
    short r = 2; // radius
    Tag tag = Tag::ENEMY;
    Vec2 offset;

    Radar(short radius) : r(radius) {}
    Radar(short radius, Tag tag) : r(radius), tag(tag) {}
    Radar(short radius, Vec2 offset) : r(radius), offset(offset) {}
    Radar(short radius, Tag tag, Vec2 offset) : r(radius), tag(tag), offset(offset) {}
    
    ~Radar() = default;
};
