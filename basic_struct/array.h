#ifndef ARRAY
#define ARRAY
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void print_array(vector<T> array, string name);

template <typename T>
void print_array(vector<T> array);

template <typename T>
void print_array_2d(vector<vector<T>> array, string name);

template <typename T>
vector<T> create_array(int len, T de);

template <typename T>
vector<vector<T>> create_array_2d(int num_row, int num_col, T de);

int binary_search(vector<int> nums, int target);

int binary_search_left_bound(vector<int> nums, int target);

int binary_search_right_bound(vector<int> nums, int target);

vector<vector<int>> duplicateTwoSum(vector<int> nums, int target);

#endif