/*
-- draw an ascii board filling it with the players inputs;
-- define each square as a three letter by three number combination -- array[];
-- that kind of combination will be the input's type;
-- compare, after each turn, the board with the 8 winning combinations.

*/
#include <iostream>
#include <cctype>
#include "board.hpp"

char board[3][3]; // = {'O', 'X', 'X', 'O', 'X', ' '};
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


void ask_play(int player_turn, int play[2]) {
  char row;
  int column;

  std::cout << "--- PLAYER"<< player_turn << " ---\n";
  do {
    std::cout << "Enter the row of your play [A - C]: ";
    do {
        std::cin >> row;
        row = toupper(row);
    } while (!check_answer(row));

    std::cout << "Enter the column of your play [1 - 3]: ";
    do {
        std::cin >> column;
    } while (!check_answer(column));

    if (row == 'A') {
        play[0] = 0;
    } else if (row == 'B') {
        play[0] = 1;
    } else {
        play[0] = 2;
    }
    play[1] = column - 1;

  } while (!insert_play(player_turn, play, board));

}


int main() {
  int player_turn;
  int turn = 0;
  int play[2];

  reset_board(board, ' ');
  print_board(board);

  do {
    turn++;
    //std::cout << "### TURN " << turn << "\n";
    
    if (!player_turn) {
      player_turn = PLAYER1;
    } else {
      player_turn = (player_turn == PLAYER1 ? PLAYER2 : PLAYER1); // swap player
    }    

    ask_play(player_turn, play);
    print_board(board);

    if (check_win(player_turn, board)) {
      turn = 0;
      break;
    }

  } while (turn < 9);

  if (turn == 0) {
    std::cout << "WELL DONE, PLAYER" << player_turn << "! YOU WON!!!!\n\n";
  } else {
    std::cout << "That was a tie! Well played.\nDo you want to play again?\n";
  }

  return 0;
}