/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int valid = 0;

        for (int i = 0; i < s1.size(); i++) {
            need[s1[i]] += 1;
        }

        int left = 0, right = 0;
        while (right < s2.size()) {
            char val_r = s2[right];
            right += 1;

            if (need.count(val_r)) {
                window[val_r] += 1;
                if (need[val_r] == window[val_r]) {
                    valid += 1;
                }
            }

            while (right - left >= s1.size()) {
                if (valid == need.size()) {
                    return true;
                }

                char val_l = s2[left];
                left += 1;

                if (need.count(val_l)) {
                    if (need[val_l] == window[val_l]) {
                        valid -= 1;
                    }
                    window[val_l] -= 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end
