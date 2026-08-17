#include<iostream>
using namespace std;

void printSudoku(int sudoku[9][9]){
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int sudoku[9][9], int row , int col , int digit){
    // virtical
    for(int i=0 ; i<9 ; i++){
        if(sudoku[i][col] == digit){
            return false;
        }
    }
    // horizontal
    for(int j=0 ; j<9 ; j++){
        if(sudoku[row][j] == digit){
            return false;
        }
    }
    // 3*3 grid
     int startRow = (row/3)*3;
     int startCol = (col/3)*3;

     for(int i=startRow ; i<startRow+3 ; i++){
        for(int j=startCol ; j<startCol+3 ; j++){
            if(sudoku[i][j]==digit){
                return false;
            }
        }
     }
     return true;
}

bool sudokuSolver(int sudoku[9][9] , int row , int col){
    // base case
    if(row == 9){
        printSudoku(sudoku);
        return true;
    }

    int nextRow = row;
    int nextcol = col+1 ;
    // if col reach last of col
    if(col+1 == 9){
        nextRow = row+1 ;
        nextcol = 0 ;
    }
    // if element or digit already present
    if(sudoku[row][col] != 0){
        return sudokuSolver(sudoku , nextRow , nextcol );
    }
    // main entering digit
    
    for(int digit=1 ; digit<=9 ; digit++){
        if(isSafe(sudoku , row , col , digit)){
            sudoku[row][col]=digit;
            if(sudokuSolver(sudoku , nextRow , nextcol)){
                return true;
            }
            sudoku[row][col]=0;
        }
    }
    return false;
}

int main(){
    int sudoku[9][9] = {{0,0,8,0,0,0,0,0,0},
                        {4,9,0,1,5,7,0,0,2},
                        {0,0,3,0,0,4,1,9,0},
                        {1,8,5,0,6,0,0,2,0},
                        {0,0,0,0,2,0,0,6,0},
                        {9,6,0,4,0,5,3,0,0},
                        {0,3,0,0,7,2,0,0,4},
                        {0,4,9,0,3,0,0,5,7},
                        {8,2,7,0,0,9,0,1,3}};
    sudokuSolver(sudoku , 0 , 0);
    return 0;
}