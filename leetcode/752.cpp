/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        set<string> visited;
        for (string deadend : deadends) {
            visited.insert(deadend);
        }

        queue<string> q;
        int ret = 0;
        q.push("0000");
        if (visited.find("0000") != visited.end()) {
            return -1;
        }
        visited.insert("0000");

        while (!q.empty()) {
            int q_len = q.size();

            for (int i = 0; i < q_len; i++) {
                string cur = q.front();
                q.pop();
                if (cur == target) {
                    return ret;
                }
                // find the neighbours of cur
                // 只找没见过的加入队列
                vector<string> neighbours = get_neighbours(cur, visited);
                for (string n : neighbours) {
                    q.push(n);
                    visited.insert(n);
                }
            }
            ret += 1;
        }

        return -1;
    }

    vector<string> get_neighbours(string cur, set<string>& visited) {
        vector<string> neighbours;
        for (int i = 0; i < cur.size(); i++) {
            string up = up_string(cur, i);
            string down = down_string(cur, i);
            if (visited.find(up) == visited.end()) {
                neighbours.push_back(up);
            }
            if (visited.find(down) == visited.end()) {
                neighbours.push_back(down);
            }
        }
        return neighbours;
    }

    string up_string(string cur, int i) {
        if (cur[i] < '9') {
            cur[i] += 1;
        } else {
            cur[i] = '0';
        }
        return cur;
    }

    string down_string(string cur, int i) {
        if (cur[i] > '0') {
            cur[i] -= 1;
        } else {
            cur[i] = '9';
        }
        return cur;
    }
};
// @lc code=end
