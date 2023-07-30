#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include <algorithm>
#include <iostream>
#include "btree_node.h"
using namespace std;

class BST {
   private:
    TreeNode* root = nullptr;
    TreeNode* find_helper(TreeNode* cur, int val);
    TreeNode* insert_helper(TreeNode* cur, int val);
    TreeNode* remove_helper(TreeNode* cur, int val);
    TreeNode* get_min(TreeNode* cur);
    TreeNode* find_range_helper(TreeNode* cur, int low, int high);

   public:
    BST();
    BST(vector<int> nums);
    TreeNode* get_root();
    TreeNode* inorder_build(vector<int>& nums, int start, int end);
    TreeNode* find(int val);
    TreeNode* insert(int val);
    TreeNode* remove(int val);
    TreeNode* find_range(int low, int high);
    void rebuild(vector<int>& nums);
};

#endif  // BST