//
// Created by 陈哲英 on 2021/11/14.
//

#include <string>
using namespace std;
class Solution {
public:
    bool checkPalindrome(const string& s, int begin, int end) {
        while(begin < end) {
            if(s[begin] != s[end]) {
                return false;
            }
            else {
                ++begin;
                --end;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left<right) {
            if(s[left] != s[right]) {
                if(checkPalindrome(s, left+1,right)) {
                    return true;
                }
                else if(checkPalindrome(s, left, right-1)) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                ++left;
                --right;
            }
        }
        return true;
    }
};