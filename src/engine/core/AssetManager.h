/**
* @file AssetManager.h
* @author Hudson Schumaker
* @brief Defines the AssetManager class.
* @version 1.0.0
*
* Dodoi Engine is a game engine developed by Dodoi-Lab.
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
* @class AssetManager
* @brief The AssetManager class encapsulates the functionality of managing game assets.
*
* This class is responsible for loading, adding, retrieving, and clearing game assets.
*/
class AssetManager final {
private:
    using sound_t   = std::map<std::string, Mix_Chunk*>;
    using texture_t = std::map<std::string, std::pair<short, SDL_Texture*>>;
   
    inline static AssetManager* instance = nullptr;
    sound_t sounds;
    texture_t textures;
    
    AssetManager() = default;

public:
    ~AssetManager();

    /**
    * @brief Gets the singleton instance of the AssetManager.
    *
    * @return A pointer to the AssetManager instance.
    */
    static AssetManager* getInstance();

    /**
    * @brief Loads the assets.
    */
    void load();

    void addSound(const std::string& name, const std::string& filePath);
    void addTexture(const std::string& name, const short value, const std::string& filePath);
    
    Mix_Chunk* getSound(const std::string& name);
    SDL_Texture* getTexture(const std::string& name);
    
    int soundCount() const;
    int textureCount() const;

    /**
    * @brief Clears the assets.
    */
    void clearAssets();
};
