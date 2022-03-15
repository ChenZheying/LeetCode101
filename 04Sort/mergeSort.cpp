//
// Created by 陈哲英 on 2022/2/28.
//
#include <vector>
using namespace std;

//归并排序：
class mergeSort {
public:
    //辅助函数merge，用于合并nums1的[front, mid]和(mid, end]
    void merge(vector<int> &nums, int front, int mid, int end) {
        vector<int> LeftSubVec(nums.begin()+front, nums.begin()+mid+1);
        vector<int> RightSubVec(nums.begin()+mid+1, nums.begin()+end+1);
        int idxLeft = 0, idxRight = 0;
        //在两个子数组的最后都插入两个最大值，以保证后续的循环中，
            //某个数组被遍历完后，会将另一数组的所有剩余值放入结果数组。
        LeftSubVec.push_back(INT32_MAX);
        RightSubVec.push_back(INT32_MAX);

        //要进行排序的是nums的[front,end]部分
        for (int i = front; i <= end; ++i) {
            if(LeftSubVec[idxLeft] < RightSubVec[idxRight])
            {
                nums[i] = LeftSubVec[idxLeft];
                ++idxLeft;
            } else{
                nums[i] = RightSubVec[idxRight];
                ++idxRight;
            }
        }
    }
    //归并排序函数，对nums的[front,end]进行排序
    void merge_Sort(vector<int> &nums, int front, int end) {
        if(front>= end) {
            return;
        }
        int mid = (front+end) /2;
        //分治思想
            //归并排序左半部
        merge_Sort(nums, front, mid);
            //归并排序右半部
        merge_Sort(nums, mid+1, end);
            //合并两部分
        merge(nums, front, mid, end);
    }



};