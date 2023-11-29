#include "TicTacToeGame.h"
#include <iostream>

TicTacToeGame::TicTacToeGame() {

	winner = CAT;
	currentState = ST_X_TURN;
	 
}

void TicTacToeGame::TakeTurn(int i, int j)
{
	board.placeMarker(getCurrentMarker(), i, j);
	advanceGameState(i, j);
}

void TicTacToeGame::advanceGameState(int i, int j)
{
	if (checkForThreeInARow(i, j))
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


Square TicTacToeGame::getCurrentMarker() {
	if(currentState == ST_X_TURN)
	{ 
		return Square::X;
	}
	else 
	{
		return Square::O;
	}
	
}

bool TicTacToeGame::checkForCatsGame()
{
	for (int i = 0; i < MAX_SQUARE_DIM; i++)
	{
		for (int j = 0; j < MAX_SQUARE_DIM; j++)
		{
			if (!board.isOccupied(i,j))
			{
				return false; 
			}
		}
	}
	return true;
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

bool TicTacToeGame::checkForThreeInARow(int i, int j)
{
	
	if (checkRow(i) || checkColumn(j) || checkDiagnals(i, j)) 
	{
		return true;
	}

	return false;
}



bool TicTacToeGame::checkRow(int row)
{
	if (allEqual(board.getRow(row)))
	{
		return true;
	}
	return false;
}

bool TicTacToeGame::checkColumn(int col)
{
	if (allEqual(board.getColumn(col)))
	{
		return true;
	}
	return false;
}

bool TicTacToeGame::checkDiagnals(int i, int j)
{
	if ((board.isLeadingDiagnal(i, j) && allEqual(board.getLeadingDiagnal())) ||
		(board.isCounterDiagnal(i, j) && allEqual(board.getCounterDiagnal())))
	{
		return true;
	}
	return false;
}

bool TicTacToeGame::allEqual(std::vector<Square> v)
{
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] != v[i - 1])
		{
			return false;
		}
	}
	
	return true;
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