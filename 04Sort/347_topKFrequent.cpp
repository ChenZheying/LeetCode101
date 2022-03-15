//
// Created by 陈哲英 on 2022/3/1.
//
#include <vector>
#include <unordered_map>
using namespace  std;



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //counts用来存nums中各数字出现的次数
        unordered_map<int, int> counts;
        //max_count用来记录最大频次，用以确定桶的个数
        int max_count = 0;
        for(const int& num:nums) {
            max_count = max(max_count, ++counts[num]);
        }
        //桶的序号：出现次数
        //桶的内容：num
        //最高频次是max_count，所以桶的大小应该是max_count+1，否则下标max_count会越界
        vector<vector<int>> buckets(max_count);
        for(const auto &p: counts) {
            //p：<num，出现次数>
            buckets[p.second].push_back(p.first);
        }

        vector<int> ans;
        //取频次最高的k个元素，放到ans中
        //在ans的size到达k时，跳出循环
        for (int i = max_count; i>=0 && ans.size() < k; --i) {
            for (const int& num:buckets[i]) {
                ans.push_back(num);
                if(ans.size() == k) {
                    break;
                }
            }
        }
        return ans;
    }
};