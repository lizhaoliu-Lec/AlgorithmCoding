/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include <basic_struct/list_node.h>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        // return reverse(head);
        return reverse_stack(head);
    }

    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    ListNode* reverse_stack(ListNode* head) {
        stack<ListNode*> st;
        while (head != nullptr) {
            st.push(head);
            // 断开链接
            ListNode* tmp = head->next;
            head->next = nullptr;
            head = tmp;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while (!st.empty()) {
            p->next = st.top();
            st.pop();

            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end
