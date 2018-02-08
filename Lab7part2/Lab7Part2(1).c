#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "lab7part2lib.h"

//changes color to opponent color when called
int findSmartestMove(char board[][26],int n, char colour, int *row2, int *col2);
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
    int rowNum = row - 'a' + deltaRow;
    int colNum = col - 'a' + deltaCol;
   // bool test = false;
    
      //  int sum = 0;
        //bool stop = true;
        //if the original position is unoccupied
        if(board[row - 'a'][col - 'a']=='U' && board[rowNum][colNum] == opponentColor(colour) ){
            while(board[rowNum][colNum] != colour && positionInBoards(board,n, rowNum + 'a', colNum + 'a')) {
                rowNum += deltaRow;
                colNum += deltaCol;
                if (board[rowNum][colNum] == colour && positionInBoards(board,n, rowNum + 'a', colNum + 'a'))
                    return true;
                if (board[rowNum][colNum] == 'U' && positionInBoards(board,n, rowNum + 'a', colNum + 'a'))
                    return false;
            }
            return false;
        }
        
        else
            return false;
}
//set up the start board
bool isLegalMove(char board[][26],int n, char row,char col,char comColor){
    bool legal, legalTwo, legalThree, legalFour, legalFive,legalSix, legalSeven, legalEight;
    
    legal = checkLegalInDirection(board, n, row,col, comColor, -1, 0);
    legalTwo = checkLegalInDirection(board, n, row,col, comColor, -1, 1);
    legalThree = checkLegalInDirection(board, n, row,col, comColor, 0, 1);
    legalFour = checkLegalInDirection(board, n, row,col, comColor, 1, 1);
    legalFive = checkLegalInDirection(board, n, row,col, comColor, 1, 0);
    legalSix = checkLegalInDirection(board, n, row,col, comColor, 1, -1);
    legalSeven = checkLegalInDirection(board, n, row,col, comColor, 0, -1);
    legalEight = checkLegalInDirection(board, n, row,col, comColor, -1, -1);
    //if either one is legal then return true
    if(legal || legalTwo || legalThree || legalFour || legalFive || legalSix || legalSeven || legalEight)
        return true;
    else
        return false;
}
//check if either side has any legal move left
bool validMoveLeft(char board[][26],int n,char comColor){
    bool valid = false;
    char row,col;
    for(int i=0; i<n; i++){ //row
                  for(int j=0; j<n;j++){ //col
                         row = i+'a';
                         col = j+'a';
                  if(positionInBoards(board, n, row, col) )
                    if(isLegalMove(board, n, row,col, comColor))
                        valid = true;
                    }
    }
    return valid;
}
//set up the starter board
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
//flips the board whenever its called
void flipBoard(int deltaRowInput, int deltaColInput, int boardDimension, char rowInput, char colInput, char colorInput, char board[][26]){
    
    board[rowInput - 'a'][colInput - 'a']=colorInput;
    int row = rowInput - 'a' + deltaRowInput;
    int col = colInput - 'a' + deltaColInput;
    //keep fliping the opponent color
    while (board[row][col] == opponentColor(colorInput)) {
        board[row][col] = colorInput;
        row += deltaRowInput;
        col += deltaColInput;
    }
}

