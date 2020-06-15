/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = l + (r - l) / 2;
        while (l <= r) {
            if (nums[mid] == target)
                return true;
            if (nums[l] == nums[mid]) {
                ++l;
            } else if (nums[l] < nums[mid] ) {
                if (nums[l] <= target && target <= nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;         
            } else {
                if (nums[mid] <= target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;           
            }
            mid = l + (r - l) / 2;
        }
        return false;
    }
};
// @lc code=end

