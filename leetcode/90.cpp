/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> track;
        vector<vector<int>> rets;

        // 包含重复元素的子集问题，要对数组进行排序
        // sort(nums.begin(), nums.end());

        backtrack(nums, 0, track, rets);

        return rets;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track, vector<vector<int>>& rets) {
        rets.push_back(track);

        for (int i = start; i < nums.size(); i++) {
            // 避免使用重复元素
            // 注意 i > start, 要排除的是除第一次外，不要出现重复乱序的现象
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            // 做选择
            track.push_back(nums[i]);
            // 递归遍历
            backtrack(nums, i + 1, track, rets);
            // 撤销选择
            track.pop_back();
        }
    }
};
// @lc code=end
