#include "Difference.h"

Difference::Difference(vector<int> nums) {
    diff.resize(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) {
            diff[i] = nums[i];
        } else {
            diff[i] = nums[i] - nums[i - 1];
        }
    }
}

Difference::~Difference() {}

void Difference::increment(int i, int j, int val) {  // val 可以是负数
    diff[i] += val;
    if (j + 1 < diff.size()) {  // 超过此范围说明是对 i 往后直到末尾的数字都进行修改了
        diff[j + 1] -= val;
    }
}

vector<int> Difference::result() {
    vector<int> ret(diff.size(), 0);
    for (int i = 0; i < ret.size(); i++) {
        if (i == 0) {
            ret[i] = diff[i];
        } else {
            ret[i] = diff[i] + ret[i - 1];
        }
    }
    return ret;
}