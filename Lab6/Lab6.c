#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int deltaRowInput;
int deltaColInput;

//changes color to opponent color when called
char opponentColor(char color){
    if(color == 'B') return 'W';
    if(color == 'W') return 'B';
}

//checks if positions are in the bounds
bool positionInBoards(char board[][26], int n, char row, char col){
    if((row-'a')>=0 && (row-'a')<n && (col-'a')>=0 && (col-'a')<n)
        return true;
    return false;
}
//check if the move is valid
bool checkLegalInDirection(char board[][26], int n, char row, char col, char colour, int deltaRow, int deltaCol){
    int rowNum = row - 'a';
    int colNum = col - 'a';
    
        int sum = 0;
        bool stop = true;
        //if the original position is unoccupied
        if(board[rowNum][colNum]=='U'){
            
            if(board[rowNum+deltaRow][colNum+deltaCol]==opponentColor(colour) && board[rowNum+deltaRow*2][colNum+deltaCol*2] != 'U'){
                //checks how many opponent colors there are
                for(int multiplier = 1; multiplier * fabs(deltaRow) < n-1 , multiplier * fabs(deltaCol) < n-1, stop==true; multiplier++){
                    if(board[rowNum+deltaRow*multiplier][colNum+deltaCol*multiplier] == opponentColor(colour)){
                        sum++;
                    }
                    else 
                        stop = false;
                }

                    //if the color next to the last opponent color is the same as the origianl color then return true
                    if(board[rowNum+deltaRow*(sum+1)][colNum+deltaCol*(sum+1)]== colour){
                        return true;
                    }
                    else
                        return false;
                }
        
            else 
                return false;
        }
        //if its occupied return false
        else
            return false;
}
//set up the start board
void startBoard(char board[][26], int n){
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            board[row][col]='U';
        }
    }
    board[n/2-1][n/2-1]='W';
    board[n/2-1][n/2]='B';
    board[n/2][n/2-1]='B';
    board[n/2][n/2]='W';
}
//prints the board
void printBoard(char board[][26],int n){
    printf("  ");
    //prints the abcdef..
    for(int i=0;i<n;i++)
        printf("%c",'a'+i);
    printf("\n");
    //prints the vertical abcdef and the board
    for(int row=0; row<n; row++){
        printf("%c ", 'a'+row);
        for(int col=0; col<n; col++){
            printf("%c", board[row][col]);
         }
        printf("\n");
    }
    
    
}
//check if user input is valid
void userInputCheck(char board[][26], char colorInput, char rowInput, char colInput, int boardDimension){
    bool check = false;
    //check if its legal
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, -1, -1)) {
        deltaRowInput = -1; deltaColInput = -1; check = true;
    }
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, -1, 0)) {
        deltaRowInput = -1; deltaColInput = 0; check = true;
    }
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, -1, 1)) {
        deltaRowInput = -1; deltaColInput = 1; check = true;
    }
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 0, 1)) {
        deltaRowInput = 0; deltaColInput = 1; check = true;
    }
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 1, 1)) {
        deltaRowInput = 1; deltaColInput = 1; check = true;
    }
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 1, 0)) {
        deltaRowInput = 1;deltaColInput = 0; check = true;
    }
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 1, -1)) {
        deltaRowInput = 1; deltaColInput = -1; check = true;
    }
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 0, -1)) {
        deltaRowInput = 0; deltaColInput = -1; check = true;
    }
    int row = rowInput - 'a';
    int col = colInput - 'a';
    if(check){
        printf("Valid move.\n");
        board[row][col]=colorInput;
        bool stop = true;
        //count how money opponent colors there are and flip all those colors
        for(int multiplier = 1; multiplier * fabs(deltaRowInput) < boardDimension , multiplier * fabs(deltaColInput) < boardDimension, stop; multiplier++){
                    if(board[row+deltaRowInput*multiplier][col+deltaColInput*multiplier] == opponentColor(colorInput)){ 
                        board[row+deltaRowInput*multiplier][col+deltaColInput*multiplier] = colorInput;
                    }
                    else
                        stop = false;
        }
    }
    else
        printf("Invalid move.\n");
}

