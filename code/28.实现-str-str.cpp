/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int m = needle.size();
        const int n = haystack.size();
        for (auto i = 0; i < n; ++ i) {
            int j = 0;
            for (j; j < m; ++ j) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == m)
                return i;
        }
        return -1;
    }     
};
// @lc code=end