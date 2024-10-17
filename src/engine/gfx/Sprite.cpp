/*
	2D Dodoi Engine
	Dodoi Lab
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Sprite.h"
#include "../core/AssetManager.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/Transform.h"

Sprite::Sprite(const std::string& name) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = (float)srcRect.w;
	h = (float)srcRect.h;
}

Sprite::Sprite(const std::string& name, bool isFixed) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = (float)srcRect.w;
	h = (float)srcRect.h;
	this->isFixed = isFixed;
}

Sprite::Sprite(const std::string& name, int srcX, int srcY, int w, int h) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = {
		srcX,
		srcY,
		w,
		h
	};

	this->w = (float)srcRect.w;
	this->h = (float)srcRect.h;
}

Sprite::Sprite(const std::string& name, int srcX, int srcY, int w, int h, bool isFixed) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = {
		srcX,
		srcY,
		w,
		h
	};

	this->w = (float)srcRect.w;
	this->h = (float)srcRect.h;
	this->isFixed = isFixed;
}

void Sprite::setOnCenter() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		auto bounds = Gfx::getInstance()->getTextureSize(texture);

		transform->position.x = (float)(Defs::SCREEN_H_WIDTH - (bounds.w / 2));
		transform->position.y = (float)(Defs::SCREEN_H_HEIGHT - (bounds.h / 2));
	}
}

void Sprite::setOnCenterX() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		auto bounds = Gfx::getInstance()->getTextureSize(texture);
		transform->position.x = (float)(Defs::SCREEN_H_WIDTH - (bounds.w / 2));
	}
}

void Sprite::setOnCenterY() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		auto bounds = Gfx::getInstance()->getTextureSize(texture);
		transform->position.y = (float)(Defs::SCREEN_H_HEIGHT - (bounds.h / 2));
	}
}

void Sprite::setW(float w) {
	this->w = w;
	srcRect.w = (int)w;
}

void Sprite::setH(float h) {
	this->h = h;
	srcRect.h = (int)h;
}

Dimension<int> Sprite::getSize() const {
	return Dimension((int)w, (int)h);
}
