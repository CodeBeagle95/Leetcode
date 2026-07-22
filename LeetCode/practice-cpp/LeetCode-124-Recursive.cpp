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

// 二叉树中的最大路径和
class Solution {
private:
    int maxPathSum_ = INT_MIN;

    int recursiveSearchPath(TreeNode* root) {
        if (root == nullptr) return 0;

        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(0, recursiveSearchPath(root->left));
        int rightGain = max(0, recursiveSearchPath(root->right));

        // 包含:root, root+left, root+right, root+left+right, 单独left或right在子问题中求解
        maxPathSum_ = max(maxPathSum_, root->val + leftGain + rightGain);
        return root->val + max(leftGain, rightGain); // 只能选左树或右树递归返回
    }
public:
    int maxPathSum(TreeNode* root) {
        recursiveSearchPath(root);
        return maxPathSum_;
    }
};