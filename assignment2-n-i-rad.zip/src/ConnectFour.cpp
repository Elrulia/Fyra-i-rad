#include "ConnectFour.hpp"

ConnectFour::ConnectFour(int columns, int rows, int numToConnect)
{
  totalConnect = numToConnect;
  playColumns = columns;
  playRows = rows;
  boardPositions = new Position *[rows];
  for (int i = 0; i < rows; i++)
  {
    boardPositions[i] = new Position[columns];
  }
  gamestatus.setReady();
}

ConnectFour::~ConnectFour()
{
  for (int i = 0; i < playRows; i++)
  {
    delete[] boardPositions[i];
  }
  delete[] boardPositions;
}

bool ConnectFour::gameRunning()
{
  while (gamestatus.isReady() || gamestatus.isInGame())
  {
    if (player1[1] == "yes")
    {
      play1();
      printBoard();
      if (yellowWins())
      {
        gamestatus.setYellowWon();
      }
      else if (redWins())
      {
        gamestatus.setRedWon();
      }
      else if (boardFull())
      {
        gamestatus.setFullBoard();
      }
      if (gamestatus.redWon() ||gamestatus.yellowWon() || gamestatus.fullBoard()){
        break;
      }
      play2();
      printBoard();
      if (yellowWins())
      {
        gamestatus.setYellowWon();
      }
      else if (redWins())
      {
        gamestatus.setRedWon();
      }
      else if (boardFull())
      {
        gamestatus.setFullBoard();
      }
      if (gamestatus.redWon() ||gamestatus.yellowWon() || gamestatus.fullBoard()){
        break;
      }
    }
    else
    {
      play2();
      printBoard();
      if (yellowWins())
      {
        gamestatus.setYellowWon();
      }
      else if (redWins())
      {
        gamestatus.setRedWon();
      }
      else if (boardFull())
      {
        gamestatus.setFullBoard();
      }
      if (gamestatus.redWon() ||gamestatus.yellowWon() || gamestatus.fullBoard()){
        break;
      }
      play1();
      printBoard();
      if (yellowWins())
      {
        gamestatus.setYellowWon();
      }
      else if (redWins())
      {
        gamestatus.setRedWon();
      }
      else if (boardFull())
      {
        gamestatus.setFullBoard();
      }
      if (gamestatus.redWon() ||gamestatus.yellowWon() || gamestatus.fullBoard()){
        break;
      }
    }
  }
  if (redWins())
  {
    std::cout << "Red player won!\n~~~~~~~~~~~~~~~" << std::endl;
  }

  if (yellowWins())
  {
    std::cout << "Yellow player won!\n~~~~~~~~~~~~~~~~~~" << std::endl;
  }

  if (boardFull())
  {
    std::cout << "The board is full and you can no longer place any more!" << std::endl;
  }
  std::cout << "Do you want to play again? (yes/no)\n> ";
  std::cin >> playAgain;
  playAgain = checkStart(playAgain);

  return playAgain == "yes";
}
bool ConnectFour::yellowWins()
{
  int n = 0;

  //Col rad
  for (int i = 0; i < playRows; i++)
  {
    n = 0;
    for (int j = 0; j < playColumns; j++)
    {
      if (boardPositions[i][j].isYellow())
      {
        n++;
      }
      else
      {
        n = 0;
      }
      if (n == totalConnect)
      {
        gamestatus.setYellowWon();
        return true;
      }
    }
  }

  //Row rad
  for (int i = 0; i < playColumns; i++)
  {
    n = 0;
    for (int j = 0; j < playRows; j++)
    {
      if (boardPositions[j][i].isYellow())
      {
        n++;
      }
      else
      {
        n = 0;
      }
      if (n == totalConnect)
      {
        gamestatus.setYellowWon();
        return true;
      }
    }
  }

  //TOP RIGHTWAYS
  int row = 0;
  int col = 0;
  for (int i = 0; i <= playRows - totalConnect; i++)
  {
    n = 0;
    for (row = i, col = 0; row < playRows && col < playColumns; row++, col++)
    {
      if (boardPositions[row][col].isYellow())
      {
        n++;
        if (n == totalConnect)
        {
          gamestatus.setYellowWon();
          return true;
        }
      }
      else
      {
        n = 0;
      }
    }
  }
  //TOP LEFTWAYS
  for (int i = 0; i <= playRows - totalConnect; i++)
  {
    n = 0;
    for (row = i, col = playColumns - 1; row < playRows && col >= 0; row++, col--)
    {
      if (boardPositions[row][col].isYellow())
      {
        n++;
        if (n == totalConnect)
        {
          gamestatus.setYellowWon();
          return true;
        }
      }
      else
      {
        n = 0;
      }
    }
  }
  //BOT RIGHTWAYS
  for (int i = 1; i <= playColumns - totalConnect; i++)
  {
    n = 0;
    for (row = 0, col = i; row < playRows && col < playColumns; row++, col++)
    {
      if (boardPositions[row][col].isYellow())
      {
        n++;
        if (n == totalConnect)
        {
          gamestatus.setYellowWon();
          return true;
        }
      }
      else
      {
        n = 0;
      }
    }
  }
  //BOT LEFTWAYS
  for (int i = 1; i <= playColumns - totalConnect; i++)
  {
    n = 0;
    for (row = playRows - 1, col = i; row >= 0 && col < playColumns; row--, col++)
    {
      if (boardPositions[row][col].isYellow())
      {
        n++;
        if (n == totalConnect)
        {
          gamestatus.setYellowWon();
          return true;
        }
      }
      else
      {
        n = 0;
      }
    }
  }
  return false;
}

