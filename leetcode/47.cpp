/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 对数组进行排序
        sort(nums.begin(), nums.end());

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
            if (used[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            // 做选择
            track.push_back(nums[i]);
            used[i] = true;
            // 递归调用
            backtrack(nums, used, track, rets);
            // 撤销选择
            track.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end
