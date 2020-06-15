/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    set<int> all = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    void solveSudoku(vector<vector<char>>& board) {
        set<int> row[9], col[9], blk[9];
        set<int> b[9][9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - 48;
                    row[i].insert(num);
                    col[j].insert(num);
                    blk[i/3*3 + j/3].insert(num);
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    set<int> tempSet;
                    tempSet.insert(row[i].begin(), row[i].end());
                    tempSet.insert(col[i].begin(), col[j].end());
                    tempSet.insert(blk[i/3*3 + j/3].begin(), blk[i/3*3 + j/3].end());
                    set_difference(all.cbegin(), all.cend(), tempSet.cbegin(),
                        tempSet.cend(), inserter(b[i][j], b[i][j].begin()));
                }
            }
        }
    }
};
// @lc code=end

