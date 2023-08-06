/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class NumArray {
   private:
    vector<int> pre_sum;

   public:
    NumArray(vector<int>& nums) { 
        pre_sum = get_prefix_sum(nums); 
    }

    int sumRange(int left, int right) { 
        return pre_sum[right + 1] - pre_sum[left]; 
    }

    vector<int> get_prefix_sum(vector<int>& nums) {
        vector<int> pre_sum(nums.size() + 1, 0);

        for (int i = 1; i < pre_sum.size(); i++) {
            pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
        }

        return pre_sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
