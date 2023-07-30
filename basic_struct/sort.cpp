#include "sort.h"

void _swap(vector<int>& nums, int idx1, int idx2) {
    int tmp = nums[idx1];
    nums[idx1] = nums[idx2];
    nums[idx2] = tmp;
}

int partition(vector<int>& nums, int left, int right) {
    // 先把元素交换到头部
    int mid = left + (right - left) / 2;  // 防止两个大整数相加后溢出
    _swap(nums, left, mid);

    int pivot = nums[left];

    // 利用快慢指针把小于等于pivot的值放到其左边，大于pivot的值放到其右边
    int slow = left + 1, fast = left + 1;
    while (fast <= right) {
        if (nums[fast] <= pivot) {
            _swap(nums, slow, fast);
            slow++;
        }
        fast++;
    }

    // 把头部元素交换回去
    _swap(nums, left, slow - 1);
    return slow - 1;
}

void quick_sort_help(vector<int>& nums, int left, int right) {
    if (left >= right) {  // 只有一个值或者没有值的时候不再需要排序
        return;
    }

    // 计算中间节点，可看作前序遍历
    int pivot = partition(nums, left, right);

    // 左边部分，可看作遍历左子树
    quick_sort_help(nums, left, pivot - 1);  // 闭区间
    // 右边部分，可看作遍历右子树
    quick_sort_help(nums, pivot + 1, right);  // 闭区间
}

void merge_two_sorted_array(vector<int>& nums, vector<int>& temp, int l1, int r1, int l2, int r2) {
    // int new_leng = (r1 - l1) + 1 + (r2 - l2) + 1;
    // vector<int> tmp_nums;
    int p1 = l1, p2 = l2;
    int p = l1;
    while (p1 <= r1 && p2 <= r2) {  // 闭区间
        if (nums[p1] <= nums[p2]) {
            // tmp_nums.push_back(nums[p1]);
            temp[p] = nums[p1];
            p1++;
        } else {
            // tmp_nums.push_back(nums[p2]);
            temp[p] = nums[p2];
            p2++;
        }
        p++;
    }

    // 把剩余的单条数组元素获取到
    while (p1 <= r1) {
        // tmp_nums.push_back(nums[p1]);
        temp[p] = nums[p1];
        p1++;
        p++;
    }
    while (p2 <= r2) {
        // tmp_nums.push_back(nums[p2]);
        temp[p] = nums[p2];
        p2++;
        p++;
    }

    // 将 tmp_nums 赋值到 nums
    // for (int i = 0; i < tmp_nums.size(); i++) {
    //     nums[l1 + i] = tmp_nums[i];
    // }
    for (int i = l1; i <= r2; i++) {
        nums[i] = temp[i];
    }
}

void merge_sort_help(vector<int>& nums, vector<int>& temp, int left, int right) {
    if (left >= right) {  // 如果没有元素或者只有一个元素，直接返回即可
        return;
    }

    int mid = left + (right - left) / 2;
    // 对左半边进行排序
    merge_sort_help(nums, temp, left, mid);  // 闭区间
    // 对右半边进行排序
    merge_sort_help(nums, temp, mid + 1, right);  // 闭区间

    // 合并排序结果，可看作后续遍历
    merge_two_sorted_array(nums, temp, left, mid, mid + 1, right);
}

void quick_sort(vector<int>& nums) {
    quick_sort_help(nums, 0, nums.size() - 1);  // 闭区间
}

void merge_sort(vector<int>& nums) {
    // 构建辅助数组，避免递归时频繁创建子数组
    vector<int> temp;
    for (int i = 0; i < nums.size(); i++) {
        temp.push_back(nums[i]);
    }
    merge_sort_help(nums, temp, 0, nums.size() - 1);  // 闭区间
}
