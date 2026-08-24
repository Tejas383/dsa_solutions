#include <bits/stdc++.h>
using namespace std;

// Approach: Hash Map + Doubly Linked List
// Time Complexity: O(1)
// Space Complexity: O(capacity)

struct Node {
  int key;
  int val;
  Node* prev;
  Node* next;

  Node() : key(-1), val(-1), prev(nullptr), next(nullptr) {}
  Node(int x, int y) : key(x), val(y), prev(nullptr), next(nullptr) {}
  Node(int x, int y, Node* p, Node* n) : key(x), val(y), prev(p), next(n) {}
};

class LRUCache {
  unordered_map<int, Node*> mp;
  int cap;
  Node* head;
  Node* tail;

  void removeNode(Node* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
  }

  void addNode(Node* node) {
    node->next = head->next;
    head->next = node;

    node->next->prev = node;
    node->prev = head;
  }

 public:
  LRUCache(int capacity) {
    this->cap = capacity;

    head = new Node();
    tail = new Node();

    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (!mp.count(key)) return -1;

    auto node = mp[key];
    removeNode(node);
    addNode(node);

    return node->val;
  }

  void put(int key, int value) {
    if (mp.count(key)) {
      auto node = mp[key];
      node->val = value;
      removeNode(node);
      addNode(node);
      return;
    }

    if (mp.size() == cap) {
      mp.erase(tail->prev->key);
      removeNode(tail->prev);
    }

    Node* newNode = new Node(key, value);
    mp[key] = newNode;
    addNode(newNode);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */