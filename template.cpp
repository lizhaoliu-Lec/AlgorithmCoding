#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print_tuple(string k1, T v1, string k2, T v2, string name) {
    cout << "[" << name << "]"
         << " is: ";
    cout << "(" << k1 << ", " << k2 << "): ";
    cout << "(" << v1 << ", " << v2 << ")" << endl;
}

template <typename T>
void print_array(vector<T> nums, string name) {
    if (name != "") {  // for reusing in print array 2d
        cout << "Array " << name << " is: ";
    }
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

template <typename T>
void print_array_2d(vector<vector<T>> array_2d, string name) {
    cout << "2D array " << name << " is: " << endl;
    for (int row = 0; row < array_2d.size(); row++) {
        print_array(array_2d[row], "");
    }
}

class Solution {
   public:
    void solve(){

    };
};

void TestCase1() {}

void TestCase2() {}

void TestCase3() {}

void TestCase4() {}

// local main
int main() {
    TestCase1();
    TestCase2();
    TestCase3();
    TestCase4();

    return 0;
}

// submit main
// int main() {
//     return 0;
// }