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

// 二叉树的层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        vector<TreeNode*> layerNodes;
        layerNodes.emplace_back(root);

        while (!layerNodes.empty()) {
            vector<int> layerValues;
            vector<TreeNode*> layerNext;
            for (auto& node : layerNodes) {
                layerValues.emplace_back(node->val);
                if (node->left != nullptr) {
                    layerNext.emplace_back(node->left);
                }
                if (node->right != nullptr) {
                    layerNext.emplace_back(node->right);
                }
            }
            result.emplace_back(layerValues);
            layerNodes = layerNext;
        }
        return result;
    }
};