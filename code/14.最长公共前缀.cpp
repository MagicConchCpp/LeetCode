/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto iter = strs.begin();
        string res = "";
        int maxSize = 0;
        for (auto i = 0; i < strs.size(); ++ i) {
            if ((*(iter + i)).size() > maxSize)
                maxSize = (*(iter + i)).size();
        }
        for (auto i = 0; i < maxSize; ++ i) {
            for (auto j = 0; j < strs.size() - 1; ++ j) {
                if ((*(iter + j))[i] != (*(iter + j + 1))[i]) {
                    return res;
                }
            }
            res += (*iter)[i];
        }
        return res;
    }
};
// @lc code=end
