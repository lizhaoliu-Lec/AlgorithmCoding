#include "utils.h"

template <typename T>
void print_tuple(string k1, T v1, string k2, T v2) {
    cout << "(" << k1 << ", " << k2 << "): ";
    cout << "(" << v1 << ", " << v2 << ")" << endl;
}

template <typename T>
void print_tuple(string k1, T v1, string k2, T v2, string name) {
    cout << "[" << name << "]"
         << " is: ";
    print_tuple(k1, v1, k2, v2);
}

void print_indent(int n) {
    for (int i = 0; i < n; i++) {
        // cout << "  ";
        cout << "\t";
        // cout << n;
    }
}

void print_indent(int n, string name) {
    for (int i = 0; i < n; i++) {
        // cout << "  ";
        cout << "\t";
        // cout << n;
    }
    cout << "[" << name << "] ";
}

/* An example for using print indent
(1) print_indent(count++); call when in a new function
(2) print_indent(--count); call right before return
int dp(string& ring, int i, string& key, int j) {
    // printIndent(count++);
    // printf("i = %d, j = %d\n", i, j);

    if (j == key.size()) {
        // printIndent(--count);
        // printf("return 0\n");
        return 0;
    }

    int res = INT_MAX;
    for (int k : charToIndex[key[j]]) {
        res = min(res, dp(ring, j, key, i + 1));
    }

    // printIndent(--count);
    // printf("return %d\n", res);
    return res;
}
*/

int randint(int low, int high) {
    assert(low <= high);
    return rand() % (high - low + 1) + low;
}

template void print_tuple(string k1, int v1, string k2, int v2);
template void print_tuple(string k1, char v1, string k2, char v2);
template void print_tuple(string k1, double v1, string k2, double v2);
template void print_tuple(string k1, string v1, string k2, string v2);

template void print_tuple(string k1, int v1, string k2, int v2, string name);
template void print_tuple(string k1, char v1, string k2, char v2, string name);
template void print_tuple(string k1, double v1, string k2, double v2, string name);
template void print_tuple(string k1, string v1, string k2, string v2, string name);