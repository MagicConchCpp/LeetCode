/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap= { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                     {'C', 100}, {'D', 500}, {'M', 1000} };
        int n = s.size();
        int num[n];
        int sum = 0;
        for (auto i = 0; i < n; ++ i) {
            num[i] = romanMap[s[i]];
        }
        if (n == 1)
            return romanMap[s[0]];
        for (auto i = 0; i < n - 1; ++ i) {
            if (num[i] < num[i + 1]) {
                sum = sum + num[i + 1] - num[i];
                i ++;
            }
            else 
                sum += num[i];
        }
        if (num[n - 2] >= num[n - 1]) 
            sum += num[n-1];
        return sum;
    }
};
// @lc code=end
