#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/shortest-prime-path--141631/1
// Approach: Sieve of Eratosthenes + Breadth-First Search (BFS)
// Time Complexity: O(10000 log log 10000 + 10000)
// Space Complexity: O(10000)

class Solution {
 public:
  int minStep(int num1, int num2) {
    // Sieve of Eratosthenes
    vector<bool> primes(10000, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i < 10000; i++) {
      if (!primes[i]) continue;

      for (int j = 2 * i; j < 10000; j += i) 
        primes[j] = false;
    }

    // BFS
    queue<int> q;
    q.push(num1);
    primes[num1] = false;
    int steps = 0;

    while (!q.empty()) {
      int s = q.size();

      while (s--) {
        int num = q.front();
        q.pop();

        if (num == num2) return steps;

        string str = to_string(num);
        for (int i = 0; i < 4; i++) {
          string temp = str;
          for (int j = 0; j < 10; j++) {
            if (i == 0 && j == 0) continue;

            temp[i] = '0' + j;

            int n = stoi(temp);

            if (n != num && primes[n] == true) {
              primes[n] = false;
              q.push(n);
            }
          }
        }
      }

      steps++;
    }

    return -1;
  }
};
