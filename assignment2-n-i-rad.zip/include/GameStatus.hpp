#ifndef GAME_STATUS_HPP
#define GAME_STATUS_HPP

class GameStatus {
 public:
  static const int READY = 0;
  static const int IN_GAME = 1;
  static const int YELLOW_WON = 2;
  static const int RED_WON = 3;
  static const int FULL_BOARD = 4;

  GameStatus() : status(READY) {}
  GameStatus(int state) : status(state) {}
  bool isReady() const { return status == READY; }
  bool isInGame() const { return status == IN_GAME; }
  bool yellowWon() const { return status == YELLOW_WON; }
  bool redWon() const { return status == RED_WON; }
  bool fullBoard() const { return status == FULL_BOARD; }

  void setReady() { status = READY; }
  void setInGame()  {  status = IN_GAME; }
  void setYellowWon()  {  status = YELLOW_WON; }
  void setRedWon() {  status = RED_WON; }
  void setFullBoard()  {  status = FULL_BOARD; }

  bool operator==(const GameStatus &rhs) const {
    return this->status == rhs.status;
  }

 private:
  int status;
};

#endif  // GAME_STATUS_HPP