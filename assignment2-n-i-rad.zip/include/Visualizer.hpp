#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#define FMT_HEADER_ONLY
#include <fmt/color.h>
#include <fmt/format.h>

#include <string>

/** A utility class to visualize the progress in Connect four games*/
class Visualizer {
 public:
  /** Constructor that crates a default board of 7x7 */
  Visualizer() : Visualizer(7, 7) {}

  /** Constructor for custom board sizes */
  Visualizer(int columns, int rows) : columns(columns), rows(rows) {
    board.resize(rows + 2);
    for (int y = 0; y < rows + 2; ++y) {
      board[y].resize(columns + 2);
      for (int x = 0; x < columns + 2; ++x) {
        board[y][x] = ' ';
      }
    }
    for (int x = 0; x < columns + 2; x++) {
      board[0][x] = '-';
      board[rows + 1][x] = '-';
    }
    for (int y = 0; y < rows + 2; y++) {
      board[y][0] = '|';
      board[y][columns + 1] = '|';
    }
    board[0][0] = '+';
    board[0][columns + 1] = '+';
    board[rows + 1][0] = '+';
    board[rows + 1][columns + 1] = '+';
    cnt.resize(columns);
    for (int y = 0; y < columns; ++y) {
      cnt[y] = 0;
    }
  }

  /** Use this method to visualize that the yellow player plays */
  void yellowPlays(int column) {
    if (column < 1 || column > columns || cnt[column - 1] >= rows) {
      throw "Yellow can't play here! It's outside of the board!";
    }
    board[rows - cnt[column - 1]++][column] =
        fmt::format(fmt::emphasis::bold | fg(fmt::color::yellow), "x");
  }

  /** Use this method to visualize that the red player plays */
  void redPlays(int column) {
    if (column < 1 || column > columns || cnt[column - 1] >= rows) {
      throw "Red can't play here! It's outside of the board!";
    }
    board[rows - cnt[column - 1]++][column] =
        fmt::format(fmt::emphasis::bold | fg(fmt::color::red), "o");
  }

  /** Get s printout showing the board and the status */
  std::string print() {
    std::string result = "";
    for (int y = 0; y < board.size(); ++y) {
      for (int x = 0; x < board[y].size(); ++x) {
        result += board[y][x];
      }
      result += '\n';
    }
    return result;
  }

 private:
  std::vector<std::vector<std::string>> board;
  /** Count how many pieces  that are stacked in each column */
  std::vector<int> cnt;
  int columns;
  int rows;
};

#endif  // VISUALIZER_HPP