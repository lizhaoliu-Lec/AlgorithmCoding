/*
剑指 Offer 15. 二进制中1的个数
编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量)。
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n > 0) {
            if (n & 1) {
                ret += 1;
            }
            n >>= 1;
        }
        return ret;
    }
};