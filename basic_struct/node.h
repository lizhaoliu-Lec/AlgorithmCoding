#ifndef NODE
#define NODE
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* construct_plain_ntree(vector<int>& nums);

void print_level_ntree(Node* root, string name);

void print_level_linked_ntree(Node* root, string name);

#endif  // NODE