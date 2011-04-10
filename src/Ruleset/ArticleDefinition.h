/*
 * Copyright 2011 OpenXcom Developers.
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

#ifndef OPENXCOM_ARTICLEDEFINITION_H
#define OPENXCOM_ARTICLEDEFINITION_H

#include <string>
#include <vector>

namespace OpenXcom
{
	class RuleCraft;	
	class RuleCraftWeapon;
	
	/// define article types
	enum UfopaediaTypeId {
		UFOPAEDIA_TYPE_UNKNOWN				= 0,
		UFOPAEDIA_TYPE_CRAFT					= 1,
		UFOPAEDIA_TYPE_CRAFT_WEAPON		= 2,
		UFOPAEDIA_TYPE_HWP						= 3,
		UFOPAEDIA_TYPE_EQUIPMENT			= 4,
		UFOPAEDIA_TYPE_WEAPON					= 5,
		UFOPAEDIA_TYPE_FACILITY				= 6,
		UFOPAEDIA_TYPE_TEXTIMAGE			= 7,
		UFOPAEDIA_TYPE_TEXT						= 8,
		UFOPAEDIA_TYPE_UFO						= 9
	};

	/**
	 * ArticleDefinition is the base class for all article types.
	 * This class is used to store all information about articles 
	 * required to generate an ArticleState from.
	 */
	
	class ArticleDefinition
	{
	protected:
		/// constructor (protected, so this class cannot be instantiated directly).
		ArticleDefinition(UfopaediaTypeId type_id);

	public:
		/// destructor
		virtual ~ArticleDefinition();

		/// get the type of article definition.
		UfopaediaTypeId getType();
		
		std::string id;
		std::string title;
		std::string section;
		int sort_key;
		
	protected:
		UfopaediaTypeId _type_id;
	};

	class ArticleDefinitionRect
	{
	public:
		ArticleDefinitionRect();
		
		void set(int set_x, int set_y, int set_width, int set_height);
		
		int x;
		int y;
		int width;
		int height;
	};
	
	/**
	 * ArticleDefinitionCraft defines articles for craft, e.g. SKYRANGER.
	 * They have a large background image, a stats block and a description positioned differently.
	 */
	
	class ArticleDefinitionCraft : public ArticleDefinition
	{
	public:
		/// Constructor
		ArticleDefinitionCraft();
		
		std::string image_id;
		ArticleDefinitionRect rect_stats;
		ArticleDefinitionRect rect_text;
		RuleCraft *craft;
		std::string text;
	};
	
	/**
	 * ArticleDefinitionCraftWeapon defines articles for craft weapons, e.g. STINGRAY, AVALANCHE.
	 * They have a large background image and a stats block.
	 */
	
	class ArticleDefinitionCraftWeapon : public ArticleDefinition
	{
	public:
		/// Constructor
		ArticleDefinitionCraftWeapon();
		
		std::string image_id;
		RuleCraftWeapon *weapon;
	};
	
	/**
	 * ArticleDefinitionText defines articles with only text, e.g. ALIEN RESEARCH.
	 */
	
	class ArticleDefinitionText : public ArticleDefinition
	{
		public:
		/// Constructor
		ArticleDefinitionText();
		
		std::string text;
	};
	
	/**
	 * ArticleDefinitionTextImage defines articles with text on the left and 
	 * an image on the right side of the screen, e.g. ALIEN LIFEFORMS, UFO COMPONENTS.
	 */
	
	class ArticleDefinitionTextImage : public ArticleDefinition
	{
		public:
		/// Constructor
		ArticleDefinitionTextImage();
		
		std::string image_id;
		std::string text;
		int text_width;
	};
	
}

#endif