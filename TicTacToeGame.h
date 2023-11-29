#ifndef _TICTACTOE_GAME_
#define _TICTACTOE_GAME_

#include <exception>
#include <vector>
#include <utility>

#include "TicTacToeBoard.h"

class TicTacToeGame {
public:

	typedef enum _Winner {
		Xs, Os, CAT
	} Winner;

	
	private:

		TicTacToeBoard board;

		typedef enum _GameState {
			ST_X_TURN,
			ST_O_TURN,
			ST_GAME_OVER
		} GameState;

		GameState currentState; 		
		
		void advanceGameState(int i, int j);
		bool checkForThreeInARow(int i, int j);
		bool checkRow(int row);
		bool checkColumn(int col);
		bool checkDiagnals(int i, int j);
		bool checkForCatsGame();
		bool isSquareEmpty(int i, int j);
		bool allEqual(std::vector<Square> v);
		void setWinner();
		Winner winner;
	public:

		TicTacToeGame(); 
		bool isGameOver();
		Square getCurrentMarker();
		Winner getWinner();
		void TakeTurn(int i, int j);
				
};


class GameInProgressException : std::exception {
public:
	char* what() {
		return "Game Currently in Progress, No Result Yet";
	}
};

#endif