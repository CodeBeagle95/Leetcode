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

// 二叉树的最大深度
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        if (!root) return maxDepth;

        vector<TreeNode*> currVec;
        currVec.emplace_back(root);

        while (!currVec.empty()) {
            vector<TreeNode*> nextVec;
            for (auto& node : currVec) {
                if (node->left) {
                    nextVec.emplace_back(node->left);
                }
                if (node->right) {
                    nextVec.emplace_back(node->right);
                }
            }
            ++maxDepth;
            currVec = nextVec;
        }
        return maxDepth;
    }
};