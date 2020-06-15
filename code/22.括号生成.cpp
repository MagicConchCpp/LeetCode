/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    int N;
    vector<string> generateParenthesis(int n) {
        N = n;
        string s = "";
        recur(1, 0, s + "(");
        return res;
    }
    void recur(int left, int right, const string &s) {
        if (left + right == 2 * N) {
            res.push_back(s);
            return;
        }
        if (left < N && left > right) {
            recur(left + 1, right, s + "(");
            recur(left, right + 1, s + ")");
        } else if (left == N) {
            recur(left, right + 1, s + ")");
        } else if (left == right) {
            recur(left + 1, right, s + "(");
        }
    }
};
// @lc code=end

