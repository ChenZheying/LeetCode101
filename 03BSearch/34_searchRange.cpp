//
// Created by 陈哲英 on 2021/11/16.
//
#include <vector>
using namespace std;
class Solution {
public:
    //本题二分查找的是两个元素：
    //1. 值为target且前一个值不为target的元素
    //2. 值为target且后一个值不为target的元素
//    std::vector<int> searchRange(std::vector<int>& nums, int target) {
//        if(nums.empty()) {return {-1,-1};}
//        int left = 0, right = nums.size()-1, cur;
//        int begin = -1, end = -1;
//        //先用一个循环找元素1
//        while(left <= right) {
//            cur = left + (right - left) / 2;
//            int value = nums[cur];
//            if(value == target) {
//                if(cur == 0){
//                    begin = cur;
//                    break;
//                }
//                if(cur != 0 && nums[cur-1] != target) {
//                    begin = cur;
//                    break;
//                } else {
//                    right = cur - 1;
//                }
//            }
//            else if(value < target) {
//                left = cur+1;
//            }
//            else {
//                right = cur -1;
//            }
//        }
//        if(begin == -1) {
//            return {-1,-1};
//        }
//        //在用一个循环找元素2
//        left = cur, right = nums.size();
//        while(left <= right) {
//            cur = left + (right - left) / 2;
//            int value = nums[cur];
//            if(value == target) {
//                if(cur==nums.size()-1) {
//                    end = cur;
//                    break;
//                }
//                if(cur != nums.size()-1 && nums[cur+1] != target) {
//                    end = cur;
//                    break;
//                } else {
//                    left = cur + 1;
//                }
//
//            }
//            else if(value < target) {
//                left = cur+1;
//            }
//            else {
//                right = cur -1;
//            }
//        }
//        return {begin,end};
//    }
    int binarySearch(vector<int> nums, int target, int lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left<=right) {
            int mid = left+(right-left)/2;
            if(nums[mid] > target || (lower&&nums[mid]>=target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
            return ans;
        }
    }
};