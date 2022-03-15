//
// Created by 陈哲英 on 2021/11/14.
//
#include <cmath>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        //1. a, b 肯定都比c小
        //2. c必须能开方出一个整数
//        double c_sqrt = sqrt(c);
//        if(c_sqrt - int(c_sqrt) != 0) {
//            return false;
//        }
        c = (unsigned int)c;
        unsigned int a = 0, b = sqrt(c);
        while (a<=b) {
            int temp = a*a + b*b;
            if(temp == c) {
                return true;
            }
            else if (temp < c) {
                ++a;
            }
            else {
                --b;
            }
        }
        return false;
    }
};
