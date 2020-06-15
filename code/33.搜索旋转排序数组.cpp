/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return -1;
        int beg = 0, end = nums.size() - 1;
        int mid = beg + (end - beg) / 2;
        while (beg <= end) {
            if (nums[mid] == target)
                return mid;
            // beg~mid是单调递增的
            if (nums[beg] <= nums[mid]) {
                if (nums[beg] <= target && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    beg = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[end]) {
                    beg = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            mid = beg + (end - beg) / 2;
        }
        return -1;
    }
};
// @lc code=end
