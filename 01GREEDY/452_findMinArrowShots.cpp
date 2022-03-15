//
// Created by 陈哲英 on 2021/11/9.
//
#include <vector>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(),points.end(),
             [](const auto &u, const auto &v) {
            return u[0]<v[0];
        });
        int n = points.size(), count = 1, split = points[0][1];
        for (int i = 1; i < n; ++i) {
            if(points[i][0]<=split) {
                split = min(points[i][1],split);
            }
            else {
                ++count;
                split=points[i][1];
            }
        }
        return count;
    }
};