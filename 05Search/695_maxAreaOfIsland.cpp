//
// Created by 陈哲英 on 2022/3/2.
//
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:

    //深度优先搜索有两种写法：1. 使用栈 2. 递归

    //使用栈进行深度优先搜索
    //思路：（将遍历到的是1的元素的位置放入栈中）
    //栈内存元素是1的位置，出栈并检查其周围，将是1的元素的位置放入栈中，再将此位置的元素置为0，避免重复统计
    //累加当前所检查的区域的面积
    vector<int> directions = {-1,0,1,0,-1};
//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        int m = grid.size();
//        if(m == 0) {return 0;}
//        int n = grid[0].size();
//        int max_area = 0, local_area, x, y;
//
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                //如果发现了是1的元素，再定义栈，存放该存放的东西
//                if(grid[i][j] == 1) {
//                    local_area = 1;
//                    stack<pair<int,int>> island;
//                    island.push(make_pair(i,j));
//                    grid[i][j] = 0;
//                    //island空的时候表示统计完一个小岛，更新max_area
//                    while(!island.empty()) {
//                        auto [r, c] = island.top();
//                        //pop的这个1之前已经统计过面积了，所以不进行其他操作，只用来检测其附近是否有1
//                        island.pop();
//                        //这个循环是遍历周围的四个方向
//                        for (int k = 0; k < 4; ++k) {
//                            x = r + directions[k], y = c + directions[k+1];
//                            if(x>=0&&x<m &&
//                            y>=0&&y<n && grid[x][y] == 1) {
//                                grid[x][y] = 0;
//                                island.push(make_pair(x,y));
//                                ++local_area;
//                            }
//                        }
//                    }
//                    max_area = max(max_area, local_area);
//                }
//
//            }
//
//        }
//        return max_area;
//
//    }
    //使用递归进行深度优先搜索

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size() == 0) {
            return 0;
        }
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if(grid[r][c] == 0) {return 0;}
        //把检查到的位置元素置零，避免重复统计
        grid[r][c] = 0;
        int x, y, area = 1;
        for (int i = 0; i < 4; ++i) {
            x = r + directions[i], y = c + directions[i+1];
            if(x>=0&&x<grid.size()&&
                y>=0&&y<grid[0].size()&&
                grid[x][y] == 1) {
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};