#include "btree_node.h"

void print_btree_helper(TreeNode* root,
                        int start,
                        int end,
                        int level,
                        vector<vector<char>>& to_print) {
    if (root == nullptr || start > end) {  // 当 到达空节点，或者没有元素时，返回
        return;
    }
    int mid = start + (end - start) / 2;
    to_print[level][mid] = '0' + root->val;  // 打印当前节点数字
    if (root->left != nullptr) {
        int sub_start = start;
        int sub_end = mid - 2;
        int sub_mid = sub_start + (sub_end - sub_start) / 2;
        int arrow_index = sub_mid + (mid - sub_mid) / 2;
        to_print[level + 1][arrow_index] = '/';  // 打印左子树的连接线
        // 递归遍历左子树
        print_btree_helper(root->left, sub_start, sub_end, level + 2,
                           to_print);  // level 要加2，因为连接线占用了一层
    }
    if (root->right != nullptr) {
        int sub_start = mid + 2;
        int sub_end = end;
        int sub_mid = sub_start + (sub_end - sub_start) / 2;
        int arrow_index = mid + (sub_mid - mid) / 2;
        to_print[level + 1][arrow_index] = '\\';  // 打印右子树的连接线
        // 递归遍历右子树
        print_btree_helper(root->right, sub_start, sub_end, level + 2,
                           to_print);  // level 要加2，因为连接线占用了一层
    }
}

void print_btree(TreeNode* root, int last_space) {
    if (root == nullptr) {
        cout << "BTree is: " << endl;
        return;
    }
    // init the 2d char vector to print
    int btree_depth = depth_of_btree(root);
    int num_row = btree_depth + btree_depth - 1;  // num_digits + num_space_between
    int num_ele_last_row = pow(2, btree_depth - 1);
    int num_col = num_ele_last_row + (num_ele_last_row - 1) * 3;
    vector<vector<char>> to_print = create_array_2d<char>(num_row, num_col, ' ');
    print_btree_helper(root, 0, num_col - 1, 0, to_print);  // 闭区间
    // 最终打印结果
    print_array_2d(to_print, "BTree is: ");
}

void print_btree_v2(TreeNode* root, string name, int last_space) {
    if (root == nullptr) {
        cout << "BTree " << name << " is: " << endl;
        return;
    }
    // init the 2d char vector to print
    int btree_depth = depth_of_btree(root);
    int num_row = btree_depth + btree_depth - 1;  // num_digits + num_space_between
    int num_ele_last_row = pow(2, btree_depth - 1);
    int num_col = num_ele_last_row + (num_ele_last_row - 1) * 3;
    vector<vector<char>> to_print = create_array_2d<char>(num_row, num_col, ' ');
    print_btree_helper(root, 0, num_col - 1, 0, to_print);  // 闭区间
    // 最终打印结果
    print_array_2d(to_print, "BTree " + name + " is: ");
}

TreeNode* construct_btree_helper(vector<int>& nums, int start, int end, bool skip) {
    if (start > end) {  // 闭区间
        return nullptr;
    }
    if (skip && nums[start] == -1) {  // -1 代表该节点不存在
        return nullptr;
    }
    TreeNode* root = new TreeNode(nums[start]);
    int sub_len = (end - start) / 2;
    int left_start = start + 1;
    int left_end = left_start + sub_len - 1;
    int right_start = start + sub_len + 1;
    int right_end = right_start + sub_len - 1;

    root->left = construct_btree_helper(nums, left_start, left_end, skip);
    root->right = construct_btree_helper(nums, right_start, right_end, skip);

    return root;
}

TreeNode* construct_btree(vector<int>& nums) {
    return construct_btree_helper(nums, 0, nums.size() - 1, false);
}

TreeNode* construct_btree_v2(vector<int>& nums) {
    return construct_btree_helper(nums, 0, nums.size() - 1, true);
}

TreeNode* construct_btree_preorder_helper(vector<int>& nums, int& start) {
    if (start >= nums.size()) {
        return nullptr;
    }
    if (nums[start] == -1) {  // 遇到非法值
        start++;
        return nullptr;
    }
    TreeNode* root = new TreeNode(nums[start]);
    start++;
    root->left = construct_btree_preorder_helper(nums, start);
    root->right = construct_btree_preorder_helper(nums, start);

    return root;
}

TreeNode* construct_btree_preorder(vector<int>& nums) {
    int start = 0;
    return construct_btree_preorder_helper(nums, start);
}

void print_level_btree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            TreeNode* tmp = q.front();
            q.pop();

            if (tmp->left != nullptr) {
                q.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                q.push(tmp->right);
            }

            cout << tmp->val;
            if (i != q_size - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

void print_level_btree(TreeNode* root, string name) {
    cout << "BTree " << name << " is:" << endl;
    print_level_btree(root);
}

int depth_of_btree(TreeNode* root) {
    if (root == nullptr) {  // 终止条件，遍历到叶子节点的下一层，返回深度 0
        return 0;
    }
    int left_depth = 1 + depth_of_btree(root->left);
    int right_depth = 1 + depth_of_btree(root->right);

    if (left_depth > right_depth) {
        return left_depth;
    } else {
        return right_depth;
    }
}

void pre_order_traverse_helper(TreeNode* root, vector<int>& ret) {
    if (root == nullptr) {
        return;
    }
    ret.push_back(root->val);
    pre_order_traverse_helper(root->left, ret);
    pre_order_traverse_helper(root->right, ret);
}

vector<int> pre_order_traverse(TreeNode* root) {
    vector<int> ret;

    pre_order_traverse_helper(root, ret);

    return ret;
}

void print_indent_btree_helper(TreeNode* root, int num_indent) {
    if (root == nullptr) {
        return;
    }
    print_indent(num_indent);
    cout << "val: " << root->val << endl;
    print_indent_btree_helper(root->left, num_indent + 1);
    print_indent_btree_helper(root->right, num_indent + 1);
}

void print_indent_btree(TreeNode* root, string name) {
    cout << "BTree " << name << " is:" << endl;
    print_indent_btree_helper(root, 0);
}