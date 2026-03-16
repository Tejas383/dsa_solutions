#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Approach Name: Divide and Conquer (Recursive construction of height-balanced BST)
// Time Complexity: O(n)
// Space Complexity: O(log n) recursion stack (for balanced tree)

class Solution {
public:
    TreeNode* insert(vector<int>& nums, int start, int end) {
        if (start == end)
            return nullptr;
        
        int mid = (start + end) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = insert(nums, start, mid);
        root->right = insert(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insert(nums, 0, nums.size());
    }
};