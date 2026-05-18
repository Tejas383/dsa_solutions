#include <vector>
using namespace std;

// Approach name: Modified Binary Search

// Time complexity:
// Average: O(log n)
// Worst case: O(n) due to duplicates
// still better than linear search,
// since linear search will take O(n) in every case
// but, this will take O(n) in special cases
// (where the number of duplicates is high)

// Space complexity: O(1)

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while (low <= high) {
      mid = (low + high) / 2;

      if (nums[mid] < nums[high]) {
        high = mid;
      } else if (nums[mid] > nums[high]) {
        low = mid + 1;
      } else {  // nums[mid] == nums[high]
        high--;
      }
    }

    return nums[mid];
  }
};