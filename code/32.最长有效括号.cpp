/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        deque<int> q;
        int max_len = 0;
        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] == ')' && !q.empty() && s[q.back()] == '(')
                q.pop_back();
            else
                q.push_back(i);
        }
        if (q.empty())
            return s.size();
        q.push_front(-1);
        q.push_back(s.size());
        for (int i = 1; i < q.size(); ++ i)
            max_len = max(max_len, q[i] - q[i - 1] - 1);
        return max_len;
    }
};
// @lc code=end

