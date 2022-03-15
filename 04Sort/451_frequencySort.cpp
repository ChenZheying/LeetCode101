//
// Created by 陈哲英 on 2022/3/2.
//
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        int max_count = 0;
        for(const char& c: s)
        {
            max_count = max(max_count, ++counts[c]);
        }
        vector<vector<char>> bucket(max_count+1);
        for (const auto& p:counts) {
            bucket[p.second].push_back(p.first);
        }
        string ans = "";
        for (int i = bucket.size()-1; i >=0 ; --i) {
            for (const auto& c:bucket[i]) {
                string temp(i,c);
                ans+=temp;
            }
        }
        return ans;
    }
};