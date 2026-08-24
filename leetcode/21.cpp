#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Approach 1 : Iterative Merge using Extra Nodes
// Time Complexity : O(n + m)
// Space Complexity : O(n + m)

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode* head;

    if (list1->val < list2->val) {
      head = new ListNode(list1->val);
      list1 = list1->next;
    } else {
      head = new ListNode(list2->val);
      list2 = list2->next;
    }

    ListNode* temp = head;
    while (list1 && list2) {
      int val;
      if (list1->val < list2->val) {
        val = list1->val;
        list1 = list1->next;
      } else {
        val = list2->val;
        list2 = list2->next;
      }

      temp->next = new ListNode(val);
      temp = temp->next;
    }

    if (!list1) temp->next = list2;
    if (!list2) temp->next = list1;

    return head;
  }
};

// Approach 2 : Iterative In-place Merge
// Time Complexity : O(n + m)
// Space Complexity : O(1)

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode* head;

    if (list1->val < list2->val) {
      head = list1;
      list1 = list1->next;
    } else {
      head = list2;
      list2 = list2->next;
    }

    ListNode* temp = head;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        temp->next = list1;
        list1 = list1->next;
      } else {
        temp->next = list2;
        list2 = list2->next;
      }

      temp = temp->next;
    }

    if (!list1) temp->next = list2;
    if (!list2) temp->next = list1;

    return head;
  }
};

// Approach 3 : Recursive In-place Merge
// Time Complexity : O(n + m)
// Space Complexity : O(n + m)

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val < list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    }

    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
  }
};