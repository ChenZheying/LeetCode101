//
// Created by 陈哲英 on 2022/3/3.
//
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> directions{-1,0,1,0,-1};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& can_reach_point, int r, int c) {
        if (can_reach_point[r][c]) {return;}
        can_reach_point[r][c] = true;
        int orig_height = heights[r][c];
        int x, y;
        for (int i = 0; i < 4; ++i) {
            x = r + directions[i], y = c + directions[i+1];
            if(x >= 0 && x < heights.size() &&
                y >= 0 && y< heights[0].size() &&
                heights[x][y] >= orig_height) {
                dfs(heights, can_reach_point, x, y);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //i=0,j=[0,n-1]和i=[1,m-1],j=0表示紧邻Pacific的点
        //i=m-1, j=[0,n-1]和i=[1,m-1],j=n-1表示紧邻Atlantic的点
        int m = heights.size();
        if(m == 0) {return {};}
        int n = heights[0].size();
        if(n==0) {return {};}
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(heights, can_reach_p, i, 0);
            dfs(heights, can_reach_a, i, n-1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, can_reach_p, 0, j);
            dfs(heights, can_reach_a, m-1, j);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(can_reach_a[i][j] && can_reach_p[i][j]) {
                    ans.push_back(vector<int>{i,j});
                }
            }
        }
        return ans;
    }
};