#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success" << std::endl;

		// set init flags
		int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);

		if (m_pWindow != 0)	// window init success
		{
			std::cout << "window creation success" << std::endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)	// renderer init success
			{
				std::cout << "renderer creation succcess" << std::endl;
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init fail" << std::endl;
				return false;	// renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail" << std::endl;
			return false;	// window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail" << std::endl;
		return false;	// SDL init fail
	}

	std::cout << "init success" << std::endl;
	m_bRunning = true;	// everything inited successfully, start the main loop

	return true;
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}

void Game::render()
{
	// clear the window to the draw color
	SDL_RenderClear(m_pRenderer);

	// draw to the screen
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "cleaning game" << std::endl;
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);

	SDL_Quit();
}
