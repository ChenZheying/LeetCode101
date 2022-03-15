//
// Created by 陈哲英 on 2022/3/8.
//
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> directions{-1,0,1,0,-1};
    void dfs(vector<vector<int>>& grid, int m, int n, int x, int y) {
        if(x<0 || x>=m || y<0 || y >=n ||grid[x][y] != 1) {
            return;
        }
        grid[x][y] = 2;
        dfs(grid, m, n, x+1, y);
        dfs(grid, m, n, x-1, y);
        dfs(grid, m, n, x, y+1);
        dfs(grid, m, n, x, y-1);
    }
    //grid二维数组：1代表陆地，0代表海洋，2代表此位置已经探查、并保存了其dist
    //dist二维数组：表示整个区域中各个位置与陆地的最近距离
    //queue队列：存储保存了dist的位置
    //思路：1.利用dfs算法，将首次搜索到的岛屿grid全部更新为2，dist全部更新为0，保存其位置到queue
        // 2.利用队列queue实现广度优先遍历，搜索
        //      与目前队列中保存的位置距离是1的地方是否有别的小岛（标识为其grid为1）
        //      搜索过的地方持续的更新其dist和grid，并将位置存入queue中
        //      这样一来，最开始queue中存储的位置都是第一块儿陆地所在的位置，如果都搜寻了一遍，
        //      距离为1的地方都没有另一块儿陆地，那么就会从队列中依次取出与原来陆地距离为1的位置进行距离为1的探寻，
        //      即探寻与原来陆地距离为2的位置是否有陆地
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        bool flag = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //找到第一个陆地之后进入dfs，将这块儿岛的所有陆地都保存
                if(grid[i][j] == 1) {
                    dfs(grid,m,n,i,j);
                    //再也不需要循环了，只有两个岛屿
                    flag = true;
                    break;
                }
            }
            if (flag) {break;}
        }
        //初始化三个容器
        queue<pair<int, int>> que_pos;
        vector<vector<int>> dist(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    que_pos.emplace(i,j);
                    dist[i][j] = 0;
                }
            }
        }
        //BFS的终止条件当然是队列为空
        while(!que_pos.empty()) {
            pair<int,int> f = que_pos.front();
            que_pos.pop();
            for (int i = 0; i < 4; ++i) {
                int x = f.first + directions[i], y = f.second + directions[i+1];
                //探查的地方超出边界或者是已探查过的了，就探查下一个地方
                if( x<0 || x>=m || y<0 || y>=n || grid[x][y] == 2) {continue;}
                //探查到啦！返回这次出队的地方的dist
                if(grid[x][y] == 1) {return dist[f.first][f.second];}
                //探查的地方是水，更新这里的相关信息
                que_pos.emplace(x,y);
                dist[x][y] = dist[f.first][f.second] + 1;
                grid[x][y] = 2;
            }
        }
        return 0;
    }
};