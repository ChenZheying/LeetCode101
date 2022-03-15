//
// Created by 陈哲英 on 2022/2/23.
//
#include <vector>
using namespace std;
//快速排序：选定一个基准后，把比他大的放右边，比他小的放左边，然后左右两边的区间递归
class quickSort {
public:
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[left];
        while(left < right) {
            //在每一趟循环中
            //先从右往左找，直到找到一个比pivot小的
            while(left < right && nums[right]>=pivot) {
                --right;
            }
            //此时right处是在left右边的，比nums[left]小的数
            nums[left] = nums[right];
            //此时right处的值是没用的
            //开始从左往右找，直到找到一个比pivot大的，存在right处
            while(left < right && nums[left]<=pivot) {
                ++left;
            }
            nums[right] = nums[left];
        }
        //跳出循环时left=right
        nums[left] = pivot;
        //返回pivot所在的位置
        return left;
    }
    void quick_sort(vector<int> &nums, int l, int r) {
        if(l<r) {
            int pivot = partition(nums, l, r);
            quick_sort(nums, l, pivot-1);
            quick_sort(nums, pivot+1, r);
        }
    }
};

