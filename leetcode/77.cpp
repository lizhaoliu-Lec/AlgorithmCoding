/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        vector<vector<int>> rets;

        backtrack(1, n, k, track, rets);

        return rets;
    }

    void backtrack(int start, int n, int k, vector<int>& track, vector<vector<int>>& rets) {
        if (track.size() == k) {
            rets.push_back(track);
            return;
        }
        for (int i = start; i <= n; i++) {
            // 做选择
            track.push_back(i);
            // 递归遍历
            backtrack(i + 1, n, k, track, rets);
            // 撤销选择
            track.pop_back();
        }
    }
};
// @lc code=end
