/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4)
            return res;
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < n - 3; ++ i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (auto k = i + 1; k < n - 2; ++ k) {
                if (k > i + 1 && nums[k] == nums[k - 1])
                    continue;
                int l = k + 1;
                int r = n - 1;
                while (l < r) {
                    int sum = nums[i] + nums[k] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[k], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[++ l]) { }
                        while (l < r && nums[r] == nums[--r ]) { }
                    }
                    else if (sum < target) {
                        ++ l;
                    }
                    else {
                        -- r;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

