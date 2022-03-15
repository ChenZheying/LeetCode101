//
// Created by 陈哲英 on 2022/3/3.
//
#include <vector>
using namespace std;

class Solution {
public:
    //递归函数
    void backtracking (int n, int k, int current_pos,
                       vector<int>& path, vector<vector<int>>& ans) {
        if(path.size() == k) {
            ans.push_back(path);
            return;
        }
        for (int i = current_pos + 1; i <= n - (k-path.size()) + 1; ++i) {
            path.push_back(i);
            backtracking(n,k,i,path,ans);
            path.erase(path.end()-1);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        int current_pos = 0;
        vector<vector<int>> ans;
        vector<int> path;
        backtracking(n, k, 0, path, ans);
        return ans;
    }
};