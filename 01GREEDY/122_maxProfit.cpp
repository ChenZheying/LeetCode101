//
// Created by 陈哲英 on 2021/11/10.
//
#include <vector>
using namespace std;

class Solution {
public:
    //动态规划思想
    //倒着算出每一天的profit，全部加起来
//    int maxProfit(vector<int>& prices) {
//        int size = prices.size();
//        vector<int> profit(size,0);
//        for (int i = size-2; i >= 0; --i) {
//            for (int j = i+1; j < size; ++j) {
//                if(prices[j] > prices[i]) {
//                    profit[i] = max(profit[i+1],prices[j]-prices[i]+profit[j]);
//                    break;
//                }
//                else if(j==size-1) {
//                    profit[i] = profit[i+1];
//                }
//            }
//        }
//        sort(profit.begin(),profit.end());
//        return *profit.rbegin();
//    }

    //贪心
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            ans += max(0, prices[i]-prices[i-1]);
        }
        return ans;
    }
};