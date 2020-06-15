/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        bool positive = ((dividend ^ divisor) & 0x80000000) == 0;
        if (divisor > 0)
            divisor = -divisor; 
        if (dividend > 0)
            dividend = -dividend; 
        recursive(dividend, divisor, res);
        // 结果为正
        if (positive) {
            if (res == INT_MIN)
                return INT_MAX;
            else
                return -res;
        }
        return res;
    }
    void recursive(const int dividend, const int divisor, int& res) {
        int sum = divisor;
        int power = 1;
        while (sum >= dividend) {
            res -= power;
            if (sum < (INT_MIN - divisor * power)) {
                break;
            }
            power++;
            if (sum < dividend - divisor * power)
                break;
            sum += divisor * power;  
        }
        if (power == 1)
            return;
        else 
            recursive(dividend - sum, divisor, res);     
    }
};
// @lc code=end

