#ifndef _TICTACTOE_GAME_
#define _TICTACTOE_GAME_

#include <exception>
#include <utility>

#include "TicTacToeBoard.h"

class TicTacToeGame {
public:

	typedef enum _Winner {
		Xs, Os, CAT
	} Winner;

	
	private:

		TicTacToeBoard board;

		uint32_t       turn; 

		typedef enum _GameState {
			ST_X_TURN,
			ST_O_TURN,
			ST_GAME_OVER
		} GameState;

		GameState currentState; 		
		
		void advanceGameState(int row, int col);
		void advanceToNextTurn();
		bool intersectsWinningMarkerSet(int row, int col);
		bool intersectsWinningRow(int row);
		bool intersectsWinningColumn(int col);
		bool intersectsWinningDiagonal(int row, int col);
		bool checkForCatsGame();
		bool isSquareEmpty(int row, int col);
		bool allEqual(MarkerSet & m);
		void setWinner();
		Winner winner;
	public:

		TicTacToeGame(); 
		bool isGameOver();
		Marker getCurrentMarker();
		Winner getWinner();
		void TakeTurn(int row, int col);
				
};


class GameInProgressException : std::exception {
public:
	char* what() {
		return "Game Currently in Progress, No Result Yet";
	}
};

#endif