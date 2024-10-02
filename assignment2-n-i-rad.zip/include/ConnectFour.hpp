#ifndef CONNECT_FOUR_HPP
#define CONNECT_FOUR_HPP

#include "GameStatus.hpp"
#include "Position.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** Main class for the game ConnectFour. This class keeps track of a board and
 * its status and lets two players play against each other. The memeber function
 * `getCurrentStatus()` can be used to check whether the game has started and if
 * someone has won, who in that case.
 */
class ConnectFour{
public:

  ConnectFour(int columns, int rows, int numToConnect);
  ~ConnectFour();

  /**
   * Function used to place a piece for the yellow player. Returns true if the
   * yellow player can play on that column and false otherwise.
   */
  bool yellowPlays(int col);

  /**
   * Function used to place a piece for the red player. Returns true if the red
   * player can play on that column and false otherwise.
   */
  bool redPlays(int col);

  GameStatus getCurrentStatus() const;

  // Add your own public methods here

  std::string FixColor(std::string color);

  std::string checkStart(std::string start);

  void whoStarts(std::string* start, std::string* color);

  void printBoard();

  bool gameRunning();

  bool yellowWins();

  bool redWins();

  bool boardFull();

private:
  std::vector<std::string> player1;
  std::vector<std::string> player2;
  std::string playAgain;
  Position** boardPositions;
  GameStatus gamestatus;
  int columnPlay = 0;
  int totalConnect = 0;
  int playColumns = 0;
  int playRows = 0;
  // Add your own private methods and member variables here

  void columnPlayCheck();

  void play1();

  void play2();
};

#endif // CONNECT_FOUR_HPP