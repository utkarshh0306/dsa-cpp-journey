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

bool isSafe(vector<vector<char>> &Board , int row , int col){
    int n = Board.size() ;
    // horizontal check
    for(int i=0 ; i<n ; i++){
        if(Board[row][i] == 'Q'){
            return false;
        }
    }
    // vertical check
    for(int j=0 ; j<=row ; j++){
        if(Board[j][col] == 'Q'){
            return false;
        }
    }
    // left diagonally
    for(int i = row , j = col ; i>=0 && j>=0 ; i-- , j--){
        if(Board[i][j] == 'Q'){
            return false;
        }
    }
    // right diagonally
    for(int i = row , j = col ; i>=0 && j<n ; i-- , j++ ){
        if(Board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

int nQueens(vector<vector<char>> &Board , int row){
    int n = Board.size() ;
    int count = 0;
    if(row == n){
        printBoard(Board);
        return 1 ;
    }

    // columns
    for(int i=0 ; i<n ; i++){
        if(isSafe(Board , row , i)){
            Board[row][i] = 'Q' ;
            count += nQueens(Board , row+1);
            // backtracking
            Board[row][i] = '.' ;
        }
    }
    return count;
}
int main(){
    vector<vector<char>> Board ;
    int n = 4;
    for(int i=0 ; i<n ; i++){
        vector<char> newRow ;
        for(int j=0 ; j<n ; j++){
            newRow.push_back('.');
        }
        Board.push_back(newRow);
    }
    cout<<"No of total ways : "<<nQueens(Board , 0);

    return 0;
}