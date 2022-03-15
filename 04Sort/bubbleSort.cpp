//
// Created by 陈哲英 on 2022/3/1.
//
#include <vector>
using namespace std;
class bubbleSort {
public:
    //冒泡排序，像冒泡泡一样，每次最大的数会冒到数组末尾
    //逐个比较,指针指向较大的数，另一个指针遍历
    void bubble_Sort(vector<int> &nums, int n) {
        bool swapped;
        //
        for (int i = 0; i < n - 1; ++i) {
            swapped = false;
            for (int j = 0; j < n - 1 - i; ++j) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            }
            //表示数组已经有序，无需后面的循环
            if(swapped == false) {
                break;
            }
        }
    }
};