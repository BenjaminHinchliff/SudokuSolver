#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include <iostream>
#include <array>

using board_t = std::array<std::array<int, 9>, 9>;

class SudokuBoard
{
public:
	SudokuBoard();
	SudokuBoard(const board_t& board);

	bool canInsertAt(int row, int col, int number) const;

	bool solve();

	const board_t& getBoard() const;

	friend std::ostream& operator<< (std::ostream& out, const SudokuBoard& board);

private:
	// mutates row and col to location
	bool findUnassignedLocation(int& row, int& col);
	bool canInsertAtRow(int row, int number) const;
	bool canInsertAtCol(int col, int number) const;
	bool canInsertAtSubBoard(int row, int col, int number) const;

	board_t board = { {
		{ {0, 0, 0, 0, 0, 0, 0, 0, 0} },
		{ {0, 0, 0, 0, 0, 0, 0, 0, 0} },
		{ {0, 0, 0, 0, 0, 0, 0, 0, 0} },
		{ {0, 0, 0, 0, 0, 0, 0, 0, 0} },
		{ {0, 0, 0, 0, 0, 0, 0, 0, 0} },
		{ {0, 0, 0, 0, 0, 0, 0, 0, 0} },
		{ {0, 0, 0, 0, 0, 0, 0, 0, 0} },
		{ {0, 0, 0, 0, 0, 0, 0, 0, 0} },
		{ {0, 0, 0, 0, 0, 0, 0, 0, 0} }
	} };
};

std::ostream& operator<< (std::ostream& out, const SudokuBoard& board);

#endif // !SUDOKU_BOARD_H
