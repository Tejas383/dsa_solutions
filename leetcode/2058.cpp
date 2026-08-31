#include <bits/stdc++.h>
using namespace std;

// Approach : Index Tracking
// Time Complexity : O(n)
// Space Complexity : O(n)

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> criticalPoints;

    ListNode* temp = head->next;
    ListNode* prevNode = head;
    ListNode* nextNode;
    int i = 1;

    while (temp && temp->next) {
      nextNode = temp->next;
      if (temp->val < prevNode->val && temp->val < nextNode->val)
        criticalPoints.push_back(i);
      if (temp->val > prevNode->val && temp->val > nextNode->val)
        criticalPoints.push_back(i);
      i++;
      prevNode = temp;
      temp = temp->next;
    }

    if (criticalPoints.size() < 2) return {-1, -1};

    int a = INT_MAX;
    for (int j = 1; j < criticalPoints.size(); j++) {
      a = min(a, criticalPoints[j] - criticalPoints[j - 1]);
    }
    int b = criticalPoints[criticalPoints.size() - 1] - criticalPoints[0];

    return {a, b};
  }
};