#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "AssetManager.hpp"


class Services {
public:
	sf::RenderWindow& window() { return _window; }
	AssetManager& assets() { return _assets; }

private:
	sf::RenderWindow _window;
	AssetManager _assets;
};
