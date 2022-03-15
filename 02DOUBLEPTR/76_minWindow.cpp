//
// Created by 陈哲英 on 2021/11/11.
//

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.size()<t.size()){
            return "";
        }

        //由于char一共有128中，所以可以用长度为128的数组记录滑动窗口
        //一个数组用来记录每个字符需要几个(初始化之后就不要变了)
        //另一个数组用来记录每个字符在窗口中已经有几个了
        vector<int> need(128, 0);
        vector<int> have(128, 0);
        for(const auto c:t){
            ++need[c];
        }
        int left = 0, right = 0, lack_count = t.size(), subStr_begin = 0, ans = s.size()+1;
        while(right < s.size()) {
            char r = s[right];
            if(need[r]==0) {
                ++right;
            }
            else {
                if(have[r]<need[r]) {
                    --lack_count;
                }
                ++have[r];
                ++right;
                while(lack_count == 0) {
                    if(right-left < ans) {
                        subStr_begin = left;
                        ans = right-left;
                    }
                    char l = s[left];
                    if(need[l] == 0) {
                        ++left;
                    }
                    else {
                        if(have[l]==need[l]) {
                            ++lack_count;
                        }
                        --have[l];
                        ++left;
                    }
                }
            }
        }
        if(ans == s.size()+1) {
            return "";
        }
        return s.substr(subStr_begin, ans);
    }
};
