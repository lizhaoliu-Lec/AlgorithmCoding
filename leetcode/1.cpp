/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 记录整数到索引的位置
        unordered_map<int, stack<int>> val2indexes;
        for (int i = 0; i < nums.size(); i++) {
            if (val2indexes.find(nums[i]) == val2indexes.end()) {
                val2indexes[nums[i]] = stack<int>();
            }
            val2indexes[nums[i]].push(i);
        }
        // 对数组进行排序
        sort(nums.begin(), nums.end());
        // 左右指针
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            // int val_l, val_r = nums[left], nums[right];
            int val_l = nums[left], val_r = nums[right];
            int sum = val_l + val_r;

            if (sum == target) {
                int left_index = val2indexes[val_l].top();
                val2indexes[val_l].pop();
                int right_index = val2indexes[val_r].top();
                val2indexes[val_r].pop();
                return {left_index, right_index};
            } else if (sum < target) {
                left += 1;
            } else if (sum > target) {
                right -= 1;
            }
        }

        return {-1, -1};
    }

    void TestCase() {
        vector<int> nums = {2, 7, 11, 15};
        vector<int> ret = twoSum(nums, 9);
    }
};
// @lc code=end
int main() {
    Solution().TestCase();
    return 0;
}