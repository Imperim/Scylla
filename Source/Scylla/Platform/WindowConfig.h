/*
 *	Scylla
 *	Copyright (C) 2015-2015 Callan Acton <callanacton@gmail.com>
 *
 *	This software is provided 'as-is', without any express or implied
 *	warranty.  In no event will the authors be held liable for any damages
 *	arising from the use of this software.
 *
 *	Permission is granted to anyone to use this software for any purpose,
 *	including commercial applications, and to alter it and redistribute it
 *	freely, subject to the following restrictions:
 *
 *	1. 	The origin of this software must not be misrepresented; you must not
 * 		claim that you wrote the original software. If you use this software
 *    	in a product, an acknowledgment in the product documentation would be
 *    	appreciated but is not required.
 * 
 * 	2. 	Altered source versions must be plainly marked as such, and must not be
 *    	misrepresented as being the original software.
 * 	
 * 	3. 	This notice may not be removed or altered from any source distribution.
 */
#pragma once
#include <cstdint>
#include <string>
#include <Math/Vec2.h>

class WindowConfig {
	// Members
	std::string 	mWindowTitle;
	Vec2u 			mPos,
					mSize;

public:
	WindowConfig(){}
	~WindowConfig(){}

	/**
	 * @brief Accessor for title string of the WindowConfig
	 * @return The title string of the window
	 */
	std::string Title() const {
		return mWindowTitle;
	}

	/**
	 * @brief Sets the title string of the WindowConfig (Shown in the titlebar on most platforms)
	 * 
	 * @param title String to be used as Window's title
	 * @return Reference to WindowConfig object for method chaining
	 */
	WindowConfig& SetTitle(std::string title) {
		mWindowTitle = std::move(title);
		return *this;
	}

	/** @brief Accesses the size of the window */
	Vec2u Size() const {
		return mSize;
	}

	/** @brief Sets the size of the window */
	WindowConfig& SetSize(const Vec2u& size) {
		mSize = size;
		return *this;
	}

	/** @brief Accesses the position of the window */
	Vec2u Pos() const {
		return mPos;
	}

	/** @brief Sets the position of the window */
	WindowConfig& SetPos(const Vec2u& pos) {
		mPos = pos;
		return *this;
	}
};