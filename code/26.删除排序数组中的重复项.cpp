/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int index = 0;
        for (auto i = 1; i < n; ++ i) {
            if (nums[i] != nums[i - 1]) {
                index ++;
                nums[index] = nums[i]; 
            }
        }
        return index + 1;
    }
};
// @lc code=end