bool ConnectFour::yellowPlays(int col)
{
  if (gamestatus.yellowWon() || gamestatus.redWon() || gamestatus.fullBoard())
  {
    return false;
  }
  gamestatus.setInGame();
  if (col > playColumns || col <= 0)
  {
    return false;
  }
  for (int i = playRows - 1; i >= 0; i--)
  {
    if (boardPositions[col - 1][i].isFree())
    {
      boardPositions[col - 1][i].yellowPlays();
      if (yellowWins())
      {
        gamestatus.setYellowWon();
      }
      if (boardFull())
      {
        gamestatus.setFullBoard();
      }
      return true;
    }
  }
  return false;
}

bool ConnectFour::redWins()
{
  int n = 0;

  //Col rad
  for (int i = 0; i < playRows; i++)
  {
    n = 0;
    for (int j = 0; j < playColumns; j++)
    {
      if (boardPositions[i][j].isRed())
      {
        n++;
      }
      else
      {
        n = 0;
      }
      if (n == totalConnect)
      {
        gamestatus.setRedWon();
        return true;
      }
    }
  }

  //Row rad
  for (int i = 0; i < playColumns; i++)
  {
    n = 0;
    for (int j = 0; j < playRows; j++)
    {
      if (boardPositions[j][i].isRed())
      {
        n++;
      }
      else
      {
        n = 0;
      }
      if (n == totalConnect)
      {
        gamestatus.setRedWon();
        return true;
      }
    }
  }

  //TOP RIGHTWAYS
  int row = 0;
  int col = 0;
  for (int i = 0; i <= playRows - totalConnect; i++)
  {
    n = 0;
    for (row = i, col = 0; row < playRows && col < playColumns; row++, col++)
    {
      if (boardPositions[row][col].isRed())
      {
        n++;
        if (n == totalConnect)
        {
          gamestatus.setRedWon();
          return true;
        }
      }
      else
      {
        n = 0;
      }
    }
  }
  //TOP LEFTWAYS
  for (int i = 0; i <= playRows - totalConnect; i++)
  {
    n = 0;
    for (row = i, col = playColumns - 1; row < playRows && col >= 0; row++, col--)
    {
      if (boardPositions[row][col].isRed())
      {
        n++;
        if (n == totalConnect)
        {
          gamestatus.setRedWon();
          return true;
        }
      }
      else
      {
        n = 0;
      }
    }
  }
  //BOT RIGHTWAYS
  for (int i = 1; i <= playColumns - totalConnect; i++)
  {
    n = 0;
    for (row = 0, col = i; row < playRows && col < playColumns; row++, col++)
    {
      if (boardPositions[row][col].isRed())
      {
        n++;
        if (n == totalConnect)
        {
          gamestatus.setRedWon();
          return true;
        }
      }
      else
      {
        n = 0;
      }
    }
  }
  //BOT LEFTWAYS
  for (int i = 1; i <= playColumns - totalConnect; i++)
  {
    n = 0;
    for (row = playRows - 1, col = i; row >= 0 && col < playColumns; row--, col++)
    {
      if (boardPositions[row][col].isRed())
      {
        n++;
        if (n == totalConnect)
        {
          gamestatus.setRedWon();
          return true;
        }
      }
      else
      {
        n = 0;
      }
    }
  }
  return false;
}

bool ConnectFour::redPlays(int col)
{
  if (gamestatus.yellowWon() || gamestatus.redWon() || gamestatus.fullBoard())
  {
    return false;
  }
  gamestatus.setInGame();
  if (col > playColumns || col <= 0)
  {
    return false;
  }
  for (int i = playRows - 1; i >= 0; i--)
  {
    if (boardPositions[col - 1][i].isFree())
    {
      boardPositions[col - 1][i].redPlays();
      if (redWins())
      {
        gamestatus.setRedWon();
      }
      if (boardFull())
      {
        gamestatus.setFullBoard();
      }

      return true;
    }
  }
  return false;
}

