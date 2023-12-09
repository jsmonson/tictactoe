#include "TicTacToeGame.h"
#include <iostream>

TicTacToeGame::TicTacToeGame()
{
	winner = CAT; 
	currentState = ST_X_TURN;
	turn = 0; 
}

void TicTacToeGame::advanceToNextTurn()
{
	turn++;
}


void TicTacToeGame::TakeTurn(int row, int col)
{
	board.placeMarker(getCurrentMarker(), row, col);
	advanceGameState(row, col);
	advanceToNextTurn();
}

void TicTacToeGame::advanceGameState(int row, int col)
{
	if (intersectsWinningMarkerSet(row, col))
	{
		setWinner();
		currentState = GameState::ST_GAME_OVER;
	}
	else if (checkForCatsGame())
	{
		currentState = GameState::ST_GAME_OVER;
	}

	if (!isGameOver())
	{
		if (currentState == GameState::ST_X_TURN)
		{
			currentState = GameState::ST_O_TURN;
		}
		else
		{
			currentState = GameState::ST_X_TURN;
		}
	}
}


Marker TicTacToeGame::getCurrentMarker() {
	if(currentState == ST_X_TURN)
	{ 
		return Marker::X;
	}
	else 
	{
		return Marker::O;
	}
	
}

bool TicTacToeGame::checkForCatsGame()
{
	return (winner == CAT && turn == 8);
}

bool TicTacToeGame::isGameOver()
{
	return (currentState == ST_GAME_OVER);
}

TicTacToeGame::Winner TicTacToeGame::getWinner()
{
	if (!isGameOver()) {
		throw GameInProgressException(); 
	}

	return winner;
}

bool TicTacToeGame::intersectsWinningMarkerSet(int row, int col)
{
	
	if (intersectsWinningRow(row) || intersectsWinningColumn(col) || intersectsWinningDiagonal(row, col)) 
	{
		return true;
	}

	return false;
}



bool TicTacToeGame::intersectsWinningRow(int row)
{
	if (allEqual(board.getRow(row)))
	{
		return true;
	}
	return false;
}

bool TicTacToeGame::intersectsWinningColumn(int col)
{
	if (allEqual(board.getColumn(col)))
	{
		return true;
	}
	return false;
}

bool TicTacToeGame::intersectsWinningDiagonal(int row, int col)
{
	if ((board.isLeadingDiagnal(row, col) && allEqual(board.getLeadingDiagnal())) ||
		(board.isCounterDiagnal(row, col) && allEqual(board.getCounterDiagnal())))
	{
		return true;
	}
	return false;
}

bool TicTacToeGame::allEqual(MarkerSet& markers)
{
	return (markers.m[0] == markers.m[1]  && markers.m[1] == markers.m[2]);
}

void TicTacToeGame::setWinner()
{
	if (currentState == ST_X_TURN)
	{
		winner = Winner::Xs; 
	}
	else 
	{
		winner = Winner::Os;
	}
}