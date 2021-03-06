#include "GameField.h"

using namespace std;

GameField::GameField()
{
	for (int i = 0; i < height; i++)
	{
		field[i] = new int[width];
	}
	inicalizationField(field, height, width);
	generateNewCell(field, height, width);
	printGameField(field, height, width);
}

void GameField::inicalizationField(int** field, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			field[i][j] = NULL;
		}
	}
}
void GameField::printGameField(int** field, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		cout << "|_______________________________|";
		cout << endl << "|   " << "\t" << "|   " << "\t" << "|   " << "\t" << "|   " << "\t" << "|   " << "\t" << endl;
		for (int j = 0; j < width; j++)
		{
			if (field[i][j] == 0)
				cout << "|   " << ' ' << "\t";
			else
				cout << "|   " << field[i][j] << "\t";
		}
		cout << "|";
		cout << endl << "|   " << "\t" << "|   " << "\t" << "|   " << "\t" << "|   " << "\t" << "|   " << "\t" << endl;
	}
	cout << "|_______________________________|" << endl;
}
void GameField::generateNewCell(int** field, int height, int width)
{
	srand(time(NULL));
	vector<int*>vectorNullCell;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (field[i][j] == NULL)
			{
				vectorNullCell.push_back(&field[i][j]);
			}
		}
	}
	if (vectorNullCell.size() != NULL)
	{
		int iterator = rand() % vectorNullCell.size();
		*vectorNullCell[iterator] = 2;
		vectorNullCell.clear();
	}
	else
		game = false;
}

void GameField::shiftUp(int** field, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		int lenght = 0;
		for (int j = 0; j < width; j++)
		{
			if (field[j][i] == NULL)
				lenght++;
			else
			{
				if (j - lenght == j)
					field[j - lenght][i] = field[j][i];
				else
				{
					field[j - lenght][i] = field[j][i];
					field[j][i] = NULL;
				}
			}
		}
	}
}
void GameField::shiftDown(int** field, int height , int width)
{
	for (int i = 0; i < width; i++)
	{
		int lenght = 0;
		for (int j = height - 1; j >= 0; j--)
		{
			if (field[j][i] == NULL)
				lenght++;
			else
			{
				if (j + lenght == j)
					field[j + lenght][i] = field[j][i];
				else
				{
					field[j + lenght][i] = field[j][i];
					field[j][i] = NULL;
				}
			}

		}
	}
}
void GameField::shiftRight(int** field, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		int lenght = 0;
		for (int j = width - 1; j >= 0; j--)
		{
			if (field[i][j] == NULL)
			{
				lenght++;
			}
			else
			{
				if (j + lenght == j)
					field[i][j + lenght] = field[i][j];
				else
				{
					field[i][j + lenght] = field[i][j];
					field[i][j] = NULL;
				}
			}
		}
	}
}
void GameField::shiftLeft(int** field, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		int lenght = 0;
		for (int j = 0; j < width; j++)
		{
			if (field[i][j] == NULL)
			{
				lenght++;
			}
			else
			{
				if (j - lenght == j)
					field[i][j - lenght] = field[i][j];
				else
				{
					field[i][j - lenght] = field[i][j];
					field[i][j] = NULL;
				}
			}
		}
	}
}

void GameField::gameController(char symbol)
{
	if (symbol == 72)
	{
		shiftUp(field, height, width);
		for (int i = 1; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (field[i][j] == field[i - 1][j])
				{
					field[i - 1][j] += field[i][j];
					field[i][j] = NULL;
				}
			}
		}
		shiftUp(field, height, width);
		generateNewCell(field, height, width);
	}
	if (symbol == 80)
	{
		shiftDown(field, height, width);
		for (int i = width - 1; i > 0; i--)
		{
			for (int j = 0; j < width; j++)
			{
				if (field[i - 1][j] == field[i][j])
				{
					field[i - 1][j] += field[i][j];
					field[i][j] = NULL;
				}
			}
		}
		shiftDown(field, height, width);
		generateNewCell(field, height, width);
	}
	if (symbol == 77)
	{
		shiftRight(field, height, width);
		for (int i = 0; i < height; i++)
		{
			for (int j = width - 1; j >= 0; j--)
			{
				if (field[i][j] == field[i][j - 1])
				{
					field[i][j - 1] += field[i][j];
					field[i][j] = NULL;
				}
			}
		}
		shiftRight(field, height, width);
		generateNewCell(field, height, width);
	}
	if (symbol == 75)
	{
		shiftLeft(field, height, width);
		for (int i = 1; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (field[j][i - 1] == field[j][i])
				{
					field[j][i - 1] += field[j][i];
					field[j][i] = NULL;
				}
			}
		}
		shiftLeft(field, height, width);
		generateNewCell(field, height, width);
	}
}

