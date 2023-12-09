#include "TicTacToeBoard.h"

TicTacToeBoard::TicTacToeBoard()
{
	for (int i = 0; i < MAX_SQUARE_DIM; i++) {
		for (int j = 0; j < MAX_SQUARE_DIM; j++) {
			board[i][j] = Marker::NONE;
		}
	}
}

MarkerSet TicTacToeBoard::getRow(int rowindex)
{
	return {board[rowindex][0],  board[rowindex][1],  board[rowindex][2]};
}

MarkerSet TicTacToeBoard::getColumn(int colindex)
{
	return {board[0][colindex],  board[1][colindex],  board[2][colindex]};
}

MarkerSet TicTacToeBoard::getLeadingDiagnal()
{
	return {board[0][0],  board[1][1],  board[2][2]};
}

MarkerSet TicTacToeBoard::getCounterDiagnal()
{
	return {board[2][0], board[1][1], board[0][2]};
}

bool TicTacToeBoard::isLeadingDiagnal(int row, int col)
{
	return (row == col);
}

bool TicTacToeBoard::isCounterDiagnal(int row, int col)
{
	return ((row + col) == 2);
}

bool TicTacToeBoard::indexOutOfRange(int n)
{
	return (n < 0) || (n >= MAX_SQUARE_DIM);
}

bool TicTacToeBoard::isValidMarkerPlacement(int row, int col)
{
	return !indexOutOfRange(row) && !indexOutOfRange(col) && !isMarked(row, col);
}

bool  TicTacToeBoard::isMarked(int row, int col)
{
	return board[row][col] != Marker::NONE;
}

Marker TicTacToeBoard::getMarker(int row, int col)
{
	return board[row][col];
}

void TicTacToeBoard::placeMarker(Marker s, int row, int col)
{
	if (!isValidMarkerPlacement(row, col))
	{
		throw InvalidMarkerPlacementException();
	}

	board[row][col] = s;
}