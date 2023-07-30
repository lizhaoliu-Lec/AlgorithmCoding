#include "array.h"

template <typename T>
vector<T> create_array(int len, T de) {
    vector<T> a;
    for (int i = 0; i < len; i++) {
        a.push_back(de);
    }
    return a;
}

template <typename T>
vector<vector<T>> create_array_2d(int num_row, int num_col, T de) {
    vector<vector<T>> a;
    for (int i = 0; i < num_row; i++) {
        a.push_back(create_array<T>(num_col, de));
    }
    return a;
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
void print_array(vector<T> nums) {
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

int binary_search(vector<int> nums, int target) {
    int left = 0, right = nums.size();  // [left, right) 左闭右开
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }

    // 找不到，返回 -1
    return -1;
}

int binary_search_left_bound(vector<int> nums, int target) {
    int left = 0, right = nums.size();  // [left, right) 左闭右开
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    // 如果输入的target很大，left会不断增加，导致数组越界
    if (left >= nums.size()) {
        return -1;
    }
    return nums[left] == target ? left : -1;
}

int binary_search_right_bound(vector<int> nums, int target) {
    int left = 0, right = nums.size();  // [left, right) 左闭右开
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    // 右开，所以要减1
    if (right - 1 < 0) {
        return -1;
    }
    return nums[right - 1] == target ? right - 1 : -1;
}

vector<vector<int>> duplicateTwoSum(vector<int> nums, int target) {
    // sort nums first
    sort(nums.begin(), nums.end());

    vector<vector<int>> rets;
    int left = 0, right = nums.size() - 1;  // [left, right]
    while (left < right) {                  // 不能等于，不然就只有一个数字了
        int sum = nums[left] + nums[right];
        int left_val = nums[left], right_val = nums[right];
        if (sum == target) {
            rets.push_back({left_val, right_val});
            // 去重
            while (left < nums.size() && nums[left] == left_val) {
                left++;
            }
            while (right >= 0 && nums[right] == right_val) {
                right--;
            }
        } else if (sum < target) {
            while (left < nums.size() && nums[left] == left_val) {
                left++;
            }
        } else if (sum > target) {
            while (right >= 0 && nums[right] == right_val) {
                right--;
            }
        }
    }

    return rets;
}

template vector<int> create_array<int>(int len, int de);
template vector<char> create_array(int len, char de);
template vector<double> create_array(int len, double de);
template vector<string> create_array(int len, string de);

template vector<vector<int>> create_array_2d(int num_row, int num_col, int de);
template vector<vector<char>> create_array_2d(int num_row, int num_col, char de);
template vector<vector<double>> create_array_2d(int num_row, int num_col, double de);
template vector<vector<string>> create_array_2d(int num_row, int num_col, string de);

template void print_array(vector<int> array, string name);
template void print_array(vector<bool> array, string name);
template void print_array(vector<char> array, string name);
template void print_array(vector<double> array, string name);
template void print_array(vector<string> array, string name);

template void print_array(vector<int> array);
template void print_array(vector<bool> array);
template void print_array(vector<char> array);
template void print_array(vector<double> array);
template void print_array(vector<string> array);

template void print_array_2d(vector<vector<int>> array_2d, string name);
template void print_array_2d(vector<vector<bool>> array_2d, string name);
template void print_array_2d(vector<vector<char>> array_2d, string name);
template void print_array_2d(vector<vector<double>> array_2d, string name);
template void print_array_2d(vector<vector<string>> array_2d, string name);
