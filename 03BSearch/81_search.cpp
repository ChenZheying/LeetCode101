//
// Created by 陈哲英 on 2021/11/18.
//
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) {
            return false;
        }
        else if(n == 1) {
            return (nums[0] == target);
        }
        int left = 0, right = n-1;
        while(left <= right) {
            int mid = (left+right) >> 1;
            if(nums[mid] == target) {
                return true;
            }
            //这种情况下，分割点可能是在一个数字的连续过程中间
            //或者是从头到尾都是一个元素
            //由于搜索区间切换的标准，是通过mid的值和left/right的值比较得来的
                //所以要把这三值都相等的条件另行处理
            if(nums[left] == nums[mid] && nums[right] == nums[mid]) {
                ++left;
                --right;
            }
            //左半部分和右半部分都是局部递增的
            //mid在左半部分
            else if (nums[mid] >= nums[left]) {
                if(nums[left]<=target && nums[mid] >target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            //mid在右半部分
            else {
                if(nums[mid] < target && nums[right] >= target) {
                    left = mid+1;
                }
                else {
                    right = mid -1;
                }
            }
        }
        return false;
    }
};