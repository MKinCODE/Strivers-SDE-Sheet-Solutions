#include<vector>
using namespace std;

class Solution {
public:
    bool isSafe(int r, int c, int digit, vector<vector<char>>& board){
        for(int j=0; j<9; j++){
            if(board[r][j]==digit+'0') return false;
        }
        for(int i=0; i<9; i++){
            if(board[i][c]==digit+'0') return false;
        }
        int sr=(r/3)*3;
        int sc=(c/3)*3;
        for(int i= sr; i<sr+3; i++){
            for(int j=sc; j<sc+3; j++){
                if(board[i][j]==digit+'0') return false;
            }
        }
        return true;
    }
    bool recurse(int idx, vector<vector<char>>& board, vector<pair<int,int>>& arr){
        if(idx==arr.size()) return true;
        int i=arr[idx].first;
        int j=arr[idx].second;
        for(int k=1;k<=9;k++){
            if(isSafe(i,j,k,board)){
                board[i][j]=k+'0';
                if(recurse(idx+1,board,arr)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> arr;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') arr.push_back({i,j});
            }
        }
        recurse(0,board,arr);
    }
};