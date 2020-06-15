/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        vector<int> v1, v2, B;
        v1 = fun1(A);
        reverse_copy(A.begin(), A.end(), B.begin());
        v2 = fun1(B);
        for (int i = 0; i < A.size(); ++i) {
            if (v1[i] == v2[i])
        }
    }

    vector<int> fun1(vector<int>& v) {
        vector<int> res(v.size(), 0);
        res[0] = v[0];
        for (int i = 1; i < v.size(); ++i) {
            res[i] = res[i - 1] + v[i];
        }
        return res;
    }
};
// @lc code=end

