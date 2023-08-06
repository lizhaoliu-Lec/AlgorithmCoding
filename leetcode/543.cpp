/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
#include <bits/stdc++.h>
#include <basic_struct/btree_node.h>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        traverse(root, max_diameter);
        return max_diameter;
    }

    int traverse(TreeNode* root, int& max_diameter){
        if(root == nullptr){
            return 0;
        }

        int left_depth = traverse(root->left, max_diameter);
        int right_depth = traverse(root->right, max_diameter);

        int cur_diameter = left_depth + right_depth;

        max_diameter = max(max_diameter, cur_diameter);

        return 1 + max(left_depth, right_depth);
    }
};
// @lc code=end

