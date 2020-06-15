/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> m = { {'(', ')'}, {'[', ']'}, {'{', '}'} };
        for (auto c : s) {
            if (!st.empty() && m[st.top()] == c) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
// @lc code=end

