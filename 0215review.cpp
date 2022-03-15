//
// Created by 陈哲英 on 2022/2/15.
//


#include "ListNode.h"
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    //455
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        sort(g.begin(),g.end());
//        sort(s.begin(),s.end());
//        int result = 0;
//        auto it = g.begin();
//        auto it2 = s.begin();
//        while(it!=g.end()) {
//            while(it2!=s.end()) {
//                if(*it<=*it2) {
//                    ++result;
//                    ++it2;
//                    break;
//                }
//                ++it2;
//            }
//            ++it;
//        }
//        return result;
//    }
    //135
//    int candy(vector<int>& ratings) {
//        int size = ratings.size();
//        vector<int> candies(size,1);
//        for (int i = 1; i < size; ++i) {
//            if(ratings[i-1]<ratings[i]) {
//                ++candies[i];
//            }
//        }
//        for (int i = size-1; i > 0; --i) {
//            if(ratings[i]<ratings[i-1]) {
//                ++candies[i-1];
//            }
//        }
//        int result = accumulate(candies.begin(),candies.end(),0);
//        return result;
//    }
    //435
    //优先删除掉结束区间较大的，要注意删除掉一个区间后，下一区间的前一个区间发生了变化
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        if(intervals.size()<2) {
//            return 0;
//        }
//        int removed_nums=0;
//        sort(intervals.begin(),intervals.end(), [](vector<int>& a,vector<int>& b)
//             {
//                 return a[1]<b[1];
//             });
//
//        auto it = intervals.begin()+1;
//        auto prev_it = intervals.begin();
//
//        while (it != intervals.end()) {
//            if((*prev_it)[1]>(*it)[0]) {
//                ++removed_nums;
//            }
//            else {
//                prev_it = it;
//            }
//            ++it;
//        }
//        return removed_nums;
//    }
    //605
//    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//        if(n == 0) {return true;}
//        int size = flowerbed.size();
//        for (int i = 0; i < size; ++i) {
//            if(flowerbed[i] == 0 && (i==0||flowerbed[i-1]==0) && (i==size-1 || flowerbed[i+1] == 0)) {
//                flowerbed[i] = 1;
//                --n;
//            }
//            if(n == 0) {
//                return true;
//            }
//        }
//        return false;
//    }
    //452
//    int findMinArrowShots(vector<vector<int>>& points) {
//        sort(points.begin(),points.end(), [](vector<int> &a, vector<int>& b) {
//            return a[1]<b[1];
//        });
//        if (points.size() == 0) {
//            return 0;
//        }
//        else if (points.size() == 1) {
//            return 1;
//        }
//        int result = points.size();
//        auto prev_it = points.begin();
//        for (auto it = points.begin()+1; it != points.end() ; ++it) {
//            if((*(it))[0]<= (*(prev_it))[1]) {
//                --result;
//            } else {
//                prev_it = it;
//            }
//
//        }
//        return result;
//    }
    //763
    //find_first_of(string substr, size_type pos)会从pos开始寻找substr中任一个字符首次出现的位置
//    vector<int> partitionLabels(string s) {
//       string::size_type cur = 0, start = 0;
//       vector<int> result;
//       while (start < s.size()) {
//           string substr = s.substr(start, 1);
//           while ((cur = s.find_first_of(substr, cur)) != string::npos) {
//                ++cur;
//                substr = s.substr(start, cur-start);
//           }
//           result.push_back(substr.size());
//           start = start+substr.size();
//           cur = start;
//       }
//        return result;
//    }
    //122
//    int maxProfit(vector<int>& prices) {
//        vector<int> difference;
//        for (int i = 1; i < prices.size(); ++i) {
//            difference.push_back(prices[i]-prices[i-1]);
//        }
//        vector<int> profit;
//        for(auto i: difference) {
//            if(i > 0) {
//                profit.push_back(i);
//            }
//        }
//        if(profit.size()>0) {
//            return accumulate(profit.begin(), profit.end(),0);
//        }
//        else {
//            return 0;
//        }
//    }
    //167
//    vector<int> twoSum(vector<int>& numbers, int target) {
//        int end = numbers.size()-1;
//        int start = 0;
//        while (start<end) {
//            int sum = numbers[start]+numbers[end];
//            if(sum == target) {
//                return {start+1,end+1};
//            }
//            else if(sum < target) {
//                ++start;
//            }
//            else if(sum > target) {
//                --end;
//            }
//        }
//        return {-1,-1};
//    }
    //88
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        int p1 = 0, p2 = 0;
//        while(p1<m && p2<n) {
//            if(nums1[p1]>nums2[p2]) {
//                swap(nums1[p1],nums2[p2]);
//                sort(nums2.begin(),nums2.end());
//            }
//            ++p1;
//        }
//        for (int i = m; i < nums1.size(); ++i) {
//            nums1[i] = nums2[i-m];
//        }
//    }
    //88
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        int pos1 = m-1, pos2 = n-1;
//        for (int i = nums1.size()-1; i >= 0; --i) {
//            if(pos1<0) {
//                for (int j = 0; j <= pos2; ++j) {
//                    nums1[j] = nums2[j];
//                }
//                return;
//            }
//            else if(pos2<0) {
//                return;
//            }
//            if(nums1[pos1]>= nums2[pos2]) {
//                nums1[i] = nums1[pos1];
//                --pos1;
//            }
//            else {
//                nums1[i] = nums2[pos2];
//                --pos2;
//            }
//        }
//    }
    //142
//    ListNode *detectCycle(ListNode *head) {
//        if(head== nullptr) {return nullptr;}
//        ListNode *fast, *slow;
//        slow = head->next;
//        if(slow == nullptr) {
//            return nullptr;
//        }
//        fast = slow->next;
//        if(fast == nullptr) {
//            return nullptr;
//        }
//        else if(fast == head) {
//            return head;
//        }
//        while(slow != fast) {
//            if(fast->next != nullptr && fast ->next->next != nullptr) {
//                fast = fast->next->next;
//            }
//            else {
//                return nullptr;
//            }
//            slow = slow->next;
//        }
//        slow = head;
//        while(fast!=slow) {
//            fast = fast->next;
//            slow = slow->next;
//        }
//        return slow;
//    }
    //76
//    string minWindow(string s, string t) {
//        vector<int> need(58,0);
//        vector<int> have(58,0);
//        for(char &c:t) {
//            ++need[c-'A'];
//        }
//        //need中存放字符串t的字符出现次数
//        // have中表示当前检查中，检查到的所需字符数
//        // 使用一个变量count表示当前检查到的所需字符的数量，和t的长度进行比较，来确定是否需要继续
//        // 使用一个变量minLength表示检查到的最短合法字符串的长度
//        // 使用一个变量start记录minLength对应的字符串的开始处
//        // left和right组成字符串s上的一个滑动窗口，先增加right，扩大窗口，让窗口中包含所有的字符
//            // 在增大left，缩小窗口，让窗口成为最小
//        int start = 0, minLength = s.size()+1;
//        for (int right = 0, left = 0, count=0; right < s.size(); ++right) {
//            int c_index = s[right]-'A';
//            //不需要当前检查到的这个字符
//            if(need[c_index] == 0) {
//                continue;
//            }
//            //需要当前检查到的这个字符
//            if(have[c_index] < need[c_index]) {
//                ++count;
//            }
//            //到这里时，检查到的这个字符一定是需要的，分为两种情况：
//                //情况1：数量已经够了（或者超了）
//                //情况2：数量不够
//            //反正够不够，都给have的对应元素加一
//            ++have[c_index];
//            //当count数量达到t的长度时，表示窗口中已经包含了所有所需字符
//            while(count == t.size()) {
//                // 如果当前窗口比之前的记录小，则记录当前窗口的起始位置和长度，
//                // 然后缩小窗口，直到跳出循环
//                if(right - left + 1 < count) {
//                    minLength = right - left + 1;
//                    start = left;
//                }
//                int l_index = s[left] - 'A';
//                if(need[l_index] == 0) {
//                    ++left;
//                    continue;
//                }
//                if(need[l_index] == have[l_index]) {
//                    --count;
//                }
//                --have[l_index];
//                ++left;
//            }
//        }
//        return minLength == s.size()+1?"":s.substr(start, minLength);
//    }
    //633
//    bool judgeSquareSum(int c) {
//        //先用二分查找找右边界
//        c = (unsigned int)c;
//        unsigned int right = sqrt(c)/1 , left = 0;
//        while(left<=right) {
//            unsigned int sum = left*left + right*right;
//            if(sum == c) {
//                return true;
//            }
//            else if(sum > c) {
//                --right;
//            }
//            else if(sum < c) {
//                ++left;
//            }
//        }
//        return false;
//
//    }


    //680
//    bool checkPalindrome(const string& s, int begin, int end) {
//        while(begin<end) {
//            if(s[begin] != s[end]) {
//                return false;
//            }
//            else {
//                ++begin;
//                --end;
//            }
//        }
//        return true;
//    }
//    bool validPalindrome(string s) {
//        int left = 0, right = s.size()-1;
//        while(left<right) {
//            if(s[left]!=s[right]) {
//                if(checkPalindrome(s,left,right-1)) {
//                    return true;
//                }
//                else if(checkPalindrome(s, left+1, right)) {
//                    return true;
//                }
//                else {
//                    return false;
//                }
//            }
//            else {
//                ++left;
//                --right;
//            }
//        }
//        return true;
//    }
    //524
//    string findLongestWord(string s, vector<string>& dictionary) {
//        sort(dictionary.begin(),dictionary.end(), [](const string& a,const string& b) {
//            if(a.size()!=b.size()) { return a.size() > b.size(); }
//            else {
//                return a<b;
//            }
//        }); //排序后字典按长度降序
//        for(const string& str:dictionary) {
//            string::size_type pos=-1;
//            int length = str.size(),count = 0;
//            for (const char& c:str) {
//                pos = s.find(c, pos+1);
//                if(pos==s.npos) {
//                    break;
//                }
//                else {
//                    ++count;
//                }
//            }
//            if(count == length) {
//                return str;
//            }
//        }
//        return "";
//
//    }
    //69
//    int mySqrt(int x) {
//        if (x==0) {return 0;}
//        int left = 1, right = x, mid, sqrt;
//        while(left <= right) {
//            mid = left+(right-left)/2;
//            sqrt = x/mid;
//            if(sqrt == mid) {
//                return sqrt;
//            }
//            else if(sqrt > mid) {
//                left = mid + 1;
//            }
//            else {
//                right = mid -1;
//            }
//        }
//
//    }
    //34
    //使用辅助函数进行二分搜索
        // 如果lower是true，此函数返回第一个大于等于target的下标
        // 如果lower是false，此函数返回第一个大于target的下标
//    int bSearch(vector<int>& nums, int target, bool lower= false) {
//        int left = 0, right = nums.size() - 1, ans = nums.size();
//        //循环，直到左右指针相遇之后
//        while(left<=right) {
//            int mid = (left+right) >> 1;
//            //lower是false时
//                //左右指针相遇之前，存储每一个大于target的下标为ans，（这个就是区间结束点）
//                //当左指针超过右指针之后，之前最后一次存储下来的ans就是第一个大于target的下标
//                    //因为总有一个指针是指向ans的，区间会向这个方向移动
//
//            //lower时true时
//                //左右指针相遇之前，存储每一个大于等于target的下标为ans（这个就是区间开始点）
//                //当左指针超过右指针之后，之前最后一次存储下来的ans就是第一个大于等于target的下标
//
//            if(nums[mid]>target || (lower&&nums[mid]>=target)) {
//                right = mid - 1;
//                ans = mid;
//            }
//            else {
//                left = mid + 1;
//            }
//
//        }
//        return ans;
//    }
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        int start = bSearch(nums, target, true);
//        int end = bSearch(nums, target)-1;
//        if(start<=end) { return {start, end};}
//        else {
//            return {-1,-1};
//        }
//    }

    //81

//    bool search(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        while(left <= right) {
//            int mid = (left + right) >> 1;
//            if(nums[mid] == target) {
//                return true;
//            }
//            if(nums[mid] == nums[right]) {
//                --right;
//            }
//            //右边有序
//            else if(nums[mid] < nums[right]) {
//                if(nums[mid] < target && target <= nums[right]) { left = mid + 1; }
//                else {
//                    right = mid - 1;
//                }
//            }
//            //左边
//            else {
//                if(nums[mid]>target && target>=nums[left]) {
//                    right = mid -1 ;
//                }
//                else {
//                    left = mid + 1;
//                }
//            }
//        }
//        return false;
//    }
    //154
//    int findMin(vector<int>& nums) {
//        int left = 0, right = nums.size()-1, min = INT32_MAX;
//        while(left <= right) {
//            int mid = (left+right) >> 1;
//            if(nums[mid] < min) {
//                min = nums[mid];
//            }
//            if(nums[mid] == nums[right]) {
//                --right;
//            }
//            //右边有序,最小值一定在左边
//            else if(nums[mid] < nums[right]) {
//                right = mid - 1;
//            }
//            //左边有序，最小值一定在右边
//            else {
//                left = mid + 1;
//            }
//        }
//        return min;
//    }
    //540
//    int singleNonDuplicate(vector<int>& nums) {
//        //nums的个数一定是奇数
//        int left = 0, right = nums.size() - 1;
//        while (left < right) {
//            //规律：
//                // 偶数号的数值和右边的相等，说明target在右边
//                // 偶数号的数值和左边的相等，说明target在左边
//            int mid = (left + right) >> 1;
//            // 先控制mid的标号是偶数
//            if(mid%2!=0) {
//                --mid;
//            }
//            if(nums[mid] == nums[mid+1]) {
//                left = mid+2;
//            }
//            else if(mid>0&&nums[mid] == nums[mid-1]) {
//                right = mid - 2;
//            }
//            else {
//                return nums[mid];
//            }
//        }
//        return nums[left];
//    }
    //4
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // 保证nums1是比较短的
        if(nums1.size()>nums2.size()) {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        int m = nums1.size(), n = nums2.size();
        if(m==0) {
            if(n==0) {
                return -1;
            }
            else {
                if(n%2 == 0) {
                    return (nums2[n/2-1]+nums2[n/2])/2.0;
                }
                else {
                    return nums2[n/2];
                }
            }
        }
        // 如果m+n是奇数，中位数应该是第(m+n)/2个 （从零开始）
        // 如果m+n是偶数，中位数应该是第(m+n)/2和(m+n)/2-1个的平均值
        // 使用二分查找法找到位置：
            //若奇数，此位置左边是中位数
            //若偶数，此位置左右两边的平均数是中位数
            //统一为(m+n+1)/2
            //此时split左右的元素个数相等（或左边比右边多一个）
        int split = (m+n+1)>>1;
        //由于现在是在两个有序数组上找分割线
            //所以要在nums1和nums2中各自找到一个split1和split2
            //保证：
                //1. split1+split2=split（即确定split1之后也就确定了split2）
                //2. split1和split2左边的两组元素，比右边的两组元素小
                    //即：split1的左边比split2的右边小
                    //split1的右边比split2的左边大
        int left = 0, right = nums1.size() ,split1,split2;
        while(left < right) {
            split1 = (left+right+1) >> 1;
            split2 = split - split1;
//            if((nums1[split1-1] <= nums2[split2])&& (nums1[split1] >= nums2[split2-1])) {
//                if((n+m)%2 == 0) {
//                    return (double)((nums1[split1-1]>nums2[split2-1]?nums1[split1-1]:nums2[split2-1])+
//                            (nums1[split1]<nums2[split2]?nums1[split1]:nums2[split2]))/2.0;
//                }
//                else {
//                    return  nums1[split1-1]>nums2[split2-1]?nums1[split1-1]:nums2[split2-1];
//                }
//            }
            if(nums1[split1-1]>nums2[split2]) {
                right = split1 - 1;
            }
            else {
                left = split1;
            }
        }
        split1 = left;
        split2 = split - split1;
        int nums1LeftMax = split1==0?INT32_MIN:nums1[split1-1];
        int nums1RightMin = split1==m?INT32_MAX:nums1[split1];
        int nums2LeftMax = split2==0?INT32_MIN:nums2[split2-1];
        int nums2RightMin = split2==n?INT32_MAX:nums2[split2];
        if((m+n)%2 == 0) {
            //return double(nums1[split1-1]+ nums2[split-split1])/2.0;
//            return double((nums1[split1-1]>nums2[split2-1]?nums1[split1-1]:nums2[split2-1])+
//                            (nums1[split1]<nums2[split2]?nums1[split1]:nums2[split2]))/2.0;
            return (max(nums1LeftMax,nums2LeftMax)+min(nums1RightMin,nums2RightMin))/2.0;
        }
        else {
            return max(nums1LeftMax,nums2LeftMax);
        }
    }

};