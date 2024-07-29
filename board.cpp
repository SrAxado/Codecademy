#include <iostream>

const char P1_SYMBOL = 'X';
const char P2_SYMBOL = 'O';

char symbol(int num_player) {
  return num_player == 1 ? P1_SYMBOL : P2_SYMBOL;
}

void reset_board(char board[3][3], char symbol) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = symbol;
    }
  }
}

void print_board(char board[3][3]) {
  std::cout << "\n         1           2           3\n";
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

bool insert_play(int num_player, int play[2], char board[3][3]) {
  if (board[play[0]][play[1]] == ' ') {
    board[play[0]][play[1]] = symbol(num_player);
    return true;
  } else {
    std::cout << "\nERROR: that tile is already taken. Try again!\n";
    return false;
  }
}

/* scans the winning_boards for elements and compares each element with the game board
  -- if comparison fails set "win" to false;
  -- if by the end of the scan "win" is still true, then it's we have a winner!!!
*/
bool check_winning_board(int player, char board[3][3], char winning_board[3][3]) {
  bool win = true;
  for (int i = 0; i < 3; i++) {
    if (!win) break;

    for (int j = 0; j < 3; j++) {
      //std::cout << "--> [" << i << "][" << j << "] -- " << winning_board[i][j] << " <-> " << board[i][j] << "\n";
      if (winning_board[i][j] != '*') {
        continue;
      }  // skips to the next tile if empty
      //std::cout << "--> [" << i << "][" << j << "] -- " << winning_board[i][j] << " <-> " << board[i][j] << "\n";
      
      if (board[i][j] != symbol(player)) {
        //std::cout << "Not a winning board: \n";
        //std::cout << "[" << i << "][" << j << "] -- " << winning_board[i][j] << " <-> " << board[i][j] << "\n";
        win = false;
        break;
      } else {
        //std::cout << "==> [" << i << "][" << j << "] -- " << winning_board[i][j] << " <-> " << board[i][j] << "\n";
        win = true;
      }
    }
  }
/*
  if (winning_board == board) {
    std::cout << "It's the same board\n";
  } else {
    std::cout << "You wished!!\n";
  }
  print_board(winning_board1);
*/
  //std::cout << "=-> " << win << "\n\n";
  return win;  
}


bool check_win(int player, char board[3][3]) {
    //char winning_board1[3][3] = {'O', 'X', 'X', 'O', 'X', 'X'};
  //char winning_board1[3][3] = {'*', '*', '*'};
  char winning_board1[3][3];
  //reset_board(winning_board1, '\0');
  winning_board1[0][0] = '*';
  winning_board1[0][1] = '*';
  winning_board1[0][2] = '*';
  //char winning_board2[3][3] = {NULL, NULL, NULL, '*', '*', '*'};
  char winning_board2[3][3];
  winning_board2[1][0] = '*';
  winning_board2[1][1] = '*';
  winning_board2[1][2] = '*';
  //char winning_board3[3][3] = {NULL, NULL, NULL, NULL, NULL, NULL, '*', '*', '*'};
  char winning_board3[3][3];
  winning_board3[2][0] = '*';
  winning_board3[2][1] = '*';
  winning_board3[2][2] = '*';
  //char winning_board4[3][3] = {'*', NULL, NULL, '*', NULL, NULL, '*'};
  char winning_board4[3][3];
  winning_board4[0][0] = '*';
  winning_board4[1][0] = '*';
  winning_board4[2][0] = '*';
  char winning_board5[3][3]; // = {NULL, '*', NULL, NULL, '*', NULL, NULL, '*', NULL};
  //reset_board(winning_board5, '\0');
  winning_board5[0][1] = '*';
  winning_board5[1][1] = '*';
  winning_board5[2][1] = '*';
  char winning_board6[3][3];
  winning_board6[0][2] = '*';
  winning_board6[1][2] = '*';
  winning_board6[2][2] = '*';
  char winning_board7[3][3];
  winning_board7[0][0] = '*';
  winning_board7[1][1] = '*';
  winning_board7[2][2] = '*';
  char winning_board8[3][3];
  winning_board8[0][2] = '*';
  winning_board8[1][1] = '*';
  winning_board8[2][0] = '*';

  if (check_winning_board(player, board, winning_board1) ||
      check_winning_board(player, board, winning_board2) ||
      check_winning_board(player, board, winning_board3) ||
      check_winning_board(player, board, winning_board4) ||
      check_winning_board(player, board, winning_board5) ||
      check_winning_board(player, board, winning_board6) ||
      check_winning_board(player, board, winning_board7) ||
      check_winning_board(player, board, winning_board8))
    {
      return true;
    } else {
      return false;
    }
}