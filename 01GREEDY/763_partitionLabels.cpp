//
// Created by 陈哲英 on 2021/11/10.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
//    vector<int> partitionLabels(string s) {
//        vector<int> result;
//        //不要用迭代器了，用size_type的pos
//        string::size_type cur = 0, region_begin = 0;
//
//        while(region_begin<s.size()) {
//            string substr = s.substr(region_begin, 1);
//            //string的函数：find_first_of：在s中从cur位置开始找到第一次出现substr中的某个字符的位置
//            while ((cur = s.find_first_of(substr, cur)) != string::npos) {
//                ++cur;
//                substr = s.substr(region_begin, cur-region_begin);
//            }
//            result.push_back(substr.size());
//            region_begin = region_begin + substr.size();
//            cur = region_begin;
//        }
//        return result;
//    }
    //1. 不用真的分出来子字符串
    //2. 涉及到存储字母的信息的，可以考虑使用一个长度是26的数组
    vector<int> partitionLabels(string s) {
        vector<int> lastPos(26);
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            lastPos[s[i]-'a']=i;
        }
        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < length; ++i) {
            end = max(end, lastPos[s[i]-'a']);
            if(i == end) {
                ans.push_back(end-start+1);
                start = end+1;
            }
        }
        return ans;
    }
};