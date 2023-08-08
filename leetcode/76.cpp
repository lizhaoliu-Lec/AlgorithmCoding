/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int valid = 0;

        for (int i = 0; i < t.size(); i++) {
            need[t[i]] += 1;
        }

        int left = 0, right = 0;
        // 记录最小覆盖子串的起始索引及长度
        int start = 0, len = INT_MAX;

        while (right < s.size()) {
            // 右指针取值，并扩大窗口
            char val_r = s[right];
            right++;
            // 更新窗口数据
            if (need.count(val_r)) {
                window[val_r] += 1;
                if (window[val_r] == need[val_r]) {
                    valid += 1;
                }
            }

            // 符合条件时，左窗口收缩
            while (valid == need.size()) {
                // 更新最小覆盖字串
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                // 左窗口取值
                char val_l = s[left];
                left++;
                // 更新窗口数据
                if (need.count(val_l)) {
                    if (window[val_l] == need[val_l]) {
                        valid -= 1;
                    }
                }
                window[val_l] -= 1;
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end
