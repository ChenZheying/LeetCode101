//
// Created by 陈哲英 on 2021/10/27.
//
#include <vector>

using namespace std;
class Solution {
public:
    //动态规划：
    //1. 排序
    //2. 检查下一个和上一个是否重合，不重合就+1
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) {
            return 0;
        }
        //自定义排序标准，以begin升序排列
        sort(intervals.begin(), intervals.end(),
             [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });
        int n = intervals.size();
        int continuous = 1;
        int split = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if(intervals[i][0] >= split) {
                ++continuous;
                split = intervals[i][1];
            }
        }
        return n - continuous;
    }
};