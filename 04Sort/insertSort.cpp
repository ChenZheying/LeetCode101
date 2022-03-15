//
// Created by 陈哲英 on 2022/3/1.
//
#include <vector>
using namespace std;
class insertSort {
public:
    void insertionSort (vector<int> &nums, int n)
    {
        for (int i = 0; i < n; ++i) {
            //进入下面这个循环时nums[0,i-1]是有序的
            //所以从i-1开始倒序检查，遇到第一个比nums[i]小的元素，其后就是nums[i]的所在位置
            //为了把这个位置空出来，就持续的进行元素交换，把比nums[i]大的元素都往后换
            for (int j = i; j>0 && nums[j]<nums[j-1] ; --j) {
                swap(nums[j],nums[j-1]);
            }
        }
    }
};