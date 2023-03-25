#include"game.h"
#include <SFML/Graphics.hpp>


int main()
{
	Game MyGame;
	while (MyGame.window.isOpen())
	{
		MyGame.Run();
	}
	return 0;
}