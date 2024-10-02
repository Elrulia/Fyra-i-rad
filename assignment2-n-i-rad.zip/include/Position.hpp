#ifndef POSITION_HPP
#define POSITION_HPP

class Position {
 public:
  Position() : state(FREE){};

  void redPlays() {
    if (state != FREE) {
      throw "Red cannot put a piece here as it is already occupied!";
    }
    state = RED;
  }

  void yellowPlays() {
    if (state != FREE) {
      throw "Yellow cannot put a piece here as it is already occupied!";
    }
    state = YELLOW;
  }

// Custom statereturner för att kunna printa boarden
  int statereturn() const {
    return state;
  }

  bool isFree() const { return state == FREE; }
  bool isRed() const { return state == RED; }
  bool isYellow() const { return state == YELLOW; }

 private:
  static const int FREE = 0;
  static const int YELLOW = 1;
  static const int RED = 2;

  int state;
};

#endif  // POSITION_HPP