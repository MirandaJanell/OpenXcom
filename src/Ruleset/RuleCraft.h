/*
 * Copyright 2010-2012 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OPENXCOM_RULECRAFT_H
#define OPENXCOM_RULECRAFT_H

#include <vector>
#include <string>
#include <yaml-cpp/yaml.h>

namespace OpenXcom
{

class RuleTerrain;
class Ruleset;

/**
 * Represents a specific type of craft.
 * Contains constant info about a craft like
 * costs, speed, capacities, consumptions, etc.
 * @sa Craft
 */
class RuleCraft
{
private:
	std::string _type;
	int _sprite;
	int _fuelMax, _damageMax, _speedMax, _accel, _weapons, _soldiers, _vehicles, _costBuy;
	std::string _refuelItem;
	int _repairRate, _refuelRate, _radarRange, _transferTime, _score;
	// battlescape:
	RuleTerrain *_battlescapeTerrainData;
	bool _spacecraft;
public:
	/// Creates a blank craft ruleset.
	RuleCraft(const std::string &type);
	/// Cleans up the craft ruleset.
	~RuleCraft();
	/// Loads craft data from YAML.
	void load(const YAML::Node& node, Ruleset *ruleset);
	/// Saves the craft data to YAML.
	void save(YAML::Emitter& out) const;
	/// Gets the craft's type.
	std::string getType() const;
	/// Gets the craft's sprite.
	int getSprite() const;
	/// Gets the craft's maximum fuel.
	int getMaxFuel() const;
	/// Gets the craft's maximum damage.
	int getMaxDamage() const;
	/// Gets the craft's maximum speed.
	int getMaxSpeed() const;
	/// Gets the craft's acceleration.
	int getAcceleration() const;
	/// Gets the craft's weapon capacity.
	int getWeapons() const;
	/// Gets the craft's soldier capacity.
	int getSoldiers() const;
	/// Gets the craft's vehicle capacity.
	int getVehicles() const;
	/// Gets the craft's cost.
	int getBuyCost() const;
	/// Gets the craft's refuel item.
	std::string getRefuelItem() const;
	/// Gets the craft's repair rate.
	int getRepairRate() const;
	/// Gets the craft's refuel rate.
	int getRefuelRate() const;
	/// Gets the craft's radar range.
	int getRadarRange() const;
	/// Gets the craft's transfer time.
	int getTransferTime() const;
	/// Gets the craft's score.
	int getScore() const;
	/// Gets the craft's terrain data.
	RuleTerrain *getBattlescapeTerrainData();
	bool getSpacecraft() const { return _spacecraft; }
};

}

#endif
