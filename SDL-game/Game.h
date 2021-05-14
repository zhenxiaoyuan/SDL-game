#pragma once
#ifndef __Game__
#define __Game__

#include <SDL.h>

class Game
{
public:
	Game() {}
	~Game() {}

	// simply set the running variable to true
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);

	void handleEvents();
	void update() {}
	void render();
	void clean();

	// a function to access the private running variable
	bool running() { return m_bRunning; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning = false;
};

#endif // !__Game__
