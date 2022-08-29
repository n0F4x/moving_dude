#pragma once

#include <array>
#include <memory>
#include <string>
#include <format>
#include "SFML/Graphics/Texture.hpp"
#include "utils/algorithms/enumerate.hpp"
#include "utils/types/Result.hpp"
#include "AssetManager.hpp"


template<size_t N>
class SpriteSheet {
public:
	constexpr size_t size() { return N; }
	const std::shared_ptr<sf::Texture> operator[](size_t idx) const { return _textures[idx]; }
	std::shared_ptr<sf::Texture> operator[](size_t idx) { return _textures[idx]; }

	Result load(AssetManager& assets, const std::array<std::string, N>& paths) {
		for (auto [i, path] : enumerate(paths)) {
			if (auto result = assets.textures().get(_textures[i], path); result.failed()) {
				return result;
			}
		}
		return SUCCESS;
	}

private:
	std::array<std::shared_ptr<sf::Texture>, N> _textures;
};


template<size_t N>
constexpr std::array<std::string, N> generate_spritesheet_paths(const std::string_view base_path, const std::string_view extension = ".png") {
	std::array<std::string, N> result;
	for (size_t i = 0; i < N; i++) {
		result[i] = std::format("{} ({}){}", base_path, std::to_string(i+1), extension);
	}
	return result;
}
