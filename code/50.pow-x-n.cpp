/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            if (n == INT_MIN) {
                n = INT_MAX;
                x *= x;
            } else {
                n = -n;
            }
        }
        return fastPow(x, n);
    }
    double fastPow(double x, int n) {
        if (n == 0) return 1.0;
        double half = fastPow(x, n / 2);
        if (n % 2)
            return x * half * half;
        else
            return half * half;
    }
};
// @lc code=end

