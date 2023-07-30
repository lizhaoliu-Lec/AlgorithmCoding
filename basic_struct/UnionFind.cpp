#include "UnionFind.h"

UnionFind::UnionFind(int n) {
    this->_count = n;
    this->parent.resize(n, 0);
    for (int i = 0; i < n; i++) {
        // 初始时指向自己
        this->parent[i] = i;
    }
}

void UnionFind::union_(int p, int q) {
    // 先分别找到 root
    int root_p = find(p);
    int root_q = find(q);

    // 如果已经连接，无需继续操作，直接返回
    if (root_p == root_q) {
        return;
    } else {
        // 将 q 合并到 p 形成一个连通分量
        this->parent[root_q] = root_p;
        this->_count--;
    }
}

bool UnionFind::connected(int p, int q) {
    // 先分别找到 root
    int root_p = find(p);
    int root_q = find(q);

    return root_p == root_q;
}

int UnionFind::find(int x) {
    // return find_recursive(x);
    return find_iterative(x);
}

int UnionFind::find_recursive(int x) {
    // 注意要进行路径压缩
    // 递归实现

    if (parent[x] != x) {
        parent[x] = find_recursive(parent[x]);
    }

    return parent[x];
}

int UnionFind::find_iterative(int x) {
    // 注意要进行路径压缩
    // 迭代实现

    // 先找到根节点
    int root = x;
    while (parent[root] != root) {
        root = parent[root];
    }
    // 迭代将 x 及其路径上的点都连接到 root
    int old_p = parent[x];
    while (x != root) {
        parent[x] = root;
        x = old_p;  // 继续遍历当前节点的 旧 父节点
        old_p = parent[x];
    }

    return root;
}

int UnionFind::count() {
    return this->_count;
}