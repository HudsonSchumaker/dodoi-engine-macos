/**
* @file Hardware.h
* @author Hudson Schumaker
* @brief Defines the Hardware class.
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
#include "../Defs.h"

/**
* @class Hardware
* @brief Handle hardware interations.
*/
class Hardware final {
public:
	enum class JoyPadTypes {
		ONE, PS4, SWITCH, PS5, UNKNOWN,
	};

	enum class JoyPadButtons {
		A, B, X, Y, L, R,
	};

	std::map<Hardware::JoyPadTypes, std::map<Hardware::JoyPadButtons, std::string>> joypads;

	Hardware() {
		joypads[JoyPadTypes::ONE] = {
			{ JoyPadButtons::A, "axb" },
			{ JoyPadButtons::B, "bxb" },
			{ JoyPadButtons::X, "xxb" },
			{ JoyPadButtons::Y, "yxb" },
			{ JoyPadButtons::L, "lbxb" },
			{ JoyPadButtons::R, "rbxb" }
		};

		joypads[JoyPadTypes::PS4] = {
			{ JoyPadButtons::A, "crosspsx" },
			{ JoyPadButtons::B, "circlepsx" },
			{ JoyPadButtons::X, "squarepsx" },
			{ JoyPadButtons::Y, "trianglepsx" },
			{ JoyPadButtons::L, "l1psx" },
			{ JoyPadButtons::R, "r1psx" },
		};

		joypads[JoyPadTypes::PS5] = {
			{ JoyPadButtons::A, "crosspsx" },
			{ JoyPadButtons::B, "circlepsx" },
			{ JoyPadButtons::X, "squarepsx" },
			{ JoyPadButtons::Y, "trianglepsx" },
			{ JoyPadButtons::L, "l1psx" },
			{ JoyPadButtons::R, "r1psx" },
		};

		joypads[JoyPadTypes::SWITCH] = {
			{ JoyPadButtons::A, "ans" },
			{ JoyPadButtons::B, "bns" },
			{ JoyPadButtons::X, "xns" },
			{ JoyPadButtons::Y, "yns" },
			{ JoyPadButtons::L, "lns" },
			{ JoyPadButtons::R, "rns" },
		};

		joypads[JoyPadTypes::UNKNOWN] = {}; // Empty vector for unknown type
	}
	~Hardware() {}

	static int getCpuCount() {
		return std::thread::hardware_concurrency();
	}

	static int getThreadNumber(int size) {
		int cpuCount = getCpuCount();
		if (size < 1001) { return 1; }
		if (size < 2001) { return std::min(2, cpuCount); }
		if (size < 3001) { return std::min(3, cpuCount); }
		if (size < 4001) { return std::min(4, cpuCount); }
		if (size < 5001) { return std::min(5, cpuCount); }
		if (size < 6001) { return std::min(6, cpuCount); }
		if (size < 7001) { return std::min(7, cpuCount); }
		if (size < 8001) { return std::min(8, cpuCount); }
		if (size < 9001) { return std::min(9, cpuCount); }
		if (size < 10001) { return std::min(10, cpuCount); }
		return cpuCount;
 	}
};