bool ConnectFour::boardFull()
{
  for (int i = 0; i < playRows; i++)
  {
    for (int j = 0; j < playColumns; j++)
    {
      if (boardPositions[i][j].isFree())
      {
        return false;
      }
    }
  }
  return true;
}

std::string ConnectFour::FixColor(std::string color)
{
  std::string FixedColor;

  std::transform(color.begin(), color.end(), color.begin(), ::tolower);
  while ((color != "red") && (color != "yellow"))
  {
    std::cout << "Sorry, that is not a valid color, please select red or yellow: " << std::endl;
    std::cin >> color;
    std::transform(color.begin(), color.end(), color.begin(), ::tolower);
  }

  if (color == "red")
  {
    FixedColor = "Red";
  }
  else if (color == "yellow")
  {
    FixedColor = "Yellow";
  }
  return FixedColor;
}

std::string ConnectFour::checkStart(std::string start)
{
  std::transform(start.begin(), start.end(), start.begin(), ::tolower);
  while (start != "yes" && start != "no")
  {
    std::cout << "Sorry, I do not understand, yes or no?" << std::endl;
    std::cin >> start;
    std::transform(start.begin(), start.end(), start.begin(), ::tolower);
  }
  return start;
}

void ConnectFour::whoStarts(std::string *start, std::string *color)
{
  if (*color == "Yellow")
  {
    player1.push_back("Yellow");
    player2.push_back("Red");
  }
  else if (*color == "Red")
  {
    player1.push_back("Red");
    player2.push_back("Yellow");
  }

  if (*start == "yes")
  {
    player1.push_back("yes");
    player2.push_back("no");
    std::cout << "Alright, player1 starts. Player1 has the color: " << player1[0] << std::endl;
  }
  else if (*start == "no")
  {
    player1.push_back("no");
    player2.push_back("yes");
    std::cout << "Alright, player2 starts. Player2 has the color: " << player2[0] << std::endl;
  }
}

void ConnectFour::printBoard()
{
  std::cout << "-------------------------------" << std::endl;
  for (int i = 0; i < playRows; i++)
  {
    for (int j = 0; j < playColumns; j++)
    {
      if (boardPositions[i][j].statereturn() == 0)
      {
        std::cout << "[ ]";
      }
      else if (boardPositions[i][j].statereturn() == 1)
      {
        std::cout << "[O]";
      }
      else if (boardPositions[i][j].statereturn() == 2)
      {
        std::cout << "[X]";
      }
    }
    std::cout << std::endl;
  }
  std::cout << "-------------------------------" << std::endl;
}

void ConnectFour::columnPlayCheck()
{
  int test = 0;
  std::cin >> columnPlay;
  while (columnPlay > playColumns || columnPlay <= 0)
  {
    std::cout << "Sorry, that is outside of the board, select another column\n> ";
    std::cin >> columnPlay;
  }
  columnPlay = columnPlay - 1;
  for (int i = playRows - 1; i >= 0; i--)
  {
    if (boardPositions[i][columnPlay].isFree())
    {
      test = 1;
      break;
    }
  }
  if (test == 0)
  {
    std::cout << "Sorry, this column is full already, please select another column\n> ";
    columnPlayCheck();
  }
}

void ConnectFour::play1()
{
  std::cout << "Player 1, " << player1[0] << ", your turn! Which column do you want to play?\n> ";
  columnPlayCheck();

  if (player1[0] == "Red")
  {
    for (int i = playRows - 1; i >= 0; i--)
    {
      if (boardPositions[i][columnPlay].isFree())
      {
        boardPositions[i][columnPlay].redPlays();
        break;
      }
    }
  }
  else if (player1[0] == "Yellow")
  {
    for (int i = playRows - 1; i >= 0; i--)
    {
      if (boardPositions[i][columnPlay].isFree())
      {
        boardPositions[i][columnPlay].yellowPlays();
        yellowWins();
        break;
      }
    }
  }
}

void ConnectFour::play2()
{
  std::cout << "Player 2, " << player2[0] << ", your turn! Which column do you want to play?\n> ";
  columnPlayCheck();

  if (player2[0] == "Red")
  {
    for (int i = playRows - 1; i >= 0; i--)
    {
      if (boardPositions[i][columnPlay].isFree())
      {
        boardPositions[i][columnPlay].redPlays();
        break;
      }
    }
  }
  else if (player2[0] == "Yellow")
  {
    for (int i = playRows - 1; i >= 0; i--)
    {
      if (boardPositions[i][columnPlay].isFree())
      {
        boardPositions[i][columnPlay].yellowPlays();
        yellowWins();
        break;
      }
    }
  }
}

GameStatus ConnectFour::getCurrentStatus() const
{
  return gamestatus;
}
