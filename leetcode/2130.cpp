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

// Approach name: Two-Pointer + Reverse Second Half
// Time Complexity: O(n)
// Space Complexity = O(1)

class Solution {
 public:
  int pairSum(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* temp = nullptr;

    while (fast) {
      temp = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* curr = slow;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    temp->next = prev;

    fast = prev;
    slow = head;

    int ans = INT_MIN;
    while (fast) {
      int sum = slow->val + fast->val;
      ans = max(ans, sum);

      slow = slow->next;
      fast = fast->next;
    }

    return ans;
  }
};