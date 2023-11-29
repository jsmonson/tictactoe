#pragma once

#include <vector>

typedef enum _Square {
	EMPTY,
	X,
	O
} Square;

#define MAX_SQUARE_DIM 3

class TicTacToeBoard
{
public:
	TicTacToeBoard();
	
	Square squares[MAX_SQUARE_DIM][MAX_SQUARE_DIM];

	std::vector<Square> getRow(int i);
	std::vector<Square> getColumn(int j);
	std::vector<Square> getLeadingDiagnal();
	std::vector<Square> getCounterDiagnal();

	bool isLeadingDiagnal(int i, int j);
	bool isCounterDiagnal(int i, int j);
	bool isValidMarkerPlacement(int i, int j);
	bool indexOutOfRange(int n);
	bool isOccupied(int i, int j);
	Square getSquare(int i, int j);
	Square getSquare(std::pair<int, int> p);
	void placeMarker(Square s, int i, int j);

};

class InvalidMarkerPlacementException : std::exception {

public:
	char* what() {
		return "Invalid Marker Placement";
	}
};

