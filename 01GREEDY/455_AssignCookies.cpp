//
// Created by 陈哲英 on 2021/10/27.
//
#include <vector>
using namespace std;
class Solution {
public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        sort(g.begin(),g.end());
//        sort(s.begin(),s.end());
//        int ans = 0;
//        for(int child: g) {
//            auto iter = s.begin();
//            for (int food: s) {
//                ++iter;
//                if(food >= child) {
//                    ans += 1;
//                    s.erase(s.begin(),iter);
//                    break;
//                }
//            }
//            if(s.size() == 0) {
//                return ans;
//            }
//        }
//        return ans;
//    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        while (child<g.size(), cookie<s.size()) {
            if(s[cookie]>=g[child]) {++child;}
            ++cookie;
        }
        return child;
    }
};