//check if user input is valid
bool userInputCheck(char board[][26], char colorInput, char rowInput, char colInput, int boardDimension){
    bool check = false;
    bool legal = checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, -1, 0);
    bool legalTwo = checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, -1, 1);
    bool legalThree = checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 0, 1);
    bool legalFour = checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 1, 1);
    bool legalFive = checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 1, 0);
    bool legalSix = checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 1, -1);
    bool legalSeven = checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 0, -1);
    bool legalEight = checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, -1, -1);
    //check if its legal
    if(legal)
        flipBoard(-1,0, boardDimension,rowInput,colInput, colorInput, board);
    if(legalTwo)
        flipBoard(-1, 1, boardDimension,rowInput,colInput, colorInput, board);
    if(legalThree)
        flipBoard(0, 1, boardDimension,rowInput,colInput, colorInput, board);
    if(legalFour) 
        flipBoard(1, 1, boardDimension,rowInput,colInput, colorInput, board);
    if(legalFive)
        flipBoard(1, 0, boardDimension,rowInput,colInput, colorInput, board);
    if(legalSix)
        flipBoard(1, -1, boardDimension,rowInput,colInput, colorInput, board);
    if(legalSeven)
        flipBoard(0, -1, boardDimension,rowInput,colInput, colorInput, board);
    if(legalEight)
        flipBoard(-1, -1, boardDimension,rowInput,colInput, colorInput, board);
    
    
    if(legal || legalTwo || legalThree || legalFour || legalFive || legalSix || legalSeven || legalEight)
        return true;
    else
        return false;
    
}
//calculate how many opponent it can flip
int scorePlus(int deltaRowInput, int deltaColInput, int boardDimension, char rowInput, char colInput, char colorInput, char board[][26]){
   // int deltaRowInput, deltaColInput;
    int row = rowInput - 'a' + deltaRowInput;
    int col = colInput - 'a' + deltaColInput;
    //int corner = boardDimension - 1;
    int score = 0;
    
    while (board[row][col] == opponentColor(colorInput)) {
        score++;
        row += deltaRowInput;
        col += deltaColInput;
    }
    //return the score times five
    return 5*score;
    
}
//since certain positions have different weights
int weightOfTheBoard(char board[][26], char rowInput, char colInput, int n){
    int row = rowInput - 'a';
    int col = colInput - 'a';
    int corner = n-1;
    int bad = n - 2;
    int good = n - 3;
    int weight = 0;
    if(n > 4){
        if(board[row][col]=='U'){
            //if the position is corner then weight is set as 100
            if((row == 0 && col == 0) || (row == corner && col ==0) || (row == 0 && col == corner) || (row == corner && col == corner))
                weight = 100;
            //if the position is ryt besde corner then the weight is -20
            if((row == 0 && col == 1) || (row == 0 && col == bad) || (row == 1 && col == 0) || (row == 1 && col == corner) || (row == bad && col == 0) ||(row == bad && col == corner) || (row == corner && col == 1) || (row == corner && col == bad))
                weight = -20;
            //it the position is two moves away from corner then weight is 20
            if((row == 2 && col == 0) || (row == 2 && col == corner) || (row == good && col == 0) || (row == good && col == corner))
                weight = 20;
            //if its the corner of the inner squre then its the worst move
            if((row == 1 && col == 1) || (row == 1 && col == bad) || (row == bad && col == 1) || (row == bad && col == bad))
                weight = -40;
            //if its the inner squares without the corners then weight is set up as -10
            for(int i = 2; i<good;i++){
                if((row ==1 && col == i)||(row == bad && col == i)||(row == i && col == 1)||(row == i && col == bad))
                    weight = -10;
            }
        }
    }
    //n*n is another case only consider the corner cases
    if(n=4){
        if((row == 0 && col == 0) || (row == corner && col ==0) || (row == 0 && col == corner) || (row == corner && col == corner))
                weight = 100;
    }
    
    return weight;
}
//score calculation adds the weight and opponent flip points together
int scoreCalculation(char board[][26], char colorInput, char rowInput, char colInput, int boardDimension){
    int score = 0;
    int weight = weightOfTheBoard(board,rowInput,colInput,boardDimension);
    //check if its legal
    score += weight;
    //check every single direction and add the score that it can flip
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, -1, -1)) 
        score += scorePlus(-1, -1, boardDimension,rowInput,colInput, colorInput, board);
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, -1, 0)) 
        score += scorePlus(-1, 0, boardDimension,rowInput,colInput, colorInput, board);
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, -1, 1))
        score += scorePlus(-1, 1, boardDimension,rowInput,colInput, colorInput, board);
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 0, 1)) 
        score += scorePlus(0, 1, boardDimension,rowInput,colInput, colorInput, board);
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 1, 1)) 
        score += scorePlus(1, 1, boardDimension,rowInput,colInput, colorInput, board);
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 1, 0)) 
        score += scorePlus(1, 0, boardDimension,rowInput,colInput, colorInput, board);
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 1, -1)) 
        score += scorePlus(1, -1, boardDimension,rowInput,colInput, colorInput, board);
    if(checkLegalInDirection(board, boardDimension, rowInput,colInput, colorInput, 0, -1))
        score += scorePlus(0, -1, boardDimension,rowInput,colInput, colorInput, board);
    
    return score;
    
}


//final score calculates how many pieces each side has
int getFinalScore(char board[][26],int n,char comColor){
    int score = 0;
    for(int i=0; i<n; i++){ //row
        for(int j=0; j<n;j++){ //col
            if(board[i][j]==comColor)
                score++;
        }
    }
    return score;
}

