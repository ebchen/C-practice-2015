// Solves the 8-queens problem

#include "stdafx.h"
#include <iostream>

class Sorter {


public:
	static const int SIZE = 8;
	int board[SIZE] = { 0 };
	int counter = 1;
	void printBoard()
	{
		std::cout << "Solution " << counter << ": ";
		counter++;
		for (int x = 0; x < SIZE; x++)
		{
			std::cout << board[x] << ", ";
		}
		std::cout << std::endl;
	}

	bool placer(int column, int row)
	{
		for (int a = 0; a < column; a++)
		{
			if (board[a] == row) return false;
			if (std::abs(board[a] - row) == (column - a)) return false;
		}
		return true;
	}

	bool backtrack(int column)
	{
		if (column == SIZE)
		{
			printBoard();
			return true;
		}
		for (int i = 1; i <= SIZE; i++)
		{
			if (placer(column, i))
			{
				board[column] = i;
				if (backtrack(column + 1)) return true;
			}
		}
		return false;
	}
};

int main()
{ 
	Sorter().backtrack(0);
	getchar();
    return 0;
}

