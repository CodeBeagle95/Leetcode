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

// 二叉树的右视图
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        vector<TreeNode*> currLayerNodes;
        currLayerNodes.emplace_back(root);
        while (!currLayerNodes.empty()) {
            vector<TreeNode*> nextLayerNodes;
            for (auto& node : currLayerNodes) {
                if (node->left != nullptr) {
                    nextLayerNodes.emplace_back(node->left);
                }
                if (node->right != nullptr) {
                    nextLayerNodes.emplace_back(node->right);
                }
            }
            result.emplace_back(currLayerNodes.back()->val);
            currLayerNodes = nextLayerNodes;
        }
        return result;
    }
};