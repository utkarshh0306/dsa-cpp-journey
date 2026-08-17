#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>> Board){        
    int n = Board.size() ;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout<<Board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------------"<<endl;
}

void nQueens(vector<vector<char>> &Board , int row){
    int n = Board.size() ;
    if(row == n){
        printBoard(Board);
        return ;
    }

    // columns
    for(int i=0 ; i<n ; i++){
        Board[row][i] = 'Q' ;
        nQueens(Board , row+1);
        // backtracking
        Board[row][i] = '.' ; 
    }
}
int main(){
    vector<vector<char>> Board ;
    int n = 2;
    for(int i=0 ; i<n ; i++){
        vector<char> newRow ;
        for(int j=0 ; j<n ; j++){
            newRow.push_back('.');
        }
        Board.push_back(newRow);
    }
    nQueens(Board , 0);
    return 0;
}