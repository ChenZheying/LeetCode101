//
// Created by 陈哲英 on 2022/3/7.
//

#include <vector>
#include <string>
using namespace std;
class Solution {
public:

    vector<int> directions{-1,0,1,0,-1};
    bool backtracking(vector<vector<char>>& board, vector<vector<bool>>& checked,
                      int m, int n,
                      string word, int level,
                      pair<int,int> last_pos) {
        if(level == word.size()) {
            return true;
        }
        int x, y;
        char required = word[level];
        bool result = false;
        for (int j = 0; j < 4; ++j) {
            x = last_pos.first + directions[j], y = last_pos.second + directions[j+1];
            if(x >= 0 && x < m &&
                y >= 0 && y < n &&
                board[x][y] == required &&
                checked[x][y] == false) {
                checked[x][y] = true;
                bool flag = backtracking(board, checked, m, n, word, ++level, {x,y});
                if (flag) {
                    result = true;
                    break;
                }
                checked[x][y] = false;
                --level;
            }
        }
        //checked.resize(m, vector<bool>(n,false));
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0) {return false;}
        int n = board[0].size();
        if (n == 0) {return false;}
        vector<vector<bool>> checked(m, vector<bool>(n,0));
        char first_char = word[0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(board[i][j]==first_char) {
                    checked[i][j] = true;
                    bool result = backtracking(board, checked, m, n, word, 1, {i,j});
                    if(result) {
                        return true;
                    }
                    checked[i][j] = false;
                }
            }
        }
        return false;
    }
};