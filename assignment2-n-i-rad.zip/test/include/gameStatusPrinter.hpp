#ifndef GAMESTATUS_PRINTER_HPP
#define GAMESTATUS_PRINTER_HPP
#include <iostream>

#include "GameStatus.hpp"

std::ostream& operator<<(std::ostream& os, GameStatus const& value) {
  std::string result;

  if (value.isReady()) {
    result = "Ready";
  } else if (value.isInGame()) {
    result = "In game";
  } else if (value.yellowWon()) {
    result = "Yellow won!";
  } else if (value.redWon()) {
    result = "Red won!";
  } else if (value.fullBoard()) {
    result = "Full board!";
  }

  os << result;
  return os;
}

#endif  // GAMESTATUS_PRINTER_HPP