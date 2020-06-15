/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int sum;
        long res = INT_MAX;
        for (auto k = 0; k < nums.size() - 2; ++ k) {
            int l = k + 1;
            int r = nums.size() - 1;
            while (l < r) {
                sum = nums[k] + nums[l] + nums[r];
                if (abs(sum - target) < abs(res - target))
                        res = sum;
                if (sum < target) {
                    while (l < r && nums[l] == nums[++ l]) { }
                }
                else if (sum > target) {
                    while (l < r && nums[r] == nums[-- r]) { }
                }
                else {
                    return target;
                }           
            }
        }
        return res;
    }
};
// @lc code=end

