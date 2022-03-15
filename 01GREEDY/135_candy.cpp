//
// Created by 陈哲英 on 2021/10/27.
//
#include <vector>
#include <numeric>

using namespace std;
class Solution {
public:
    //需要一个数组保存目前的糖果数量
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size < 2) {return size;}
        vector<int> candyNum(size,1);
        for (int i = 1; i < size; ++i) {
            if(ratings[i] >ratings[i-1]){
                candyNum[i] = candyNum[i-1] +1;
            }
        }
        for (int i = size-1; i > 0; --i) {
            if(ratings[i] < ratings[i-1] && candyNum[i] >= candyNum[i-1]) {
                candyNum[i-1] = candyNum[i] + 1;
            }
        }
        return accumulate(candyNum.begin(),candyNum.end(),0);
    }
};