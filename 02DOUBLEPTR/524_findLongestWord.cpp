//
// Created by 陈哲英 on 2021/11/15.
//

#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    bool isFind(string s, string t) {
        int pos = -1;
        for(auto c:t) {
           pos = s.find(c,pos+1);
           if(pos==string::npos) {
               return false;
           }
        }
        return true;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<string> ans;
        for(auto elem: dictionary) {
            if(isFind(s,elem)) {
                ans.push_back(elem);
            }
        }
        if(ans.empty()) { return ""; }
        else {
            if(ans.size()==1) {
                return ans[0];
            }
            sort(ans.begin(), ans.end(),
                 [](const auto &u, const auto &v) {
                     return u.size() > v.size();
                 });
            string first = *ans.begin(), second = *(ans.begin() + 1);
            if(first.size()!= second.size()) {
                return first;
            }
            else {
                for (int i = 0; i < first.size(); ++i) {
                    char c_f = first[i], c_s = second[i];
                    if(c_f < c_s) {
                        return first;
                    }
                    else if(c_f > c_s) {
                        return second;
                    }
                }
                return first;
            }
        }
    }
};