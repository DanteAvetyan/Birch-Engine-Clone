#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

class AssetManager;
class ColliderComponent;

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	//Game Functions
	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();
	void reset();

	static SDL_Renderer* renderer;
	static SDL_Event event;

	//Game States
	static bool isRunning;
	static bool isGameOver;
	static bool playAgain;
	static bool quit;

	static SDL_Rect camera;
	static AssetManager* assets;
	enum groupLabels : std::size_t
	{
		groupMap,
		groupPlayers,
		groupColliders,
		groupProjectiles,
		grouptext
	};


private:
	int cnt = 0;
	SDL_Window* window;
};