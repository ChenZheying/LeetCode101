//
// Created by 陈哲英 on 2021/11/22.
//
#include <vector>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m==0&&n==0) {
            return -1;
        }
        else if (m==0) {
            nums1.push_back(nums2[n-1]);
            nums2.pop_back();
        }
        else if(n==0){
            nums2.push_back(nums1[m-1]);
            nums1.pop_back();
        }
        int p1 = 0, p2 = 0;

        int length = m+n;
        double result = 0;
        if(length % 2 == 1) {
            for (int i = length/2 - 1; i > 0 ; --i) {
                if(nums1[p1]<= nums2[p2]) {
                    ++p1;
                }
                else {
                    ++p2;
                }
                if(p1>=m) {
                    for (int j = i-1; j >0 ; --j) {
                        ++p2;
                    }
                    break;
                }
                else if (p2>=n) {
                    for (int j = i-1; j >0 ; --j) {
                        ++p1;
                    }
                    break;
                }
            }
            if(p1>=m){
                result = nums2[length/2-m];
            }
            else if(p2>=n) {
                result = nums1[length/2-n];
            }else {
                if (nums1[p1] <= nums2[p2]) {
                    ++p1;
                    if (p1 < m) {
                        result = nums1[p1] <= nums2[p2] ? nums1[p1] : nums2[p2];
                    } else {
                        result = nums2[p2];
                    }
                } else {
                    ++p2;
                    if (p2 < n) { result = nums2[p2] > nums1[p1] ? nums1[p1] : nums2[p2]; }
                    else {
                        result = nums1[p1];
                    }
                }
            }
        }
        else {
            for (int i = length/2-1; i > 0; --i) {
                if(nums1[p1]<= nums2[p2]) {
                    ++p1;
                }
                else {
                    ++p2;
                }
                if(p1>=m) {
                    for (int j = i-1; j >0 ; --j) {
                        ++p2;
                    }
                    break;
                }
                else if (p2>=n) {
                    for (int j = i-1; j >0 ; --j) {
                        ++p1;
                    }
                    break;
                }
            }
            if(p1>=m){
                result = (double(nums2[p2])+double(nums2[p2+1]))/2.0;
            }
            else if(p2>=n) {
                result = (double(nums1[p1])+double(nums1[p1+1]))/2.0;
            }else {
                if (nums1[p1] <= nums2[p2]) {
                    result += nums1[p1];
                    ++p1;
                } else {
                    result += nums2[p2];
                    ++p2;
                }
                if (p1 >= m) {
                    result = (double(result) + double(nums2[p2])) / 2.0;
                } else if (p2 >= n) {
                    result = (double(result) + double(nums1[p1])) / 2.0;
                } else {
                    result = (double(result) + double(nums1[p1] <= nums2[p2] ? nums1[p1] : nums2[p2])) / 2.0;
                }
            }
        }
        return result;
    }
};