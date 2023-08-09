/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int ret = INT_MIN;
        while (right < s.size()) {
            char val_r = s[right];
            right += 1;
            window[val_r] += 1;

            while (window[val_r] > 1) {
                char val_l = s[left];
                left += 1;
                window[val_l] -= 1;
            }
            ret = max(ret, right - left);
        }

        return ret == INT_MIN ? 0 : ret;
    }
};
// @lc code=end