/*void computerMove(char board[][26], char color, int n){
    char row,col;
    char copyBoard[n][n];
    for(int i=0; i<n; i++){ //row
        for(int j=0; j<n;j++){ //col
            row = i+'a';
            col = j+'a';
            if(positionInBoards(board, n, row, col) ){
                if(isLegalMove(board, n, row,col, color)){
                    
            }
        }   
        }
    }
}*/

int main(int argc, char** argv) {
    int boardDimension;
    //prompt the user for the board dimension
    printf("Enter the board dimension: ");
    scanf("%d", &boardDimension);
    char board[26][26];
    startBoard(board,boardDimension);
    //asks the user if the computer is to be the Black or WHite player (black player always gets the first move)
    char comColor;
    char userColor;
    char userInput[2];
  
    printf("Computer plays (B/W) : ");
    scanf(" %c", &comColor);
    printBoard(board,boardDimension);
    
    userColor=opponentColor(comColor); 
    bool done = false;
  
    char rowCom,colCom;
    int scoreOne = 0;
    int scoreTwo = -40;
    char row,col;
    int row2,col2;
    //if computer moves first
    if(comColor=='B'){
        char rowFirst=boardDimension/2-2+'a';
        char colFirst=boardDimension/2-1+'a';
        
        printf("Computer places %c at %c%c.\n",comColor, rowFirst, colFirst);
        userInputCheck(board, comColor, rowFirst, colFirst,boardDimension);
        printBoard(board,boardDimension);
    }
    
    do{
        //check if theres any valid move left
        if(validMoveLeft(board,boardDimension,userColor)){
            //printf("Enter move for colour %c (RowCol): ",userColor);
            findSmartestMove(board,boardDimension,userColor, &row2, &col2);
            printf("AI plays at %c%c\n", row2+'a',col2+'a');
            //if the positionis valid then print the position and the board
            if(userInputCheck(board, userColor, row2+'a',col2+'a',boardDimension))
                printBoard(board,boardDimension);
            //if its not valid then ends the game
            else{
                printf("Invalid move.\n%c player wins.", comColor);
                done = true;
            }
        }
        //if theres no legal move left
        else if(!validMoveLeft(board,boardDimension,userColor) && done == false)
            printf("%c player has no valid move.\n", userColor);
        else if(!validMoveLeft(board,boardDimension,comColor) && done == false)
                printf("%c player has no valid move.\n", comColor);
       
        
        if(!done){
            //checks every single position and finds the best move based on my score calculation
            for(int i=0; i<boardDimension; i++){ //row
                  for(int j=0; j<boardDimension;j++){ //col
                         row = i+'a';
                         col = j+'a';
                   //it is in bound      
                  if(positionInBoards(board, boardDimension, row, col) ){
                      //if its legal then start score calculation
                    if(isLegalMove(board, boardDimension, row,col, comColor)){
                         scoreOne = scoreCalculation(board, comColor, row, col, boardDimension);
                       //always replace the lower score position with the higher score position
                        if(scoreOne > scoreTwo){
                            rowCom = row;
                            colCom = col;
                            scoreTwo = scoreOne;
                        }
                    }
                  }
                }
            }
            
            scoreTwo = -40;
            //prints the computer move 
            if(validMoveLeft(board,boardDimension,comColor) && board[rowCom][colCom]!='U'){
                printf("Computer places %c at %c%c.\n",comColor, rowCom, colCom);
                userInputCheck(board, comColor, rowCom, colCom,boardDimension);
                printBoard(board,boardDimension);
            }
            //if theres no valid move left for both sides then ends the game
            if(!validMoveLeft(board,boardDimension,comColor) && !validMoveLeft(board,boardDimension,userColor))
            done = true;
            else if(!validMoveLeft(board,boardDimension,comColor) && done == false)
                printf("%c player has no valid move.\n", comColor);
        }
        //if theres no valid move left for both sides then ends the game
        if(!validMoveLeft(board,boardDimension,comColor) && !validMoveLeft(board,boardDimension,userColor))
            done = true;
    }while(!done);
    int comScore,userScore;
    comScore = getFinalScore(board,boardDimension,comColor);
    userScore = getFinalScore(board,boardDimension,userColor);
 
        if(comScore>userScore)
            printf("%c player wins.", comColor);
        if(userScore>comScore)
            printf("%c player wins.", userColor);
        if(userScore==comScore)
            printf("Draw!");
    return (EXIT_SUCCESS);
}
