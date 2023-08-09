/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int valid = 0;
        vector<int> rets;

        for (int i = 0; i < p.size(); i++) {
            need[p[i]] += 1;
        }

        int left = 0, right = 0;
        while (right < s.size()) {
            char val_r = s[right];
            right += 1;

            if (need.count(val_r)) {
                window[val_r] += 1;
                if (window[val_r] == need[val_r]) {
                    valid += 1;
                }
            }

            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    rets.push_back(left);
                }

                char val_l = s[left];
                left += 1;

                if (need.count(val_l)) {
                    if (window[val_l] == need[val_l]) {
                        valid -= 1;
                    }
                    window[val_l] -= 1;
                }
            }
        }

        return rets;
    }
};
// @lc code=end
