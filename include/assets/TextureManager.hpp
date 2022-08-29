#pragma once

#include <string>
#include "SFML/Graphics/Texture.hpp"
#include "assets/BaseAssetManager.hpp"


class TextureManager : public BaseAssetManager<TextureManager, sf::Texture> {
	friend BaseAssetManager<TextureManager, sf::Texture>;

	Result load(std::shared_ptr<sf::Texture>& asset, const std::string_view path) {
		asset = std::make_shared<sf::Texture>();

		return asset->loadFromFile(std::string{ ASSETS_PATH }.append(path)) ? SUCCESS : FAILURE;
	}
};
