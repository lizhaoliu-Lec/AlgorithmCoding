/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<int> track;
        vector<vector<int>> rets;

        backtrack(nums, 0, track, rets);

        return rets;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track, vector<vector<int>>& rets) {
        // 空集也是结果
        rets.push_back(track);

        // 遍历所有选项
        for (int i = start; i < nums.size(); i++) {
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
