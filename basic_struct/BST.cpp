#include "BST.h"

BST::BST() {
    // nothing to do
}

BST::BST(vector<int> nums) {
    // 先对数字进行排序
    sort(nums.begin(), nums.end());

    // 采用中序遍历的方式插入
    this->root = inorder_build(nums, 0, nums.size() - 1);
}

TreeNode* BST::inorder_build(vector<int>& nums, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    // 确定根节点
    int index = start + (end - start) / 2;
    TreeNode* cur = new TreeNode(nums[index]);
    cur->left = inorder_build(nums, start, index - 1);
    cur->right = inorder_build(nums, index + 1, end);

    return cur;
}

TreeNode* BST::get_root() {
    return this->root;
}

TreeNode* BST::find(int val) {
    return find_helper(this->root, val);
}

TreeNode* BST::find_helper(TreeNode* cur, int val) {
    if (cur == nullptr || cur->val == val) {
        return cur;
    } else if (cur->val > val) {  // 当前节点值太大，去左子树搜
        return find_helper(cur->left, val);
    } else if (cur->val < val) {  // 当前节点值太小，去右子树搜
        return find_helper(cur->right, val);
    }
    return nullptr;  // 实在找不到了，返回空指针
}

TreeNode* BST::insert(int val) {
    this->root = insert_helper(root, val);
    return this->root;
}

TreeNode* BST::insert_helper(TreeNode* cur, int val) {
    // 主要还是检索的逻辑，到最后找不到了就生成
    if (cur == nullptr) {
        cur = new TreeNode(val);
    } else if (cur->val >= val) {  // 插入到左子树
        cur->left = insert_helper(cur->left, val);
    } else if (cur->val < val) {  // 插入到右子树
        cur->right = insert_helper(cur->right, val);
    }
    return cur;
}

TreeNode* BST::remove(int val) {
    this->root = remove_helper(root, val);
    return this->root;
}

TreeNode* BST::get_min(TreeNode* cur) {
    if (cur->left == nullptr) {  // 注意这里判断的是左子树是否为空，而不是cur
        return cur;
    }
    return get_min(cur->left);
}

TreeNode* BST::remove_helper(TreeNode* cur, int val) {
    // 找不到，直接返回空指针
    if (cur == nullptr) {
        return nullptr;
    }
    if (cur->val > val) {  // 去左子树删除
        cur->left = remove_helper(cur->left, val);
    } else if (cur->val < val) {  // 去右子树删除
        cur->right = remove_helper(cur->right, val);
    } else if (cur->val == val) {  // 找到节点了，即将删除
        // 三种情况
        if (cur->left == nullptr) {
            return cur->right;
        }
        if (cur->right == nullptr) {
            return cur->left;
        }
        // 左右子树都存在
        // 找到右子树的最小节点
        TreeNode* min = get_min(cur->right);
        // 暴力解法：直接交换 min 和 cur 的 val，然后把 min 删了
        // 但这样操作并不完美，我们一般不会通过修改节点内部的值来交换节点。因为在实际应用中，BST
        // 节点内部的数据域是用户自定义的，可以非常复杂，而 BST
        // 作为数据结构（一个工具人），其操作应该和内部存储的数据域解耦
        // cur->val = min->val;  // 用最小节点的值覆盖要删除的节点
        // // 删除最小值节点
        // cur->right = remove_helper(cur->right, min->val);
        root->right = remove_helper(root->right, min->val);
        min->left = root->left;
        min->right = root->right;
        root = min;
    }

    return cur;
}

TreeNode* BST::find_range(int low, int high) {
    return find_range_helper(this->root, low, high);
}

TreeNode* BST::find_range_helper(TreeNode* cur, int low, int high) {
    if (cur == nullptr) {
        return nullptr;
    }

    int val = cur->val;
    if (val >= low && val <= high) {  // 继续修剪左子树和右子树
        cur->left = find_range_helper(cur->left, low, high);
        cur->right = find_range_helper(cur->right, low, high);
    } else if (val < low) {  // 当前值太小了，继续去右子树搜索
        return find_range_helper(cur->right, low, high);
    } else if (val > high) {  // 当前值太大了，继续去左子树搜索
        return find_range_helper(cur->left, low, high);
    }
    return cur;
}

void BST::rebuild(vector<int>& nums) {
    // 先对数字进行排序
    sort(nums.begin(), nums.end());

    // 采用中序遍历的方式插入
    this->root = inorder_build(nums, 0, nums.size() - 1);
}