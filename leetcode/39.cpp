/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int track_sum = 0;
        vector<int> track;
        vector<vector<int>> rets;

        bactrack(candidates, target, 0, track_sum, track, rets);

        return rets;
    }

    void bactrack(vector<int>& nums,
                  int target,
                  int start,
                  int track_sum,
                  vector<int>& track,
                  vector<vector<int>>& rets) {
        if (track_sum > target) {
            return;
        }
        if (track_sum == target) {
            rets.push_back(track);
        }
        for (int i = start; i < nums.size(); i++) {
            // 做选择
            track.push_back(nums[i]);
            track_sum += nums[i];
            // 递归遍历
            bactrack(nums, target, i, track_sum, track, rets);
            // 撤销选择
            track.pop_back();
            track_sum -= nums[i];
        }
    }
};
// @lc code=end
