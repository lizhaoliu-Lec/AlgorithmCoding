#ifndef UNION_FIND
#define UNION_FIND
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
   private:
    int _count = 0;
    vector<int> parent;

   public:
    UnionFind(int n);
    void union_(int p, int q);
    bool connected(int p, int q);
    int find(int x);
    int find_recursive(int x);
    int find_iterative(int x);
    int count();
};

#endif  // UNION_FIND