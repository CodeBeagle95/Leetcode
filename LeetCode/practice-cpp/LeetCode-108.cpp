/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 将有序数组转换为二叉搜索树
class Solution {
private:
    TreeNode* subSortedArrayToBST(vector<int>& nums, int i, int j) {
        if (i < 0 || j < 0 || i >= nums.size() || j >= nums.size() || i > j) return nullptr;

        int mid = (i + j) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* leftTree = subSortedArrayToBST(nums, i, mid - 1);
        TreeNode* rightTree = subSortedArrayToBST(nums, mid + 1, j);

        root->left = leftTree;
        root->right = rightTree;
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return subSortedArrayToBST(nums, 0, nums.size() - 1);
    }
};