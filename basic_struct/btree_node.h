#ifndef BTREE_NODE
#define BTREE_NODE
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include "array.h"
#include "btree_node.h"
#include "utils.h"
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void print_btree(TreeNode* root, int last_space);

void print_btree_v2(TreeNode* root, string name, int last_space);

TreeNode* construct_btree(vector<int>& nums);

TreeNode* construct_btree_v2(vector<int>& nums);

TreeNode* construct_btree_preorder(vector<int>& nums);

void print_level_btree(TreeNode* root);

void print_level_btree(TreeNode* root, string name);

int depth_of_btree(TreeNode* root);

vector<int> pre_order_traverse(TreeNode* root);

void print_indent_btree(TreeNode* root, string name);

#endif  // BTREE_NODE