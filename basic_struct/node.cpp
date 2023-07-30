#include "node.h"

Node* construct_plain_ntree_helper(vector<int>& nums, int start, int end) {
    if (start > end) {  // 闭区间
        return nullptr;
    }

    Node* root = new Node(nums[start]);
    int len = (end - start) / 2;
    int left_start = start + 1, left_end = start + len;
    int right_start = start + len + 1, right_end = end;

    root->left = construct_plain_ntree_helper(nums, left_start, left_end);
    root->right = construct_plain_ntree_helper(nums, right_start, right_end);

    return root;
}

Node* construct_plain_ntree(vector<int>& nums) {
    return construct_plain_ntree_helper(nums, 0, nums.size() - 1);
}

void print_level_ntree(Node* root, string name) {
    cout << "NTree " << name << " is:" << endl;
    if (root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            Node* tmp = q.front();
            q.pop();
            cout << tmp->val << " ";

            if (tmp->left != nullptr) {
                q.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                q.push(tmp->right);
            }
        }
        cout << endl;
    }
}

void print_level_linked_ntree(Node* root, string name) {
    cout << "Linked NTree " << name << " is:" << endl;
    if (root == nullptr) {
        return;
    }
    Node* leftmost = root;
    vector<Node*> leftmost_list;
    while (leftmost != nullptr) {
        leftmost_list.push_back(leftmost);
        leftmost = leftmost->left;
    }
    // directly level print
    for (int i = 0; i < leftmost_list.size(); i++) {
        Node* cur = leftmost_list[i];
        while (cur != nullptr) {
            cout << cur->val << " ";
            if (cur->next != nullptr) {
                cout << "-> ";  // show connection here
            }
            cur = cur->next;
        }
        cout << endl;
    }
}
