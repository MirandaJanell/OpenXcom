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
#ifndef OPENXCOM_ALIEN_MISSION_H
#define OPENXCOM_ALIEN_MISSION_H

#include <string>
#include <yaml-cpp/yaml.h>

namespace OpenXcom
{

class RuleAlienMission;
class Ufo;
class Globe;
class Game;
class SavedGame;
class Ruleset;
class RuleUfo;
class UfoTrajectory;
class AlienBase;

/**
 * Represents an ongoing alien mission.
 * Contains variable info about the mission, like spawn counter, target region
 * and current wave.
 * @sa RuleAlienMission
 */
class AlienMission
{
private:
	const RuleAlienMission &_rule;
	std::string _region, _race;
	unsigned _nextWave;
	unsigned _nextUfoCounter;
	unsigned _spawnCountdown;
	unsigned _liveUfos;
	int _uniqueID;
	const AlienBase *_base;
public:
	// Data

	/// Creates a mission of the specified type.
	AlienMission(const RuleAlienMission &rule);
	/// Cleans up the mission info.
	~AlienMission();
	/// Loads the mission from YAML.
	void load(const YAML::Node& node, SavedGame &game);
	/// Saves the mission to YAML.
	void save(YAML::Emitter& out) const;
	/// Gets the mission's type.
	const std::string &getType() const;
	/// Gets the mission's region.
	const std::string &getRegion() const { return _region; }
	/// Sets the mission's region.
	void setRegion(const std::string &region) { _region = region; }
	/// Gets the mission's race.
	const std::string &getRace() const { return _race; }
	/// Sets the mission's race.
	void setRace(const std::string &race) { _race = race; }
	/// Gets the minutes until next wave spawns.
	unsigned getWaveCountdown() const { return _spawnCountdown; }
	/// Sets the minutes until next wave spawns.
	void setWaveCountdown(unsigned minutes);
	/// Sets the unique ID for this mission.
	void setId(int id);
	/// Gets the unique ID for this mission.
	int getId() const;
	/// Gets the alien base for this mission.
	const AlienBase *getAlienBase() const;
	/// Sets the alien base for this mission.
	void setAlienBase(const AlienBase *base);

	// Behaviour

	/// Is this mission over?
	bool isOver() const;
	/// Handle UFO spawning for the mission.
	void think(Game &engine, const Globe &globe);
	/// Initialize with values from rules.
	void start(unsigned initialCount = 0);
	/// Increase number of live UFOs.
	void increaseLiveUfos() { ++_liveUfos; }
	/// Decrease number of live UFOs.
	void decreaseLiveUfos() { --_liveUfos; }
	/// Handle UFO reaching a waypoint.
	void ufoReachedWaypoint(Ufo &ufo, Game &engine, const Globe &globe);
	/// Handle UFO lifting from the ground.
	void ufoLifting(Ufo &ufo, Game &engine, const Globe &globe);
	/// Handle UFO shot down.
	void ufoShotDown(Ufo &ufo, Game &engine, const Globe &globe);
	/// Handle Points for mission successes.
	void addScore(const double lon, const double lat, Game &engine);
private:
	/// Spawns a UFO, based on mission rules.
	Ufo *spawnUfo(const SavedGame &game, const Ruleset &ruleset, const Globe &globe, const RuleUfo &ufoRule, const UfoTrajectory &trajectory);
	/// Spawn an alien base
	void spawnAlienBase(Ufo* ufo, const Globe &globe, Game &engine);
};

}

#endif
