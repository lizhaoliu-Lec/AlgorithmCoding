/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = left_bound(nums, target);
        int right = right_bound(nums, target);
        return {left, right};
    }

    int left_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = nums[mid];
            if (val == target) {
                right = mid - 1;  // 若 target 存在, right 最终会刚好卡在 target 前面
            } else if (val < target) {
                left = mid + 1;  // left 指针一直向前移动, 直到结束或者碰到 target
            } else if (val > target) {
                right = mid - 1;
            }
        }

        // left 一直右移可能产生越界
        if (left >= nums.size()) {
            return -1;
        }

        // 判断 left 是否右移到了 target 所在位置
        return nums[left] == target ? left : -1;
    }

    int right_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = nums[mid];
            if (val == target) {
                left += 1;  // 若 target 存在, left 最终会刚好卡在 target 前面
            } else if (val < target) {
                left = mid + 1;
            } else if (val > target) {
                right = mid - 1;  // right 指针一直向左移动, 直到结束或者碰到 target
            }
        }

        // right 一直左移可能会产生越界
        if (right < 0) {
            return -1;
        }

        // 判断 right 是否左移到了 target 所在位置
        return nums[right] == target ? right : -1;
    }
};
// @lc code=end
