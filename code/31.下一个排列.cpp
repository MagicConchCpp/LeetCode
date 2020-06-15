/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        bool flag = false;
        int i = nums.size() - 2;
        int j = 0;
        for (; i >= 0; -- i) {
            for (j = nums.size() - 1; j >= i + 1; -- j) {
                if (nums[i] < nums[j]) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (i == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};
// @lc code=end

