/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ivec;
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target)
                r = mid;
            else 
                l = mid + 1;
        }
        // 只会在右侧可能会数组越界，左侧不会，因为我们取的是下中位数
        if (l < nums.size() && nums[l] == target)
            ivec.push_back(l);
        else
            return {-1, -1};
        r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                l = mid + 1;
            else
                r = mid;
        }
        ivec.push_back(l - 1);
        return ivec;
    }
};
// @lc code=end

        // vector<int> res = {-1, -1};
        // int left = 0, right = nums.size() - 1;
        // int mid = left + (right - left) / 2;
        // while (nums[mid] != target) {
        //     if (nums[mid] > target)
        //         right = mid + 1;
        //     else if (nums[mid] < target)
        //         left = mid - 1;
        //     mid = left + (right - left) / 2;
        // }
        // int right1 = mid;
        // int left1 = left;
        // int mid1 = left1 + (right1 - left1) / 2;
        // while (left1 < right1) {
        //     if (nums[mid1] == target) {
        //         if (mid1 == 0) {
        //             res[0] = 0;
        //             break;
        //         } else if (nums[mid1] != nums[mid1 - 1]) {
        //             res[0] = mid1;
        //             break;
        //         }
        //     }
        //     if (nums[mid1] < target)
        //         left1 = mid1 + 1;
        //     else
        //         right1 = mid1 - 1;
        //     mid1 = left1 + (right1 - left1) / 2;
        // }
        // int left2 = mid;
        // int right2 = right;
        // int mid2 = left2 + (right2 - left2) / 2;
        // while (left2 < right2) {
        //     if (nums[mid2] == target) {
        //         if (mid2 == nums.size() - 1) {
        //             res[1] = 0;
        //             break;
        //         } else if (nums[mid2] != nums[mid2 + 1]) {
        //             res[1] = mid2;
        //             break;
        //         }
        //     }
        //     if (nums[mid] > target)
        //         right2 = mid2 - 1;
        //     else
        //         left2 = mid2 + 1;
        //     mid2 = left2 + (right2 - left2) / 2;
        // }
        // return vector<int>({mid1, mid2});