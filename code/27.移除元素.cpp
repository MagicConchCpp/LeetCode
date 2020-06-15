/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (auto elem : nums) {
            if (elem != val)
                nums[index ++] = elem;
        }
        return index;
    }
};
// @lc code=end

