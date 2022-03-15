//
// Created by 陈哲英 on 2022/3/1.
//
#include <vector>
using namespace std;

class Solution {
public:



    // 进行n-k次冒泡排序，此时从头到尾有k个元素被从小到大排序，取第k个元素即为所需结果
    //冒泡排序的时间复杂度是n^2
//    int findKthLargest(vector<int>& nums, int k) {
//        int n = nums.size();
//        bool swapped = false;
//        for (int i = 0; i < k; ++i) {
//            //数组末尾的若干的元素是有序的
//            // 所以j从0开始遍历，直到遇到这些有序元素
//            for (int j = 0; j < n-i-1; ++j) {
//                if(nums[j]>nums[j+1]) {
//                    swap(nums[j],nums[j+1]);
//                    swapped = true;
//                }
//            }
//            if(swapped == false) {
//                return nums[n-k];
//            }
//        }
//        return nums[n-k];
//    }
    //使用快速排序的版本
    //快速排序的平均时间复杂度是o(nlogn)，
    // 但当排序数组是有序的时候，时间复杂度最差，是o(n^2)
    // 所以快速排序一般搭配一个打乱数组的函数

    int quickSelect(vector<int>& nums, int left, int right,int index)
    {
        //q代表第一趟快排排好的元素
        int q = randomPartition(nums, left, right);
        if (q==index) {
            return nums[q];
        }
        else {
            return q<index? quickSelect(nums,q+1,right,index): quickSelect(nums,left,q-1,index);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int resultPos = nums.size() - k;
        //设置随机因子
        srand(time(0));
        return quickSelect(nums,0,nums.size()-1,resultPos);
    }
    inline int randomPartition(vector<int>& a, int l, int r) {
        //i落在l到r-1之间
        int i = rand() %(r - l + 1) +l;
        //交换一次随机位置和r的元素
        swap(a[i],a[r]);
        return partition(a, l, r);
    }
    inline int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        while(left < right) {
            while(left < right && nums[right] >= pivot) {
                --right;
            }
            nums[left] = nums[right];
            while(left < right && nums[left] <= pivot) {
                ++left;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};