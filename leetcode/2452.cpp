#include <vector>
#include <string>
using namespace std;

// Approach 1: Brute Force String Comparison
// Time Complexity: O(n * m *  s)
// Space Complexity = O(n)

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int s = queries[0].size();
        vector<string> ans;

        for (auto word : queries) {
            for (auto dict : dictionary) {
                int diff = 0;

                for (int i = 0; i < s; i++) {
                    if (word[i] != dict[i])
                        diff++;
                    if (diff > 2)
                        break;
                }

                if (diff <= 2) {
                    ans.push_back(word);
                    break;
                }
            }
        }

        return ans;
    }
};