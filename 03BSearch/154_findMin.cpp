//
// Created by 陈哲英 on 2021/11/22.
//
#include <vector>
using namespace std;
class Solution {
public:
    //找最小值，其实就是找左右区段，最小值就是右区段的第一个值
//    int findMin(vector<int>& nums) {
//        int left = 0, right = nums.size()-1;
//
//        int ans = nums[right];
//
//        while(left<=right) {
//            if(nums[left] < nums[right])
//            {
//                return nums[left];
//            }
//            int mid = (left+right) >> 1;
//            ans = min(nums[mid], ans);
//            if(nums[mid] == nums[left] && nums[mid] == nums[right]) {
//                ++left;
//                --right;
//            }
//            // 此时mid在左半区间，应该去右边找
//            else if(nums[mid]>=nums[right]&&nums[mid]>=nums[left]) {
//                left = mid+1;
//            }
//            //此时mid已经在右半区间了，把区间缩小到
//            else {
//                right = mid;
//            }
//
//        }
//        return ans;
//    }
    //更优雅的官方写法
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = (left+right) >> 1;
            if(nums[mid] > nums[right]) {
                left = mid+1;
            }
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            else {
                --right;
            }
        }
        return nums[left];
    }
};