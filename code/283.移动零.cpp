/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // for (int i = 0, j = 0; i < nums.size(); ++i) {
        //     if (nums[j] != 0) {
        //         ++j;
        //         continue;
        //     }
        //     if (nums[i] != 0)
        //         swap(nums[i], nums[j++]);
        // }
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i != j)
                    swap(nums[i], nums[j++]);
                else
                    j++;
            }
                
        }
    }
};
// @lc code=end

