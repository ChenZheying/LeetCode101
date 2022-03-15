//
// Created by 陈哲英 on 2022/3/8.
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void backtracking(int n, int current_level, vector<string>& board, vector<vector<string>>& ans)
    {
        if(current_level == n) {
            ans.push_back(board);
            return;
        }
        string current_level_str(n,'.');

        for (int i = 0; i < n; ++i) {
            //if(i == current_level) {continue;}
            bool i_placeable = true;
            //使用一个循环探查此位置i可否放置Q
            for (int j = current_level-1; j >= 0; --j) {
                //判断i所在的这一列有没有Q，有的话改变i
                if(board[j][i] == 'Q') {
                    i_placeable = false;
                    break;
                }
                //当行、列的差值都一样时，表示在对角线上
                int temp_x = i - (current_level - j);
                //先探查左斜对角线
                if(temp_x >= 0 &&
                    board[j][temp_x] == 'Q') {
                    i_placeable = false;
                    break;
                }
                //探查右斜对角线上有没有Q
                temp_x = i + (current_level - j);
                if (temp_x < n &&
                    board[j][temp_x] == 'Q') {
                    i_placeable = false;
                    break;
                }
            }
            if(i_placeable) {
                current_level_str[i] = 'Q';
                board.push_back(current_level_str);
                backtracking(n, current_level+1, board, ans);
                current_level_str[i] = '.';
                board.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 1) {return {{"Q"}};}
        vector<string> board;
        vector<vector<string>> ans;
        backtracking(n, 0, board, ans);
        return ans;
    }
};
