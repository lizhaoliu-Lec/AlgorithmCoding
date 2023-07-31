/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x1 = max(ax1, bx1);
        int x2 = min(ax2, bx2);
        int y1 = max(ay1, by1);
        int y2 = min(ay2, by2);

        // x 轴相交区域 [max(ax1, bx1), min(ax2, bx2)]
        // y 轴相交区域 [max(ay1, by1), min(ay2, by2)]

        // 矩形 a 面积
        int area_a = area(ax1, ay1, ax2, ay2);
        // 矩形 b 面积
        int area_b = area(bx1, by1, bx2, by2);
        // 相交面积
        int area_u = 0;
        // 这里一定要注意，线段长度要大于 0 才说明有交集
        if (x2 - x1 > 0 && y2 - y1 > 0) {
            area_u = area(x1, y1, x2, y2);
        }

        return area_a + area_b - area_u;
    }

    int area(int x1, int y1, int x2, int y2) { return (x2 - x1) * (y2 - y1); }
};
// @lc code=end
