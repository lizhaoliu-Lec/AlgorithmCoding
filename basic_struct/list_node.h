#ifndef LIST_NODE
#define LIST_NODE

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ReverseN {
   private:
    ListNode* successor = nullptr;

   public:
    ListNode* reverseN(ListNode* head, int n);
};

void run_linked_list();

void print_linked_list(ListNode* head);

void print_linked_list_v2(ListNode* head, string name);

ListNode* create_linked_list_with_n(int n);

ListNode* create_linked_list(vector<int>& nums);

void delete_linked_list(ListNode* head);

ListNode* mergeTwoLists_(ListNode* l1, ListNode* l2);

ListNode* findFromEnd(ListNode* head, int k);

void reversed_transverse(ListNode* head);

ListNode* reverse_list(ListNode* head);

ListNode* reverse_n(ListNode* head, int n);

#endif  // LIST_NODE
