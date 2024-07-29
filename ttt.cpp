/*
-- draw an ascii board filling it with the players inputs;
-- define each square as a three letter by three number combination -- array[];
-- that kind of combination will be the input's type;
-- compare, after each turn, the board with the 8 winning combinations.

*/
#include <iostream>
#include <cctype>
#include "board.hpp"

char board[3][3];
const int PLAYER1 = 1;
const int PLAYER2 = 2;

bool check_answer(char row) {
  if (row == 'A' || row == 'B' || row == 'C') {
    return true;
  } else {
    std::cout << "Invalid row value! Enter 'a', 'b' or 'c': ";
    return false;
  }
}

bool check_answer(int column) {
  if (column == 1 || column == 2 || column == 3) {
    return true;
  } else {
    std::cout << "Invalid column value! Enter 1, 2 or 3: ";
    return false;
  }
}


void ask_play(int player_turn) {
  char row;
  int column;

  std::cout << "PLAYER"<< player_turn << " enter the row of your play [A - C]: ";
  do {
    std::cin >> row;
    row = toupper(row);
  } while (!check_answer(row));  

}


int main() {
  bool win = false;
  int player_turn = PLAYER1;

  reset_board(board);

  while (!win) {
    print_board(board);
    ask_play(player_turn);

    win = true;
  }

  insert_play(PLAYER1, 1, 1, board);
  if (insert_play(PLAYER1, 1, 1, board)) {
    print_board(board);
  } else {
    std::cout << "ERROR: that tile is already taken\n";
  }
  

  return 0;
}