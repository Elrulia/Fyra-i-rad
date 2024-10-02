#include "ConnectFour.hpp"
#include <iostream>
#include <string>

int main() {
  bool playGame = true;
  int n = 0;
  int columns = 0;
  int rows = 0;
  std::string color;
  std::string start;

  while (playGame) {
    std::cout << "Hello and welcome to a game of \"Connect n\"!" << std::endl;
    std::cout << "What should \"n\" be: " << std::endl;
    std::cout << "> ";
    std::cin >> n;
    std::cout << "How many columns?" << std::endl;
    std::cout << "> ";
    std::cin >> columns;
    std::cout << "How many rows?" << std::endl;
    std::cout << "> ";
    std::cin >> rows;

    ConnectFour cf(columns, rows, n);

    std::cout << "Do you want to be red or yellow?" << std::endl;
    std::cout << "> ";
    std::cin >> color;
    color = cf.FixColor(color);
    std::cout << color << " it is, do you want to start? (yes/no)" << std::endl;
    std::cout << "> ";
    std::cin >> start;
    start = cf.checkStart(start);
    cf.whoStarts(&start, &color);
    cf.printBoard();

    if (!cf.gameRunning()) {
      playGame = false;
    };
  }
  std::cout << "Thanks for playing \"Count n\"!" << std::endl;
}
