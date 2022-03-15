//
// Created by 陈哲英 on 2022/3/1.
//

#include <vector>
using namespace std;
class selectionSort{
public:
    void selection_Sort(vector<int> &nums, int n){
        int mid;
        for (int i = 0; i < n-1; ++i) {
            //[0,i]区间内是已排序序列
            //使用mid记录当前遍历到的最小值的位置
            mid = i;
            for (int j = i+1; j < n; ++j) {
                if(nums[j]<nums[mid]){
                    mid = j;
                }
            }
            swap(nums[i],nums[mid]);
        }
    }
};