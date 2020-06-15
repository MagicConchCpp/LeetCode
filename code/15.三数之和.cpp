/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        int k = 0;
        while(nums[k] <= 0 && k < len - 2) {
            int l = k + 1;
            int r = len - 1;
            while (l < r) {
                int sum = nums[k] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[k], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[++ l]) { }
                    while (l < r && nums[r] == nums[-- r]) { }   
                }
                else if (sum < 0) {
                    ++ l;
                }
                else {
                    -- r;
                }               
            }
            while (k < len - 2 && nums[k] == nums[++ k]) { }
        }
        return res;
    }
};
// @lc code=end

