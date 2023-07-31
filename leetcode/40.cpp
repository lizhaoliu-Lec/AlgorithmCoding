/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int track_sum = 0;
        vector<int> track;
        vector<vector<int>> rets;
        // 对数组进行排序
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target, track_sum, track, rets);

        return rets;
    }

    void backtrack(vector<int>& nums,
                   int start,
                   int target,
                   int track_sum,
                   vector<int>& track,
                   vector<vector<int>>& rets) {
        if (track_sum > target) { // 直接结束遍历即可
            return;
        }
        if (track_sum == target) {
            rets.push_back(track);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            // 做选择
            track.push_back(nums[i]);
            track_sum += nums[i];
            // 递归遍历
            backtrack(nums, i + 1, target, track_sum, track, rets);
            // 撤销选择
            track.pop_back();
            track_sum -= nums[i];
        }
    }
};
// @lc code=end
