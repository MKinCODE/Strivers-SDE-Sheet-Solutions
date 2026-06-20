#include<vector>
#include<string>
using namespace std;


//most optimal but too much space
class Solution {
private:
    vector<vector<string>> ans;
public:
    void recurse(vector<string>& board, int n, int row, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0; j<n; j++){
            if(board[row][j]=='.' && !col[j] && !diag1[row-j+n-1] && !diag2[row+j]){
                board[row][j]='Q';
                col[j]=true;
                diag1[row-j+n-1]=true;
                diag2[row+j]=true;
                recurse(board,n,row+1,col,diag1,diag2);
                board[row][j]='.';
                col[j]=false;
                diag1[row-j+n-1]=false;
                diag2[row+j]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<bool> col(n,false);
        vector<bool> diag1(2*n-1,false);
        vector<bool> diag2(2*n - 1, false);
        recurse(board,n,0,col,diag1,diag2);
        return ans;
    }
};

//less optimal still less extra space
class Solution {
private:
    vector<vector<string>> ans;
public:
    bool isSafe(vector<string>& board, int r, int c, int n){
        int x=r;
        int y=c;
        for(int i=0; i<r; i++){
            if(board[i][c]=='Q') return false;
        }
        r=x-1;c=y-1;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        r=x-1;c=y+1;
        while(r>=0 && c<n){
            if(board[r][c]=='Q') return false;
            r--;
            c++;
        }
        return true;
    }
    void recurse(vector<string>& board, int n, int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0; j<n; j++){
            if(board[row][j]=='.' && isSafe(board,row,j,n)){
                board[row][j]='Q';
                recurse(board,n,row+1);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        recurse(board,n,0);
        return ans;
    }
};