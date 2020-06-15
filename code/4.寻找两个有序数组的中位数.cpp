/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start

#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    }
    int findKth(vector<int>& nums1, vector<int> nums2, int k) {
        int i = 0, j = 0;
        while (i + j + 2 < k) {
            if (i < nums1.size() && nums1[i] < nums2[j]) {
                i ++;
            } else if (j < nums2.size() && nums1[i] >= nums2[j]){
                j ++;
            }
                
        }
        return 1;
    }
};
// @lc code=end

