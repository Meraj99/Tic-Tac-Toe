//WORK IN PROGRESS!
#include <iostream>
#include <cstdlib>

int AddSymbol(char Board[3][3], char Symbol, int Row, int Column);
char DetectWin(char Board[3][3]);
bool checkX(char b[3][3], int row, int col, int dr, int dc);
bool checkO(char b[3][3], int row, int col, int dr, int dc);

int main() {

    char GameBoard[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
    };

    int SelectedRow, SelectedColumn;
    int InvalidInput;
    char winner;

    int turn = 0;

    int SeparatorsPrinted = 0;
    while(true){
        SeparatorsPrinted = 0;
        for(int i = 0; i != 3; i++){ // Print game board
            for(int j = 0; j != 3; j++){
                std::cout << GameBoard[i][j] << " | ";
            }
            std::cout << std::endl;

            if(SeparatorsPrinted != 2)
                std::cout << "-------------" << std::endl;
            else {
                std::cout << "© Meraj Ahmed" << std::endl;
                std::cout << std::endl;
            }
            SeparatorsPrinted++;
        }

        if(turn % 2 == 0) { // Check which player's turn it is, and prompt the player to play his turn
            std::cout << "You are X. Enter row and column number, one at a time." << std::endl;
            std::cin >> SelectedRow >> SelectedColumn;
            InvalidInput = AddSymbol(GameBoard, 'X', SelectedRow, SelectedColumn); // Adds symbol to the game board. If spot is occupied,
            if(InvalidInput == 1) continue;
            winner = DetectWin(GameBoard);
        }
        else{
            std::cout << "You are O. Enter row and column number, one at a time." << std::endl;
            std::cin >> SelectedRow >> SelectedColumn;
            InvalidInput = AddSymbol(GameBoard, 'O', SelectedRow, SelectedColumn);
            if(InvalidInput == 1) continue;
            winner = DetectWin(GameBoard);
        }

        if(winner == 'X'){ // If X has won, exit
            std::cout << "Congratulations! X has won!" << std::endl;
            system("pause");
            return 0;
        }
        if(winner == 'O'){ // If O has won, exit
            std::cout << "Congratulations! O has won!" << std::endl;
            system("pause");
            return 0;
        }
        system("cls");
        turn++;
    }
}

int AddSymbol(char Board[3][3], char Symbol, int Row, int Column){

    Row -= 1;
    Column -= 1;

    if(Symbol == 'X'){
        if(Board[Row][Column] == ' ')
            Board[Row][Column] = 'X';
        else {
            std::cout << "Sorry, that spot is not empty." << std::endl;
            system("pause");
            system("cls");
            return 1;
        }
    }
    if(Symbol == 'O'){
        if(Board[Row][Column] == ' ')
            Board[Row][Column] = 'O';
        else {
            std::cout << "Sorry, that spot is not empty." << std::endl;
            system("pause");
            system("cls");
            return 1;
        }
    }

    return 0;
}

char DetectWin(char Board[3][3]){
    bool hasWinX = checkX(Board, 0, 0, 0, 1) // First horizontal line
                  || checkX(Board, 1, 0, 0, 1) // Second horizontal line
                  || checkX(Board, 2, 0, 0, 1) // Third horizontal line
                  || checkX(Board, 0, 0, 1, 0) // First vertical line
                  || checkX(Board, 0, 1, 1, 0) // Second vertical line
                  || checkX(Board, 0, 2, 1, 0) // Third vertical line
                  || checkX(Board, 0, 0, 1, 1) // First diagonal
                  || checkX(Board, 0, 2, 1, -1); // Second diagonal

    bool hasWinO = checkO(Board, 0, 0, 0, 1) // First horizontal line
                  || checkO(Board, 1, 0, 0, 1) // Second horizontal line
                  || checkO(Board, 2, 0, 0, 1) // Third horizontal line
                  || checkO(Board, 0, 0, 1, 0) // First vertical line
                  || checkO(Board, 0, 1, 1, 0) // Second vertical line
                  || checkO(Board, 0, 2, 1, 0) // Third vertical line
                  || checkO(Board, 0, 0, 1, 1) // First diagonal
                  || checkO(Board, 0, 2, 1, -1); // Second diagonal

    if(hasWinX){
        return 'X';
    }
    if(hasWinO){
        return 'O';
    }
    return ' ';
}

bool checkX(char b[3][3], int row, int col, int dr, int dc) {
    if((b[row][col] == 'X') && (b[row][col] == b[row+dr][col+dc]) && (b[row][col] == b[row+2*dr][col+2*dc]))
        return true;
    return false;
}

bool checkO(char b[3][3], int row, int col, int dr, int dc) {
    if((b[row][col] == 'O') && (b[row][col] == b[row+dr][col+dc]) && (b[row][col] == b[row+2*dr][col+2*dc]))
        return true;
    return false;
}