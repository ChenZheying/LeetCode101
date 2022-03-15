//
// Created by 陈哲英 on 2022/3/15.
//
#include <vector>
using namespace std;

class Solution {
public:
    //深度优先搜索，看最深的地方是不是边界
    void dfs (vector<vector<char>>& borad, int m, int n, int x, int y) {
        if(x < 0 || x >= m || y < 0 || y >= n) {return;}
        if(borad[x][y] == 'O') {
            borad[x][y]  = 'A';
        }
        else {
            return;
        }
        dfs(borad, m, n, x+1, y);
        dfs(borad, m, n, x-1, y);
        dfs(borad, m, n, x, y+1);
        dfs(borad, m, n, x, y-1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) {return;}
        int n = board[0].size();
        for(int x:{0,m-1}) {
            for (int y = 0; y < n; ++y) {
                if (board[x][y] == 'O') {
                    dfs(board, m, n, x, y);
                }
            }
        }
        for (int y: {0, n-1}) {
            for (int x = 1; x < m-1; ++x) {
                if (board[x][y] == 'O') {
                    dfs(board, m, n, x, y);
                }
            }
        }
        for (auto& vec:board) {
            for (char& c:vec) {
                if(c == 'A') {
                    c = 'O';
                }
                else if(c == 'O') {
                    c = 'X';
                }
            }
        }
        return;
    }
};