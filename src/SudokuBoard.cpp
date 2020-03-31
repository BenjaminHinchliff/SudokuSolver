#include "SudokuBoard.h"

SudokuBoard::SudokuBoard()
{
}

SudokuBoard::SudokuBoard(const board_t& board)
	: board(board)
{
}

bool SudokuBoard::canInsertAtRow(int row, int number) const
{
	for (size_t col = 0; col < board[row].size(); ++col)
	{
		if (board[row][col] == number)
		{
			return false;
		}
	}
	return true;
}
bool SudokuBoard::canInsertAtCol(int col, int number) const
{
	for (size_t row = 0; row < board[0].size(); ++row)
	{
		if (board[row][col] == number)
		{
			return false;
		}
	}
	return true;
}
bool SudokuBoard::canInsertAtSubBoard(int row, int col, int number) const
{
	int rowStart = row / 3 * 3;
	int colStart = col / 3 * 3;
	for (int y = rowStart; y < rowStart + 3; ++y)
	{
		for (int x = colStart; x < colStart + 3; ++x)
		{
			if (board[y][x] == number)
			{
				return false;
			}
		}
	}
	return true;
}
bool SudokuBoard::canInsertAt(int row, int col, int number) const
{
	return board[row][col] == 0
		&& canInsertAtRow(row, number)
		&& canInsertAtCol(col, number)
		&& canInsertAtSubBoard(row, col, number);
}

bool SudokuBoard::findUnassignedLocation(int& row, int& col)
{
	for (row = 0; row < board.size(); ++row)
	{
		for (col = 0; col < board[row].size(); ++col)
		{
			if (board[row][col] == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool SudokuBoard::solve()
{
	int row;
	int col;
	if (!findUnassignedLocation(row, col))
	{
		return true;
	}

	for (int num = 1; num <= 9; ++num)
	{
		if (canInsertAt(row, col, num))
		{
			board[row][col] = num;
			if (solve())
			{
				return true;
			}
			board[row][col] = 0;
		}
	}
	return false;
}

const board_t& SudokuBoard::getBoard() const
{
	return board;
}

std::ostream& operator<< (std::ostream& out, const SudokuBoard& sudokuBoard)
{
	const board_t& board = sudokuBoard.board;
	for (size_t y = 0; y < board.size(); ++y)
	{
		const auto& row = board[y];
		std::cout << ' ';
		for (size_t x = 0; x < row.size() - 1; ++x)
		{
			std::cout << row[x] << " | ";
		}
		std::cout << row[row.size() - 1];
		if (y != board.size() - 1)
		{
			std::cout << '\n';
			std::cout << std::string(board.size() * 4 - 1, '-') << '\n';
		}
	}
	return out;
}