#pragma once

#include <exception>

typedef enum _Marker {
	NONE,
	X,
	O
} Marker;

#define MAX_SQUARE_DIM 3

typedef struct _MarkerSet {
	Marker m[MAX_SQUARE_DIM];
} MarkerSet;

class TicTacToeBoard
{
public:
	TicTacToeBoard();
	
	Marker board[MAX_SQUARE_DIM][MAX_SQUARE_DIM];

	MarkerSet getRow(int row);
	MarkerSet getColumn(int col);
	MarkerSet getLeadingDiagnal();
	MarkerSet getCounterDiagnal();

	bool isLeadingDiagnal(int row, int col);
	bool isCounterDiagnal(int row, int col);
	bool isValidMarkerPlacement(int row, int col);
	bool indexOutOfRange(int n);
	bool isMarked(int row, int col);
	Marker getMarker(int row, int col);
	void placeMarker(Marker s, int row, int col);

};

class InvalidMarkerPlacementException : std::exception {

public:
	char* what() {
		return "Invalid Marker Placement";
	}
};

