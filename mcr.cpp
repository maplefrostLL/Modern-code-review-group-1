
bool isWin(char game[3][3]){ 

bool win = false; 

if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true; 

else if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true; 

else if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true; 

// column 

else if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true; 

else if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true; 

else if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true; 

// diagonal 

else if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true; 

else if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true; 

return win; 

} 

 

int main(){ 

 int i, j; 

 char game[3][3] = {' '}; // Tic-tac-toe 

 char player1 = 'X'; 

 char player2 = 'O'; 

 bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first. 

 cout << "X = Player 1" << " " << "O = Player 2" << endl; 

 int numOfTurns = 1;

 for (int n=0; n<9; n++){ 

 turn = !turn;  // use the not-operator to change true to false or false to true. 

 if (!turn) 
  cout << "Player 1: "; 

 else 
  cout << "Player 2: "; 

 cout << "Which cell to mark? i:[0..2], j:[0..2]: "; 

 cin >> i >> j; 

  //check the user's input
  //user can only input number with value between 0 to 2
  //if the cell is already occupied, the user cannot choose that cell
 while((!(isDigit(i) && i <3 && i>=0) && !(isDigit(j) && j<3 && j>=0)) || (game[i][j]=='X' || game[i][j]=='O')){
  cout << "Your input is invalid. Please retry" << endl;
  cout << "Which cell to mark? i:[0..2], j:[0..2]: "; 
  cin >> i >> j; 
 }

 if (!turn) 
  game[i][j] = 'X'; 

 else  
  game[i][j] = 'O'; 

 if (isWin(game)){ 

  cout << "Win!" << endl; 

  break; // need to terminate the problem 

 } 

  numOfTurns++;

} 

 if (numOfTurns==9) // all cells with i=0 to 2 have been inputted above but no winner yet 

 cout << "Tie!" << endl; 

 // show the game to console 

 cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl; 

 cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl; 

 cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl; 

 return 0; 

} 

