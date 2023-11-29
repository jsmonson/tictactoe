#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "TicTacToeGame.h"


bool checkAllSquaresOccupied(TicTacToeBoard & B)
{
	for (int i = 0; i < MAX_SQUARE_DIM; i++) {
		for (int j = 0; j < MAX_SQUARE_DIM; j++) {
			if (!B.isOccupied(i, j)) {
				return false;
			}
		}
	}
	return true;
}

bool checkAllSquaresUnoccupied(TicTacToeBoard & B)
{
	for (int i = 0; i < MAX_SQUARE_DIM; i++) {
		for (int j = 0; j < MAX_SQUARE_DIM; j++) {
			if (B.isOccupied(i, j)) {
				return false;
			}
		}
	}
	return true;
}


void fillBoard(TicTacToeBoard& B) {
	for (int i = 0; i < MAX_SQUARE_DIM; i++) {
		for (int j = 0; j < MAX_SQUARE_DIM; j++) {
			B.placeMarker(Square::X, i, j);
		}
	}
}
BOOST_AUTO_TEST_CASE(InitialGameIsEmpty)
{
	TicTacToeBoard B;
	BOOST_TEST(!checkAllSquaresOccupied(B));
}

BOOST_AUTO_TEST_CASE(PlaceMarkerOnAllSquares)
{
  TicTacToeBoard B;
  fillBoard(B);
  
  BOOST_TEST(checkAllSquaresOccupied(B));
}

BOOST_AUTO_TEST_CASE(ExceptionOnInvalidMarkerIndex)
{
	TicTacToeBoard B;
	
	BOOST_CHECK_THROW(B.placeMarker(Square::X, -1, -1), InvalidMarkerPlacementException);
	BOOST_CHECK_THROW(B.placeMarker(Square::X, MAX_SQUARE_DIM, MAX_SQUARE_DIM), InvalidMarkerPlacementException);
	BOOST_CHECK_THROW(B.placeMarker(Square::X, 0, -1), InvalidMarkerPlacementException);
	BOOST_CHECK_THROW(B.placeMarker(Square::X, 0, MAX_SQUARE_DIM), InvalidMarkerPlacementException);
	BOOST_CHECK_THROW(B.placeMarker(Square::X, -1, 0), InvalidMarkerPlacementException);
	BOOST_CHECK_THROW(B.placeMarker(Square::X, MAX_SQUARE_DIM, 0), InvalidMarkerPlacementException);

	BOOST_TEST(checkAllSquaresUnoccupied(B));

	B.placeMarker(Square::X, 0, 0);
	BOOST_CHECK_THROW(B.placeMarker(Square::X, 0, 0), InvalidMarkerPlacementException);
	
}

BOOST_AUTO_TEST_CASE(XGoesFirst)
{
	TicTacToeGame G;

	BOOST_TEST(G.getCurrentMarker() == Square::X);

}

BOOST_AUTO_TEST_CASE(AlternateBetweenXandO)
{
	TicTacToeGame G;

	G.TakeTurn(0, 0); BOOST_TEST(G.getCurrentMarker() == Square::O);
	G.TakeTurn(0, 1); BOOST_TEST(G.getCurrentMarker() == Square::X);

	G.TakeTurn(0, 2); BOOST_TEST(G.getCurrentMarker() == Square::O);
	G.TakeTurn(1, 0); BOOST_TEST(G.getCurrentMarker() == Square::X);

}

BOOST_AUTO_TEST_CASE(ThreeInARowHorizontalXWins)
{
	TicTacToeGame G;

	G.TakeTurn(0, 0); G.TakeTurn(1, 0);
	G.TakeTurn(0, 1); G.TakeTurn(1, 1);
	G.TakeTurn(0, 2);

	BOOST_TEST(G.isGameOver());
	BOOST_TEST(G.getWinner() == TicTacToeGame::Winner::Xs);
}

BOOST_AUTO_TEST_CASE(ThreeInARowHorizontalOWins)
{
	TicTacToeGame G;

	G.TakeTurn(0, 0); G.TakeTurn(1, 0);
	G.TakeTurn(0, 1); G.TakeTurn(1, 1);
	G.TakeTurn(2, 2); G.TakeTurn(1, 2);

	BOOST_TEST(G.isGameOver());
	BOOST_TEST(G.getWinner() == TicTacToeGame::Winner::Os);
}

BOOST_AUTO_TEST_CASE(ThreeInARowVerticalXWins)
{
	TicTacToeGame G;

	G.TakeTurn(0, 0); G.TakeTurn(0, 1);
	G.TakeTurn(1, 0); G.TakeTurn(1, 1);
	G.TakeTurn(2, 0);

	BOOST_TEST(G.isGameOver());
	BOOST_TEST(G.getWinner() == TicTacToeGame::Winner::Xs);
}

BOOST_AUTO_TEST_CASE(ThreeInARowDiagnalOWins)
{
	TicTacToeGame G;

	G.TakeTurn(0, 1); G.TakeTurn(0, 0);
	G.TakeTurn(1, 0); G.TakeTurn(1, 1);
	G.TakeTurn(2, 1); G.TakeTurn(2, 2);

	BOOST_TEST(G.isGameOver());
	BOOST_TEST(G.getWinner() == TicTacToeGame::Winner::Os);
}

BOOST_AUTO_TEST_CASE(ThreeInARowReverseDiagnalXWins)
{
	TicTacToeGame G;

	G.TakeTurn(0, 2); G.TakeTurn(0, 0);
	G.TakeTurn(1, 1); G.TakeTurn(1, 0);
	G.TakeTurn(2, 0);

	BOOST_TEST(G.isGameOver());
	BOOST_TEST(G.getWinner() == TicTacToeGame::Winner::Xs);
}

BOOST_AUTO_TEST_CASE(ThrowErrorIsAskedForWinnerBeforeEndGame)
{
	TicTacToeGame G;

	BOOST_CHECK_THROW(G.getWinner(), GameInProgressException);
}

BOOST_AUTO_TEST_CASE(CatWins)
{
	TicTacToeGame G;
	
	G.TakeTurn(0, 0); G.TakeTurn(0, 1);
	G.TakeTurn(1, 0); G.TakeTurn(2, 0);
	G.TakeTurn(1, 1); G.TakeTurn(2, 2);
	G.TakeTurn(2, 1); G.TakeTurn(1, 2);
	G.TakeTurn(0, 2);

	BOOST_TEST(G.isGameOver());
	BOOST_TEST(G.getWinner() == TicTacToeGame::Winner::CAT);

}