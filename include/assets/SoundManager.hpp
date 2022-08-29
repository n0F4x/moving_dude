#pragma once

#include <string>
#include "SFML/Audio/SoundBuffer.hpp"
#include "assets/AssetManager.hpp"
#include "utilities/utilities.hpp"


class SoundManager : public AssetManager<SoundManager, sf::SoundBuffer> {
	friend AssetManager<SoundManager, sf::SoundBuffer>;
	bool load(std::shared_ptr<sf::SoundBuffer> sound, const std::string& path) const {
		return sound->loadFromFile(std::string{ utils::ASSETS_PATH } + "sounds/" + path);
	}
};
