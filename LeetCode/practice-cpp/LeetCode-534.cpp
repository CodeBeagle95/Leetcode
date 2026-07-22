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

// 二叉树的直径
class Solution {
private:
    int maxDiameter = 0;

    int depthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftDepth = 0, rightDepth = 0;
        if (root->left) {
            leftDepth = depthOfBinaryTree(root->left);
        }
        if (root->right) {
            rightDepth = depthOfBinaryTree(root->right);
        }
        maxDiameter = max(maxDiameter, leftDepth + rightDepth + 1);
        return max(leftDepth, rightDepth) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        depthOfBinaryTree(root);
        return maxDiameter - 1;
    }
};