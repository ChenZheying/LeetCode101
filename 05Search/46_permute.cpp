//
// Created by 陈哲英 on 2022/3/3.
//
#include <vector>
using namespace std;

class Solution {
public:
    //首先分析题目，是需要做递归的：因为算法需要做的事情是
    // 1，2，3，4 全排列 -> 1 固定 2, 3, 4全排列 + 2 固定 1, 3, 4全排列......
    //                  -> 1，2固定，3，4全排列

    //参数level表示nums的前level+1个元素固定
    void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans)
    {

        //递归函数一定要有返回的条件
        //当level（范围是从0到nums.size()-1）等于nums.size()-1时，指向末尾元素，表示走到了最深处
        if(level == nums.size()-1) {
            ans.push_back(nums);
            return;
        }
        //i从当前固定的值开始遍历，因为需要把本趟递归中，啥都不变的情况统计进去
        for (int i = level; i < nums.size(); ++i) {
            swap(nums[i], nums[level]);
            //递归调用，走到最深处的时候，形成一次排列
            backtracking(nums, level+1, ans);
            swap(nums[i],nums[level]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {return {};}
        vector<vector<int>> ans;
        backtracking(nums, 0, ans);
        return ans;
    }
};