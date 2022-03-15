//
// Created by 陈哲英 on 2021/11/9.
//
#include <vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) {
            return true;
        }
        int size = flowerbed.size();
        for (int i = 0; i < size;) {
            if(flowerbed[i] == 0) {
                if(i == size-1) {
                    --n;
                    if(n == 0) {
                        return true;
                    }
                    break;
                }
                else if(flowerbed[i+1] == 0) {
                    i+=2;
                    --n;
                    if(n == 0) {
                        return true;
                    }
                }
                else {
                    i+=3;
                }
            }
            else {
                i+=2;
            }
        }
        return false;
    }
};