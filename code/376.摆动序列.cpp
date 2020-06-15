/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int res = 1;
        bool bigger = (nums[1] >= nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if ((nums[i] >= nums[i - 1]) != bigger) {
                ++res;
                bigger = !bigger;
            }
        }
        return res;
    }
};
// @lc code=end
