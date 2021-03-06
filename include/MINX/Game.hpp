/*
# MINX

Copyright (c) 2013-2014 Liam Middlebrook, Benjamin Pylko

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

> 1\. The origin of this software must not be misrepresented; you must not
> claim that you wrote the original software. If you use this software
> in a product, an acknowledgment in the product documentation would be
> appreciated but is not required.
> 
> 2\. Altered source versions must be plainly marked as such, and must not be
> misrepresented as being the original software.
> 
> 3\. This notice may not be removed or altered from any source
> distribution.
>
 */

#ifndef MINX_GAME_HPP_
#define MINX_GAME_HPP_

#include "API.hpp"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <string>
#include <vector>
#include <queue>
#include <iostream>

#include "Graphics/Font.hpp"
#include "Graphics/TextureBatch.hpp"
#include "Graphics/RenderTarget.hpp"
#include "GameComponent.hpp"
#include "GameTime.hpp"
#include "Graphics/GameWindow.hpp"
#include <thread>
#include <mutex>

namespace MINX
{
	/** The class that handles everything.
	 * When using the library, your code will probably construct and Run() your subclass of Games
	 */
	class MINX_API Game 
	{
		public:
			/** The constructor, which handles some of the initialization code for the Game
			 */
			Game();
		
			/** This handles the rest of the initialization code for the game
			 */
			virtual void Initialize();
		
			/** Loads content used by the game
			 */
			virtual void LoadContent();
		
			/** Updates the game state
			 * Should be extended when you create a subclass of Game
			 * @param gameTime the GameTime to use when updating
			 */
			virtual void Update(GameTime* gameTime);
		
			/** Unloads content used by the game
			 */
			virtual void UnloadContent();
		
			/** Draws the state of the game every frame
			 * This method is called by a different thread than Update(), so it is ok to use sleeps in Update() and not worry about freezing the drawing, or vice versa
			 * @param gameTime the GameTime to use when drawing
			 */
			virtual void Draw(GameTime* gameTime);
		
			/** Handles Update()ing, Draw()ing, and event handling
			 */
			void Run();
		
			/** A pointer to the window used by the game
			 */
			Graphics::GameWindow* gameWindow;
		
			/** A pointer to a vector of pointers to the GameComponents used in the game
			 */
			std::vector<GameComponent*>* Components;
		
			/** Set the video options when creating a new GameWindow
			 *	@param windowWidth The Width of the GameWindow
			 *	@param windowHeight The Height of the GameWindow
			 *	@param fullscreen Whether or not the window is fullscreen
			 */
			void SetVideoOptions(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen);
		
			/** Set the video options when creating a new GameWindow
			 *	@param windowWidth The Width of the GameWindow
			 *	@param windowHeight The Height of the GameWindow
			 *	@param fullscreen Whether or not the window is fullscreen
			 *	@param windowTitle The title of the GameWindow
			 */
			void SetVideoOptions(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, char* windowTitle);
		
			/** Is the Game Running, or should it close?
			 */
			bool isRunning;
		
			/** Set's the Game's RenderTarget and clears to the clearColor
			 * @param target The RenderTarget to render to, defaults to NULL, if null the entire window is used
			 * @param clearColor The color to clear the RenderTarget to, defaults to CornflowerBlue
			 */
			void SetRenderTarget(Graphics::RenderTarget* target = NULL, Graphics::Color clearColor = Graphics::Color::CornflowerBlue);

		protected:
			/** An instance of freetype used to draw text
			 */
			FT_Library freeTypeLibrary;

		private:
			/** A pointer to the GameTime being used by the game
			 */
			GameTime* gameTime;
		
			/** The width of the window
			 */
			int windowWidth;
		
			/** The height of the window
			 */
			int windowHeight;
		
			/** Whether or not the window is fullscreen
			 */
			bool fullscreen;
		
			/** The title of the window
			 */
			char* windowTitle;
		
			/** The current RenderTarget for the game
			 */
			static Graphics::RenderTarget* activeRenderTarget;
		
		friend class MINX::Graphics::Font;
		friend class MINX::Graphics::TextureBatch;
	};
}
#endif
