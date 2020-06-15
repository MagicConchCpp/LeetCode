/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxS = 0;
        while (left != right) {
            if (height[left] < height[right])
                maxS = max(maxS, (right - left) * height[left ++]);
            else
                maxS = max(maxS, (right - left) * height[right --]);
        }
        return maxS;        
    }
};
// @lc code=end

