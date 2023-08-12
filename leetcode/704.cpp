/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = nums[mid];
            if (val == target) {
                return mid;
            } else if (val < target) {
                left = mid + 1;
            } else if (val > target) {
                right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
