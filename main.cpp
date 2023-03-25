#include"game.h"

int main()
{
	Game MyGame;
	while (MyGame.window.isOpen())
	{
		MyGame.Run();
	}
	return 0;
}