#include <iostream>
#include <conio.h>

#include "GameField.h"

using namespace std;

int main()
{
	GameField game;
	while (game.game)
	{
		game.symbol = _getch();
		game.gameController(game.symbol);
		system("cls");
		game.printGameField(game.field, game.height, game.width);
	}
}


