/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class NumMatrix {
   private:
    vector<vector<int>> pre_sum;

   public:
    NumMatrix(vector<vector<int>>& matrix) { pre_sum = get_pre_sum(matrix); }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre_sum[row2 + 1][col2 + 1] - pre_sum[row1][col2 + 1] - pre_sum[row2 + 1][col1] + pre_sum[row1][col1];
    }

    vector<vector<int>> get_pre_sum(vector<vector<int>>& matrix) {
        int num_row = matrix.size();
        int num_col = matrix[0].size();

        vector<vector<int>> pre_sum(num_row + 1, vector<int>(num_col + 1, 0));
        for (int i = 1; i < num_row + 1; i++) {
            for (int j = 1; j < num_col + 1; j++) {
                pre_sum[i][j] = pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        return pre_sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
