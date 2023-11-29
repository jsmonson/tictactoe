#include "TicTacToeBoard.h"

TicTacToeBoard::TicTacToeBoard()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			squares[i][j] = Square::EMPTY;
		}
	}
}

std::vector<Square> TicTacToeBoard::getRow(int i)
{
	return {squares[i][0],  squares[i][1],  squares[i][2]};
}

std::vector<Square> TicTacToeBoard::getColumn(int j)
{
	return {squares[0][j],  squares[1][j],  squares[2][j]};
}

std::vector<Square> TicTacToeBoard::getLeadingDiagnal()
{
	return {squares[0][0],  squares[1][1],  squares[2][2]};
}

std::vector<Square> TicTacToeBoard::getCounterDiagnal()
{
	return {squares[2][0], squares[1][1], squares[0][2]};
}

bool TicTacToeBoard::isLeadingDiagnal(int i, int j)
{
	return (i == j);
}

bool TicTacToeBoard::isCounterDiagnal(int i, int j)
{
	return ((i + j) == 2);
}

bool TicTacToeBoard::indexOutOfRange(int n)
{
	return (n < 0) || (n >= MAX_SQUARE_DIM);
}

bool TicTacToeBoard::isValidMarkerPlacement(int i, int j)
{
	return !indexOutOfRange(i) && !indexOutOfRange(j) && !isOccupied(i, j);
}

bool  TicTacToeBoard::isOccupied(int i, int j)
{
	return squares[i][j] != Square::EMPTY;
}

Square TicTacToeBoard::getSquare(int i, int j)
{
	return squares[i][j];
}

Square TicTacToeBoard::getSquare(std::pair<int, int> p)
{
	return getSquare(p.first, p.second);
}

void TicTacToeBoard::placeMarker(Square s, int i, int j)
{
	if (!isValidMarkerPlacement(i, j))
	{
		throw InvalidMarkerPlacementException();
	}

	squares[i][j] = s;
}