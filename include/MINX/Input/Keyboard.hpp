/*
# MINX

Copyright (c) 2013-2014 Liam Middlebrook, Benjamin Pylko

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

> 1\. The origin of this software must not be misrepresented; you must not
> claim that you wrote the original software. If you use this software
> in a product, an acknowledgment in the product documentation would be
> appreciated but is not required
>
> 2\. Altered source versions must be plainly marked as such, and must not be
> misrepresented as being the original software
>
> 3\. This notice may not be removed or altered from any source
> distribution
>
 */

#ifndef MINX_KEYBOARD_HPP_
#define MINX_KEYBOARD_HPP_

#include "../API.hpp"

#include "IGenericHID.hpp"
#include "Button.hpp"

#include <map>

namespace MINX
{
	namespace Input
	{

		namespace Keys
		{
			/** Enumerates all readable keys
			 */
			enum MINX_API Keys 
			{
				KEY_0 = 48,
				KEY_1 = 49,
				KEY_2 = 50,
				KEY_3 = 51,
				KEY_4 = 52,
				KEY_5 = 53,
				KEY_6 = 54,
				KEY_7 = 55,
				KEY_8 = 56,
				KEY_9 = 57,
				KEY_A = 65,
				KEY_APOSTROPHE = 39, /* ' */
				KEY_B = 66,
				KEY_BACKSLASH = 92, /* \ */
				KEY_BACKSPACE = 259,
				KEY_C = 67,
				KEY_CAPS_LOCK = 280,
				KEY_COMMA = 44, /* , */
				KEY_D = 68,
				KEY_DELETE = 261,
				KEY_DOWN = 264,
				KEY_E = 69,
				KEY_END = 269,
				KEY_ENTER = 257,
				KEY_EQUAL = 61, /* = */
				KEY_ESCAPE = 256,
				KEY_F = 70,
				KEY_F1 = 290,
				KEY_F10 = 299,
				KEY_F11 = 300,
				KEY_F12 = 301,
				KEY_F13 = 302,
				KEY_F14 = 303,
				KEY_F15 = 304,
				KEY_F16 = 305,
				KEY_F17 = 306,
				KEY_F18 = 307,
				KEY_F19 = 308,
				KEY_F2 = 291,
				KEY_F20 = 309,
				KEY_F21 = 310,
				KEY_F22 = 311,
				KEY_F23 = 312,
				KEY_F24 = 313,
				KEY_F25 = 314,
				KEY_F3 = 292,
				KEY_F4 = 293,
				KEY_F5 = 294,
				KEY_F6 = 295,
				KEY_F7 = 296,
				KEY_F8 = 297,
				KEY_F9 = 298,
				KEY_G = 71,
				KEY_GRAVE_ACCENT = 96, /* ` */
				KEY_H = 72,
				KEY_HOME = 268,
				KEY_I = 73,
				KEY_INSERT = 260,
				KEY_J = 74,
				KEY_K = 75,
				KEY_KP_0 = 320,
				KEY_KP_1 = 321,
				KEY_KP_2 = 322,
				KEY_KP_3 = 323,
				KEY_KP_4 = 324,
				KEY_KP_5 = 325,
				KEY_KP_6 = 326,
				KEY_KP_7 = 327,
				KEY_KP_8 = 328,
				KEY_KP_9 = 329,
				KEY_KP_ADD = 334,
				KEY_KP_DECIMAL = 330,
				KEY_KP_DIVIDE = 331,
				KEY_KP_ENTER = 335,
				KEY_KP_EQUAL = 336,
				KEY_KP_MULTIPLY = 332,
				KEY_KP_SUBTRACT = 333,
				KEY_L = 76,
				KEY_LAST = 348,
				KEY_LEFT = 263,
				KEY_LEFT_ALT = 342,
				KEY_LEFT_BRACKET = 91, /* [ */
				KEY_LEFT_CONTROL = 341,
				KEY_LEFT_SHIFT = 340,
				KEY_LEFT_SUPER = 343,
				KEY_M = 77,
				KEY_MENU = 348,
				KEY_MINUS = 45, /* - */
				KEY_N = 78,
				KEY_NUM_LOCK = 282,
				KEY_O = 79,
				KEY_P = 80,
				KEY_PAGE_DOWN = 267,
				KEY_PAGE_UP = 266,
				KEY_PAUSE = 284,
				KEY_PERIOD = 46, /* . */
				KEY_PRINT_SCREEN = 283,
				KEY_Q = 81,
				KEY_R = 82,
				KEY_RIGHT = 262,
				KEY_RIGHT_ALT = 346,
				KEY_RIGHT_BRACKET = 93, /* ] */
				KEY_RIGHT_CONTROL = 345,
				KEY_RIGHT_SHIFT = 344,
				KEY_RIGHT_SUPER = 347,
				KEY_S = 83,
				KEY_SCROLL_LOCK = 281,
				KEY_SEMICOLON = 59, /* , */
				KEY_SLASH = 47, /* / */
				KEY_SPACE = 32,
				KEY_T = 84,
				KEY_TAB = 258,
				KEY_U = 85,
				KEY_UNKNOWN = -1,
				KEY_UP = 265,
				KEY_V = 86,
				KEY_W = 87,
				KEY_WORLD_1 = 161, /* non-US #1 */
				KEY_WORLD_2 = 162, /* non-US #2 */
				KEY_X = 88,
				KEY_Y = 89,
				KEY_Z = 90
			};
		}

		/** Represents a keyboard device
		 */
		class MINX_API Keyboard : public IGenericHID
		{
			public:
				/** Calls the IGenericHID constructor with game,512,0
				 * @param game A pointer to the Game to attach to
				 */
				Keyboard(Game* game);
				
				/** Updates the state of the Keyboard
				 * @param gametime The GameTime used to update
				 */
				void Update(GameTime* gametime);
				
				/** Gets a button for the state of 'key'
				 * @param key The key to get the state of
				 * @return The Button object representing the key
				 */
				Button GetKey(unsigned int key);
		};
	}
}
#endif
