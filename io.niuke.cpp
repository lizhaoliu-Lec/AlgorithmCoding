#include <bits/stdc++.h>
#include <iostream>
#include "basic_struct/array.h"
#include <bits/stdc++.h>

using namespace std;

using namespace std;


void test1() {
    int N;
    cin >> N;

    vector<string> data;
    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        data.push_back(tmp);
    }

    print_array(data, "test1");
}

void test2() {
    vector<vector<int>> data;
    string tmp;
    char sep = ' ';
    while (getline(cin, tmp)) {
        vector<int> _d;
        stringstream ss(tmp);
        bool first = true;
        while (getline(ss, tmp, sep)) {
            // 不要第一个数据
            if (!first) {
                _d.push_back(stoi(tmp));
            }
            first = false;
        }
        data.push_back(_d);
    }

    print_array_2d(data, "test2");
}

void test2_v2() {
    vector<vector<int>> data;
    int N;
    while (cin >> N) {
        vector<int> _d;
        int tmp;
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            _d.push_back(tmp);
        }
        data.push_back(_d);
    }

    print_array_2d(data, "test2_v2");
}

void test3() {
    int N;
    cin >> N;
    vector<vector<int>> data;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        vector<int> _d;
        int tmp;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            _d.push_back(tmp);
        }
        data.push_back(_d);
    }
    print_array_2d(data, "test3");
}

void test4() {
    int N;
    vector<vector<int>> data;
    while (cin >> N) {
        if (N == 0) {
            break;
        }
        vector<int> _d;
        int tmp;
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            _d.push_back(tmp);
        }
        data.push_back(_d);
    }
    print_array_2d(data, "test4");
}

void test5() {
    vector<vector<int>> data;
    string tmp;
    char sep = ' ';

    while (getline(cin, tmp)) {
        stringstream ss(tmp);
        vector<int> _d;
        while (getline(ss, tmp, sep)) {
            _d.push_back(stoi(tmp));
        }
        data.push_back(_d);
    }

    print_array_2d(data, "test5");
}

void test6() {
    vector<vector<int>> data;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        vector<int> _d;
        while (cin >> tmp) {
            _d.push_back(tmp);
            if (cin.get() == '\n') {
                break;
            }
        }
        data.push_back(_d);
    }
    print_array_2d(data, "test6");
}

void test7() {
    vector<vector<int>> data;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        data.push_back({a, b});
    }

    print_array_2d(data, "test7");
}

int main() {
    // test1();
    // test2();
    // test2_v2();
    // test3();
    // test4();
    // test5();
    // test6();
    test7();
    return 0;
}