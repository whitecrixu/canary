/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019–present OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#pragma once

#include "map/map.hpp"

class IOMapSerialize {
public:
	static void loadHouseItems(Map* map);
	static bool saveHouseItems();
	static bool loadHouseInfo();
	static bool saveHouseInfo();

private:
	static bool SaveHouseInfoGuard();
	static bool SaveHouseItemsGuard();
	static void saveItem(PropWriteStream &stream, const std::shared_ptr<Item> &item);
	static void saveTile(PropWriteStream &stream, const std::shared_ptr<Tile> &tile);

	static bool loadContainer(PropStream &propStream, const std::shared_ptr<Container> &container);
	static bool loadItem(PropStream &propStream, const std::shared_ptr<Cylinder> &parent, bool isHouseItem = false);

	// Defined in iomapserialize.cpp: MinGW does not COMDAT-fold the TLS init
	// function of an inline thread_local, so an in-header definition multiply-
	// defines across unity translation units. A single out-of-line definition
	// is correct on every compiler.
	static thread_local std::vector<std::shared_ptr<BedItem>> bedsToCheck;
};
