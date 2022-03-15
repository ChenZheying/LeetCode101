//
// Created by 陈哲英 on 2022/3/2.
//
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int size, int i) {
        visited[i] = true;
        for (int j = 0; j < size; ++j) {
            if(isConnected[i][j] == 1 && !visited[j]) {

                dfs(isConnected, visited, size, j);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        if(size == 0) {return 0;}
        int circles = 0;
        //visited是一个一维数组，用来存储一个城市是否被统计过了
        vector<bool> visited(size);
        for (int i = 0; i < size; ++i) {
            if(!visited[i]) {
                dfs(isConnected, visited, size, i);
                ++circles;
            }
        }
        return circles;
    }
};