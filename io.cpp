#include <bits/stdc++.h>
#include <iostream>

#include "basic_struct/array.h"
#include "basic_struct/utils.h"

using namespace std;

/**
 * 输入一个数字
 * 4
 */
void input_one_num() {
    int tmp;
    while (cin >> tmp) {
        if (cin.get() == '\n') {
            break;
        }
    };
    cout << "num: " << tmp << endl;
}

/**
输入数据有1行数字,空格分开，表示一组输入数据。
或
输入数据有1行数字,逗号','分开，表示一组输入数据。
4 1 2 3 4
或
4,1,2,3,4
*/
void input_int_array() {
    vector<int> data;
    int tmp;
    while (cin >> tmp) {
        data.push_back(tmp);
        if (cin.get() == '\n') {
            break;
        }
    }

    print_array(data, "data");
}

/**
 * 输入一个字符串
 * abcdefg
 */
void input_one_string() {
    string tmp;
    while (cin >> tmp) {
        if (cin.get() == '\n') {
            break;
        }
    };
    cout << "string: " << tmp << endl;
}

/*
输入数据有1行字符串,空格分开，表示一组输入数据。
或
输入数据有1行字符串,逗号','分开，表示一组输入数据。
string char xiao meng
或
string,char,xiao,meng
*/
void input_string_array() {
    vector<string> data;
    string tmp;
    char sep = ',';
    // char sep = ' ';

    getline(cin, tmp);
    stringstream ss(tmp);
    while (getline(ss, tmp, sep)) {
        data.push_back(tmp);
    }

    print_array(data, "string array");
}

/**
 * 多行数字/字符，每行数量不定，空格分割
 */
void input_multiline_int_array() {
    vector<vector<int>> data;
    string tmp;
    // char sep = ' ';
    char sep = ',';

    while (getline(cin, tmp)) {
        // getchar();
        vector<int> _d;
        stringstream ss(tmp);
        while (getline(ss, tmp, sep)) {
            _d.push_back(stoi(tmp));
        }
        data.push_back(_d);
    }

    print_array_2d(data, "data 2d");
}
void input_multiline_string_array() {
    vector<vector<string>> data;
    string tmp;
    // char sep = ' ';
    char sep = ',';

    while (getline(cin, tmp)) {
        vector<string> _d;
        stringstream ss(tmp);
        while (getline(ss, tmp, sep)) {
            _d.push_back(tmp);
        }
        data.push_back(_d);
    }

    print_array_2d(data, "data 2d");
}

void input_multiline_int_array_v2() {
    int N;
    cin >> N;  // N 行数据

    vector<vector<int>> data;
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
    print_array_2d(data, "data with N");
}

void input_2d_int_array() {
    vector<vector<int>> data;
    string tmp;
    // char sep = ' ';
    char sep = ',';

    while (getline(cin, tmp)) {
        vector<int> _d;
        stringstream ss(tmp);
        while (getline(ss, tmp, sep)) {
            _d.push_back(stoi(tmp));
        }
        data.push_back(_d);
    }
    print_array_2d(data, "data (2d)");
}

void input_2d_int_array_with_N() {
    int N;
    cin >> N;

    vector<vector<int>> data;
    for (int i = 0; i < N; i++) {
        vector<int> _d;
        int tmp;
        while (cin >> tmp) {
            _d.push_back(tmp);
            if (cin.get() == '\n') {
                break;
            }
        }
        data.push_back(_d);
    }

    print_array_2d(data, "data 2d with N");
}

int main() {
    // input_one_num();
    // input_int_array();
    // input_one_string();
    // input_string_array();
    input_multiline_int_array();
    // input_multiline_string_array();
    // input_multiline_int_array_v2();
    // input_2d_int_array();
    // input_2d_int_array_with_N();
    return 0;
}
