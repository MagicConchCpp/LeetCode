/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int l = 1, r = x / 2;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long num = static_cast<long>(mid * mid);
            if (num > x)
                r = mid - 1;
            else if (num < x)
                l = mid + 1;
            else
                return mid;
        }
        return r;
    }
};
// @lc code=end

