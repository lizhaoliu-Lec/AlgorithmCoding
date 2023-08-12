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
|    11    | LeetCode-104 | 二叉树 | [二叉树的最大深度](./leetcode/104.cpp) | 递归 | 使用 traverse 辅助函数 |
|    12    | LeetCode-144 | 二叉树 | [二叉树的前序遍历](./leetcode/144.cpp) | 递归/栈 | 注意栈的实现，当前节点出栈，先压右节点，再压左节点 |
|    12    | LeetCode-94 | 二叉树 | [二叉树的中序遍历](./leetcode/94.cpp) | 递归/栈 | 注意栈的实现，两层循环（直接看代码即可，有点复杂） |
|    13    | LeetCode-145 | 二叉树 | [二叉树的后序遍历](./leetcode/145.cpp) | 递归/栈 | 注意栈的实现，后序遍历在中序的双层循环的基础上需要加入一个记录，专门记录上一次出栈的节点（直接看代码即可，有点复杂） |
|    14    | LeetCode-543 | 二叉树 | [二叉树的直径](./leetcode/543.cpp) | 递归 | 半径等于左右最大深度之和为 `int cur_diameter = left_depth + right_depth;`，当前节点能贡献的最大半径为 `1 + max(left_depth, right_depth)` |
|    15    | LeetCode-303 | 前缀和 | [区域和检索 - 数组不可变](./leetcode/303.cpp) | 前缀和 | 注意前缀和数组大小，以及索引范围: `vector<int> pre_sum(nums.size() + 1, 0); pre_sum[i] = pre_sum[i - 1] + nums[i - 1]; return pre_sum[right + 1] - pre_sum[left];` |
|    16    | LeetCode-304 | 前缀和 | [二维区域和检索 - 矩阵不可变](./leetcode/304.cpp) | 前缀和 | 注意前缀和数组大小，以及索引范围: `vector<vector<int>> pre_sum(num_row + 1, vector<int>(num_col + 1, 0)); pre_sum[i][j] = pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1] + matrix[i - 1][j - 1]; return pre_sum[row2 + 1][col2 + 1] - pre_sum[row1][col2 + 1] - pre_sum[row2 + 1][col1] + pre_sum[row1][col1];` |
|    17    | JZ-15 | 位运算 | [二进制中1的个数](./jz_offer/15.cpp) | 位运算 | 判断最右边是否是1：`n & 1`, 数字右移一位：`n = n >> 1;` |
|    18    | LeetCode-76 | 字符串匹配 | [最小覆盖子串](./leetcode/76.cpp) | 滑动窗口 | 滑动窗口思路：1. 右指针先行，更新窗口数据，2. 确定收缩条件，3. 左指针再行，更新窗口数据；需要的数据结构有：`unordered_map<char, int> window; unordered_map<char, int> need; int valid = 0;` 关于 `unordered_map`, 有几个注意点：1.`need[i]`等价于`need[i] = 0`，2. `need.count(i)` 即为查找功能，所以本题中，在更新窗口数据前要进行判断，即`if (need.count(val_l))`, `if (need.count(val_r))` |
|    19    | LeetCode-567 | 字符串匹配 | [字符串的排列](./leetcode/567.cpp) | 滑动窗口 | 滑动窗口遗漏了两指针先行：1. 右指针先行，更新窗口数据 `char val_r = s2[right]; right += 1;`，...，3. 左指针再行，更新窗口数据 `char val_l = s2[left]; left += 1;` |
|    20    | LeetCode-438 | 字符串匹配 | [字符串的排列](./leetcode/438.cpp) | 滑动窗口 | 同 LeetCode-567 |
|    21    | LeetCode-3 | 字符串匹配 | [无重复字符的最长子串](./leetcode/3.cpp) | 滑动窗口 | `need, valid` 都不需要；结果更新要在左窗口 while 之后，此时确保是无重复字符的 |
|    22    | LeetCode-704 | 数组 | [二分查找](./leetcode/704.cpp) | 二分法 | 4 个注意点：1. 初始条件 `int left=0, right=nums.size()-1;`, 2. 循环条件 `while (left <= right)`, 3. mid 计算规则 `int mid = left + (right - left)/2`, 4. 左右指针更新规则 `left = mid-1; right = mid+1;` |
|    23    | LeetCode-34 | 数组 | [在排序数组中查找元素的第一个和最后一个位置](./leetcode/34.cpp) | 二分法 | 左右边界的二分查找. 对于左边界查找, 遇 target 时更新条件为 `right = mid-1;`, 随后要判断 `left >= nums.size()`, 最后再次确认是否遇 target `return nums[left] == target ? left : -1;`; 对于右边界查找, 遇 target 时更新条件为 `left = mid+1;`, 随后要判断 `right < 0`, 最后再次确认是否遇到 target `return nums[right] == target ? right : -1;` |
|  ...   |      ...      |    ...   |    ...   |  ... |

如果想要添加或删除列，可以自行修改。
