#include <climits>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// Approach name: BFS (Breadth First Search)
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
 public:
  int minJumps(vector<int>& arr) {
    int n = arr.size();

    map<int, vector<int>> idx;
    // idx<num, i>

    for (int i = 0; i < n; i++) {
      idx[arr[i]].push_back(i);
    }

    queue<int> q;
    vector<int> dist(n, INT_MAX);

    q.push(0);
    dist[0] = 0;

    int nbr;

    while (!q.empty()) {
      int i = q.front();
      q.pop();

      nbr = i + 1;
      if (nbr < n) {
        int d = dist[i] + 1;
        if (d < dist[nbr]) {
          dist[nbr] = d;
          q.push(nbr);
        }
      }

      nbr = i - 1;
      if (nbr >= 0) {
        int d = dist[i] + 1;
        if (d < dist[nbr]) {
          dist[nbr] = d;
          q.push(nbr);
        }
      }

      int num = arr[i];
      auto& row = idx[num];
      // taking by reference avoids copying the vector repeatedly
      for (auto r : row) {
        int d = dist[i] + 1;
        if (d < dist[r]) {
          dist[r] = d;
          q.push(r);
        }
      }
      row.clear();
      // clear the indices for this value after processing once
      // so that same-value neighbors are not traversed repeatedly
      // this keeps the complexity linear
    }

    return dist[n - 1];
  }
};