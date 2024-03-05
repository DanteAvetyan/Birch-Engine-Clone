#include "Game.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 640;

Game* game = nullptr;

int main(int argc, char* argv[])
{
	do
	{
		if (Game::playAgain)
		{
			game->clean();
			game->reset();
		}

		const int FPS = 60;
		const int frameDelay = 1000 / FPS;

		Uint32 frameStart;
		int frameTime;

		game = new Game();
		game->init("BirchEngine", SCREEN_WIDTH, SCREEN_HEIGHT, false);

		while (game->running())
		{
			std::cout << "Game loop running..." << std::endl;

			frameStart = SDL_GetTicks();

			game->handleEvents();
			game->update();
			game->render();

			/*if (Game::isGameOver)
			{
				//SDL_Delay(7000); // Wait for 6 seconds
				//game->clean();
				//Game::isRunning = false; // Stop the game loop
			}*/

			frameTime = SDL_GetTicks() - frameStart;

			if (frameDelay > frameTime)
			{
				SDL_Delay(frameDelay - frameTime);
			}
		}

	} while (Game::playAgain);

	game->clean();
	return 0;
}
