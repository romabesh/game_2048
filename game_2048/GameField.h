#pragma once
#include <iostream>
#include <time.h>
#include <vector>

class GameField
{
public:
	bool game = true;
	int height = 4;
	int width = 4;
	int score = 0;
	int** field = new int* [height];
	char symbol;
	GameField();
	void inicalizationField(int** field, int height, int width);
	void printGameField(int** field, int height, int width);
	void generateNewCell(int** field, int height, int width);
	void gameController(char symbol);
	void shiftUp(int** field, int height, int width);
	void shiftDown(int** field, int height, int width);
	void shiftRight(int** field, int height, int width);
	void shiftLeft(int** field, int height, int width);
};

