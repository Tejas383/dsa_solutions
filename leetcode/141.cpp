#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Approach name : Floyd's Cycle Detection (Tortoise and Hare)
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) return true;
    }

    return false;
  }
};