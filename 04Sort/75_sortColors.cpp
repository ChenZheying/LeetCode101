//
// Created by 陈哲英 on 2022/3/2.
//
#include <vector>
using namespace std;
class Solution {
public:
//    void sortColors(vector<int>& nums) {
//        for (int i = 0; i < nums.size(); ++i) {
//            int mid = i;
//            for (int j = i+1; j < nums.size(); ++j) {
//                if(nums[j] < nums[mid]) {
//                    mid = j;
//                }
//            }
//            swap(nums[i],nums[mid]);
//        }
//    }
    //  利用快排的思想：一趟排序后，pivot后的比pivot大，pivot前的比pivot小
    void sortColors(vector<int>& nums) {
        //设定位置p0和p1，含义为：
        // p0前的都是0，p1后的都是2
        int p0 = 0, p1 = nums.size()-1;
        //i用于遍历nums
        int i = 0;
        while(i<=p1 && p0<=p1) {
            if (nums[i] == 2) {
                swap(nums[i],nums[p1]);
                --p1;
            }
            else if(nums[i] == 0) {
                swap(nums[i], nums[p0]);
                ++p0;
                ++i;
            }
            else {
                ++i;
            }
        }
    }
};