int main(int argc, char** argv) {
    int boardDimension;
    //prompt the user for the board dimension
    printf("Enter the board dimension: ");
    scanf("%d", &boardDimension);
    char board[26][26];
    startBoard(board,boardDimension);
    printBoard(board,boardDimension);
    //prompt the user to put in board configuration
    printf("Enter board configuration: \n");
    char userInput[3];
    while(userInput[0]!='!'){
        //scans the user input
        for(int i=0; i<3; i++){
            scanf(" %c", &userInput[i]);
        }
        
        int row = userInput[1] - 97;
        int col = userInput[2] - 97;
        
        board[row][col] = userInput[0];
    }
    printBoard(board,boardDimension);
    //for white
    printf("Available moves for W: \n");
    char color = 'W';
    bool legal, legalTwo, legalThree, legalFour, legalFive,legalSix, legalSeven, legalEight;
    //checks for legal moves one by one
    for(int i=0; i<boardDimension; i++){ //row
        for(int j=0; j<boardDimension;j++){ //col
            char row = i+'a';
            char col = j+'a';
            //checks for the legal moves one by one
            if(positionInBoards(board, boardDimension, row, col)){
                legal = checkLegalInDirection(board, boardDimension, row,col, color, -1, 0);
                legalTwo = checkLegalInDirection(board, boardDimension, row,col, color, -1, 1);
                legalThree = checkLegalInDirection(board, boardDimension, row,col, color, 0, 1);
                legalFour = checkLegalInDirection(board, boardDimension, row,col, color, 1, 1);
                legalFive = checkLegalInDirection(board, boardDimension, row,col, color, 1, 0);
                legalSix = checkLegalInDirection(board, boardDimension, row,col, color, 1, -1);
                legalSeven = checkLegalInDirection(board, boardDimension, row,col, color, 0, -1);
                legalEight = checkLegalInDirection(board, boardDimension, row,col, color, -1, -1);
                if(legal || legalTwo || legalThree || legalFour || legalFive || legalSix || legalSeven || legalEight)
                    printf(" %c%c \n", row, col);
            }
           }
    }
    printf("Available moves for B: \n");
    char color2 = 'B';
    //checks for legal moves one by one
    for(int i=0; i<boardDimension; i++){ //row
        for(int j=0; j<boardDimension;j++){ //col
            char row = i+'a';
            char col = j+'a';

                if(positionInBoards(board, boardDimension, row, col)){
                    legal = checkLegalInDirection(board, boardDimension, row,col, color2, -1, 0);
                    legalTwo = checkLegalInDirection(board, boardDimension, row,col, color2, -1, 1);
                    legalThree = checkLegalInDirection(board, boardDimension, row,col, color2, 0, 1);
                    legalFour = checkLegalInDirection(board, boardDimension, row,col, color2, 1, 1);
                    legalFive = checkLegalInDirection(board, boardDimension, row,col, color2, 1, 0);
                    legalSix = checkLegalInDirection(board, boardDimension, row,col, color2, 1, -1);
                    legalSeven = checkLegalInDirection(board, boardDimension, row,col, color2, 0, -1);
                    legalEight = checkLegalInDirection(board, boardDimension, row,col, color2, -1, -1);
                        if(legal || legalTwo || legalThree || legalFour || legalFive || legalSix || legalSeven || legalEight)
                            printf(" %c%c \n", row, col);
                }
           }
    }
     
    char moveInput[3];
    printf("Enter a move: \n");
    //asks the user to enter the move
    for(int i=0; i<3; i++){
            scanf(" %c", &userInput[i]);
        }
    char colorInput = userInput[0];
    char rowInput = userInput[1];
    char colInput = userInput[2];
    //call the func to check if its valid
    userInputCheck(board, colorInput, rowInput, colInput, boardDimension);
    //prints the board
    
    printBoard(board,boardDimension);
    
    
    return (EXIT_SUCCESS);
}


