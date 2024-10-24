/**
* @file InputSystem.h
* @author Hudson Schumaker
* @brief Defines the InputSystem class.
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
#include "System.h"
#include "../../core/MousePointer.h"

class InputSystem final : public System {
public:
    using KeyboardCallback = std::function<void(const Uint8*)>;
    using JoypadCallback = std::function<void(const Hardware::JoyPadTypes, const Hardware::JoyPadButtons)>;

    InputSystem();
    ~InputSystem();

    void update();

    void setKeyboardCallback(KeyboardCallback callback);
    void setJoypadCallback(JoypadCallback callback);

private:
    void handleMouseInput();
    void handleKeyboardInput();
    void handleJoypadInput();
    bool isInside(const SDL_Rect& box1, const SDL_Rect& box2) const;

    MousePointer pointer;
    KeyboardCallback keyboardCallback;
    JoypadCallback joypadCallback;
};
