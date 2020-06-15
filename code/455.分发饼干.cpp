/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;
        for (int i = 0; i < s.size() && child < g.size(); ++i) {
            if (g[child] <= s[i])
                ++child;
        }
        return child;
    }
    
};
// @lc code=end

