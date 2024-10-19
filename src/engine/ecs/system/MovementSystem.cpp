/**
* @file MovementSystem.cpp
* @author Hudson Schumaker
* @brief Implements the MovementSystem class
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
#include "MovementSystem.h"
#include "../EntityManager.h"
#include "../../core/Hardware.h"
#include "../component/Waypoint.h"
#include "../component/Transform.h"
#include "../component/RigidBody.h"

void MovementSystem::update(float dt) {
    // Get all entities with RigidBody component
    auto entities = EntityManager::getInstance()->getEntitiesWithComponent<RigidBody>();

    // Get the number of these entities
    int entitiesSize = static_cast<int>(entities.size());

    // Get the number of threads based on the number of entities
    int numThreads = Hardware::getThreadNumber(entitiesSize);

    // Calculate the size of each chunk for parallel processing
    int chunkSize = (entitiesSize + numThreads - 1) / numThreads; // Round up division

    // Vector to hold the chunks of entities
    std::vector<std::vector<Entity*>> chunks;
    chunks.reserve(numThreads); // Reserve space for the chunks

    // Divide the entities into chunks
    for (int i = 0; i < entities.size(); i += chunkSize) {
        chunks.emplace_back(entities.begin() + i, entities.begin() +
            std::min(i + chunkSize, entitiesSize));
    }

    // Vector to hold the threads
    std::vector<std::thread> threads;

    // For each chunk of entities, create a thread
    for (const auto& chunk : chunks) {
        threads.emplace_back([chunk, dt] {
            // For each entity in the chunk
            for (auto& entity : chunk) {
                // Do nothing if the entity have a Waypoint component
                if (entity->getComponent<Waypoint>()) {
					continue;
				}

                auto components = entity->getComponents<RigidBody, Transform>();
                RigidBody* rigidBody = std::get<1>(components); // Get the RigidBody component
                Transform* transform = std::get<2>(components); // Get the Transform component

                // If the entity has a RigidBody and Transform
                if (rigidBody && transform) {
                    // If the entity is not moving ignore it
                    if (!rigidBody->isMoving) { continue; }

                    // Update the position based on the velocity
                    transform->position.x += rigidBody->velocity.x * dt;
					transform->position.y += rigidBody->velocity.y * dt;
                }
            }
        });
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }
}
