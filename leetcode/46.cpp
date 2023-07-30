/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> track;
        vector<vector<int>> rets;

        backtrack(nums, used, track, rets);

        return rets;
    }

    void backtrack(vector<int>& nums,
                   vector<bool>& used,
                   vector<int>& track,
                   vector<vector<int>>& rets) {
        if (track.size() == nums.size()) {
            rets.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 排列不可使用重复元素
            if (used[i]) {
                continue;
            }
            // 做选择
            track.push_back(nums[i]);
            used[i] = true;
            // 递归遍历
            backtrack(nums, used, track, rets);
            // 撤销选择
            track.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end
