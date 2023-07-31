# AlgorithmCoding
这个仓库用于记录和跟踪个人算法题的刷题情况。

算法题记录

|   Id   |   来源   |    类型    | 题目名称 | 解题思想 | 备注 |
| :------ | :------ | :-------- | :------ | :------ | :-- |
|    1    | LeetCode-1 | 数组/字符串 | [两数之和](./leetcode/1.cpp) | 数组排序，左右指针 | 需要用 `val2indexes (unordered_map[int, stack])` 存储反向索引，注意错误代码：`int val_l, val_r = nums[left], nums[right];` |
|    2    | LeetCode-206 | 数组/字符串 | [反转字符串](./leetcode/206.cpp) | 递归、左右指针/栈、链表重构 | 递归代码行数少，但比较复杂，需要多复习；栈比较简单，但要注意入栈时断开原链表链接，构造时使用 dummy 头节点 |
|    3    | LeetCode-78 | 排列/组合/子集 | [子集](./leetcode/78.cpp) | 回溯 | 子集问题，使用 `start (int)` 保证向后遍历即可 |
|    4    | LeetCode-77 | 排列/组合/子集 | [组合](./leetcode/77.cpp) | 回溯 | 同 LeetCode-78 |
|    5    | LeetCode-46 | 排列/组合/子集 | [排列](./leetcode/46.cpp) | 回溯 | 排列问题，使用 `used (List[bool])` 保证不使用重复元素即可 |
|    6    | LeetCode-90 | 排列/组合/子集 | [子集 II](./leetcode/90.cpp) | 回溯 | 有重复元素的子集问题，注意要对数组进行排序`sort(nums.begin(), nums.end())`，使用 `i > start && nums[i] != nums[i-1]` 排除除第一次外，不要出现重复乱序的现象 |
|    7    | LeetCode-40 | 排列/组合/子集 | [组合总和 II](./leetcode/40.cpp) | 回溯 | 同 LeetCode-90 |
|    8    | LeetCode-47 | 排列/组合/子集 | [全排列 II](./leetcode/47.cpp) | 回溯 | 排列问题不需要使用 `start`，跳过条件有两个：1）用过的不再用 `used[i]`，2）有重复元素时，保证不会重复出现，出现相同时，只有前面用过了，后面才会继续用 `i > 0 && nums[i] == nums[i-1] && !used[i]` |
|    9    | LeetCode-39 | 排列/组合/子集 | [组合总和](./leetcode/39.cpp) | 回溯 | 要使用 `start` 参数，防止重复遍历；由于可重复选择，所以 `bactrack(nums, target, i, track_sum, track, rets);` 使用的是 `i` 而不是 `i + 1` |
|    10    | LeetCode-223 | 算法题 IoU | [矩形面积](./leetcode/223.cpp) | 画图+理解 | x 轴相交区域 `[max(ax1, bx1), min(ax2, bx2)]`; y 轴相交区域 `[max(ay1, by1), min(ay2, by2)]`; 线段长度要大于 0 才说明有交集 `x2 - x1 > 0 && y2 - y1 > 0` |
|  ...   |      ...      |    ...   |    ...   |  ... |

如果想要添加或删除列，可以自行修改。
