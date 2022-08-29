#pragma once

#include <string>
#include "SFML/Graphics/Font.hpp"
#include "assets/AssetManager.hpp"
#include "utilities/utilities.hpp"


class FontManager : public AssetManager<FontManager, sf::Font> {
	friend AssetManager<FontManager, sf::Font>;
	bool load(std::shared_ptr<sf::Font> font, const std::string& path) const {
		return font->loadFromFile(std::string{ utils::ASSETS_PATH } + "fonts/" + path);
	}
};
