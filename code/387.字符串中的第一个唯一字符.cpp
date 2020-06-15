/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++ i) {
            auto ret = m.insert({s[i], i});
            if (!ret.second)
                ret.first->second = s.size();
        }
        for(auto i : m) {
            cout << i.first << ": " << i.second << endl;
        }
        auto index = find_if(m.begin(), m.end(),
                            [](pair<char, int> p) { return p.second != -1; });
        return index->second;
    }
};
// @lc code=end

