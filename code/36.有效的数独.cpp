/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row[9], col[9], blk[9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    if (!row[i].insert(c).second ||
                        !col[j].insert(c).second ||
                        !blk[i / 3 * 3+ j / 3].insert(c).second)
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
