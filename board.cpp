#include <iostream>

const char P1_SYMBOL = 'X';
const char P2_SYMBOL = 'O';

void reset_board(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

void print_board(char board[3][3]) {
  std::cout << "         1           2           3\n";
  std::cout << "   # = = = = = = = = = = = = = = = = = #\n";
  std::cout << "   |           |           |           |\n";
  std::cout << "A  |     " << board[0][0] << "     |     " << board[0][1] << "     |     " << board[0][2] << "     |\n";
  std::cout << "   |           |           |           |\n";
  std::cout << "   + - - - - - - - - - - - - - - - - - +\n";
  std::cout << "   |           |           |           |\n";
  std::cout << "B  |     " << board[1][0] << "     |     " << board[1][1] << "     |     " << board[1][2] << "     |\n";
  std::cout << "   |           |           |           |\n";
  std::cout << "   + - - - - - - - - - - - - - - - - - +\n";
  std::cout << "   |           |           |           |\n";
  std::cout << "C  |     " << board[2][0] << "     |     " << board[2][1] << "     |     " << board[2][2] << "     |\n";
  std::cout << "   |           |           |           |\n";
  std::cout << "   # = = = = = = = = = = = = = = = = = #\n\n";
}

bool insert_play(int num_player, int row, int column, char board[3][3]) {
  if (board[row][column] == ' ') {
    board[row][column] = num_player == 1 ? P1_SYMBOL : P2_SYMBOL;
    return true;
  } else {
    return false;
  }
}