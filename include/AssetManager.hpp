#pragma once

#include "assets/TextureManager.hpp"


class AssetManager {
public:
	TextureManager& textures() { return _textures; }

private:
	TextureManager _textures;
};
