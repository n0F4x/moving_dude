#pragma once

#include <string_view>
#include <unordered_map>
#include <memory>
#include <mutex>
#include "utils/helpers/CRTP.hpp"
#include "utils/types/Result.hpp"

#include <iostream>


constexpr std::string_view ASSETS_PATH{ "../../../res/assets/" };


template<typename Derived, typename AssetType>
class BaseAssetManager : public CRTP<Derived, BaseAssetManager, AssetType> {
	friend Derived;
	BaseAssetManager() = default;

public:
	Result get(std::shared_ptr<AssetType>& asset, const std::string_view path) {
		std::lock_guard lock{ _mutex };

		auto& ref_asset= _assets[hash(path)];

		if (asset = ref_asset.lock()) {
			return SUCCESS;
		}

		if (auto res = this->derived().load(asset, path); res != SUCCESS) {
			return res;
		}

		ref_asset = asset;

		return SUCCESS;
	}

private:
	unsigned long hash(const std::string_view sv) const { return hash_djb2a(sv); }

	///////////////
	// Variables //
	///////////////
	std::mutex _mutex;
	std::unordered_map<unsigned long, std::weak_ptr<AssetType>> _assets;
};
