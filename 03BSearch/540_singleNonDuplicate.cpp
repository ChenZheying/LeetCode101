//
// Created by 陈哲英 on 2021/11/21.
//
#include <vector>
using namespace std;

class Solution {
public:
    //双指针暴力搜索
//    int singleNonDuplicate(vector<int>& nums) {
//        if(nums.size() == 1) {
//            return nums[0];
//        }
//        int left = 0, right = nums.size()-1;
//        while(left<=right) {
//            if(nums[right] - nums[left] == nums[right-1] - nums[left+1]) {
//                left += 2;
//                right -= 2;
//            }
//            else {
//                if(nums[right] == nums[right-1]) {
//                    return nums[left+2] == nums[left+1]?nums[left]:nums[left+1];
//                }
//                else {
//                    return nums[right-2] == nums[right-1]?nums[right]:nums[right-1];
//                }
//            }
//        }
//        return -1;
//    }
    //使用二分法
    //"数组元素有序"是一个迷惑项
    //关键点：去除中间的一对元素后，要找的但个元素存在于包含奇数个元素的部分
    //mid指向的元素有五种情况：
        //1. mid与mid+1相等，且右半部分为奇数个
        //2. mid与mid+1相等，且左半部分为奇数个
        //3. mid与mid-1相等，且右半部分为奇数个
        //4. mid与mid-1相等，且左半部分为奇数个
        //5. mid不与mid+1或mid-1相等
//    int singleNonDuplicate(vector<int>& nums) {
//        int left = 0, right = nums.size()-1;
//        //左右相等时，搜索区间宽度为1，要找的就是它
//        while(left < right) {
//            int mid = (left + right) >> 1;
//            //对以上五种情况进行区分
//            if(nums[mid] == nums[mid+1]) {
//                if((mid - left) % 2 == 0) {
//                    left = mid + 2;
//                }
//                else {
//                    right = mid - 1;
//                }
//            }
//            else if (nums[mid] == nums[mid-1]) {
//                if((right - mid) % 2 == 0) {
//                    right = mid - 2;
//                }
//                else {
//                    left = mid + 1;
//                }
//            }
//            else {
//                return nums[mid];
//            }
//        }
//        return nums[left];
//    }
    //使用二分法，且只遍历偶数元素号
    //如果mid和mid+1相等，则证明要找的单个元素在mid后面
    //如果mid和mid-1相等，则证明要找的单个元素在mid前面
    //如果都不相等，则证明mid就是要找的元素
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left<right) {
            int mid = (left + right) >> 1;
            if(mid%2!=0) {
                --mid;
            }
            if(nums[mid] == nums[mid+1]) {
                left = mid + 2;
            }
            else if(mid>0&&nums[mid] == nums[mid-1]) {
                right = mid - 2;
            }
            else {
                return nums[mid];
            }
        }
        return nums[left];
    }
};