//
// Created by 陈哲英 on 2021/11/16.
//


class Solution {
public:
    int mySqrt(int x) {
        if (x == 0|| x==1) {return x;}
        unsigned int left = 1, right = x;
        while(left < right) {
            long cur = (left + right) / 2;
            long square = cur*cur, next = (cur+1)*(cur+1);
            if(x>=square && x<next) {
                return cur;
            }
            else if(x >= next) {
                left = cur+1;
            }
            else{
                right = cur;
            }
        }
        return -1;
    }
};