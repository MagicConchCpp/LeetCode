/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> m = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
                                {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
        queue<string> q;
        vector<string> res;
        // 先处理第一个数字。是为了使q不为空。
        for (auto i : m[digits[0]]) {
            string s(1, i);
            q.push(s);
        }  
        for (auto i = 1; i < digits.size(); ++ i) {
            int len = q.size();
            for (auto j = 0; j < len; ++ j) {
                string s = q.front();
                for (auto k = 0; k < m[digits[i]].size(); ++ k) {
                    q.push(s + m[digits[i]][k]);
                }
                q.pop();
            }
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
    return res;
    }
};
// @lc code=end

