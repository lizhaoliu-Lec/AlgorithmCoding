#include "list_node.h"
#include "utils.h"

ListNode* ReverseN::reverseN(ListNode* head, int n) {
    if (n == 1) {
        // 记录第 n+1 个节点
        this->successor = head->next;
        return head;
    }

    ListNode* last = this->reverseN(head->next, n - 1);
    head->next->next = head;
    head->next = nullptr;
    return last;
}

void run_linked_list() {
    ListNode a(1);
    ListNode b(2);
    ListNode* a_ptr = &a;
    ListNode* b_ptr = &b;
    a_ptr->next = b_ptr;

    ListNode* dummy = a_ptr;

    while (dummy != nullptr) {
        cout << "->" << dummy->val;
        dummy = dummy->next;
    }
    cout << endl;
    // cout << "hehe" << endl;
}

void print_linked_list(ListNode* head) {
    cout << "LinkedList is as follows: ";
    while (head != nullptr) {
        cout << head->val;
        head = head->next;
        if (head != nullptr) {
            cout << " -> ";
        }
    }
    cout << endl;
}

void print_linked_list_v2(ListNode* head, string name) {
    cout << "LinkedList " << name << " is: ";
    while (head != nullptr) {
        cout << head->val;
        head = head->next;
        if (head != nullptr) {
            cout << " -> ";
        }
    }
    cout << endl;
}

ListNode* create_linked_list_with_n(int n) {
    ListNode* dummy = new ListNode(-1000);
    ListNode* head = dummy;

    for (int i = 0; i < n; i++) {
        head->next = new ListNode(i);
        head = head->next;
    }

    // dummy = head;
    // head = head->next;

    // free(dummy);

    // return head;
    return dummy->next;
}

ListNode* create_linked_list(vector<int>& nums) {
    ListNode* dummy = new ListNode(-1);
    ListNode* head = dummy;

    for (int i = 0; i < nums.size(); i++) {
        // cout << nums[i] << endl;
        head->next = new ListNode(nums[i]);
        head = head->next;
    }

    return dummy->next;
}

void delete_linked_list(ListNode* head) {
    cout << "Deleting linked list...";
    ListNode* p = head;
    ListNode* temp = nullptr;
    while (p != nullptr) {
        temp = p;
        p = p->next;
        // delete node here
        free(temp);
    }
    cout << " Done!" << endl;
}

ListNode* mergeTwoLists_(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;
    ListNode *p1 = l1, *p2 = l2;

    // 当两个链表都还有元素时
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->val <= p2->val) {
            // 移动链表1的指针
            p->next = p1;
            p1 = p1->next;
        } else {
            // 移动链表2的指针
            p->next = p2;
            p2 = p2->next;
        }
        // 移动整体的指针
        p = p->next;
    }

    // 当链表1还有元素时
    if (p1 != nullptr) {
        p->next = p1;
    }
    // 当链表2还有元素时
    if (p2 != nullptr) {
        p->next = p2;
    }

    // 释放 dummy 节点的内存
    p = dummy;
    dummy = dummy->next;
    free(p);

    return dummy;
}

ListNode* findFromEnd(ListNode* head, int k) {
    ListNode* dummy = new ListNode(-1);
    ListNode *slow, *fast;
    dummy->next = head;  // 虚拟节点排除空值
    slow = dummy;
    fast = dummy;

    // 先走
    cout << "fast: ";
    for (int i = 0; i < k; i++) {  // 注意这里不需要 +1
        if (fast == nullptr) {
            return nullptr;  // 长度不足k，倒数第k个节点不存在
        }
        cout << fast->val << " -> ";
        fast = fast->next;
    }
    cout << endl;

    cout << "(slow, fast): ";
    // 此时快慢指针再一起往前走
    while (fast != nullptr) {
        cout << "(" << slow->val << " , " << fast->val << ")"
             << " -> ";
        slow = slow->next;
        fast = fast->next;
    }
    cout << endl;

    return slow;
}

void reversed_transverse(ListNode* head) {
    if (head == nullptr) {
        return;
    }
    // if (head->next != nullptr) {
    //     cout << " -> ";
    // }
    reversed_transverse(head->next);
    cout << head->val << " -> ";
}

ListNode* reverse_list(ListNode* head) {
    // 第一个条件其实在递归时不会出现，主要是为了应对输入的 head 为空的情况
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* last = reverse_list(head->next);
    head->next->next = head;
    head->next = nullptr;
    // if (last != nullptr) {
    //     print_tuple("last", last->val, "head", head->val);
    // }
    return last;
}

ListNode* reverse_n(ListNode* head, int n) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *p = head, *to_link;
    for (int i = 0; i < n - 1; i++) {
        p = p->next;

        if (p == nullptr) {
            // TODO
        }
    }
    to_link = p->next;  // 保存需要链接的节点
    p->next = nullptr;  // 断开

    ListNode* new_head = reverse_list(head);
    // 找到反转后的链表尾部
    p = new_head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = to_link;  // 拼接回本来断开的部分

    return new_head;
}
