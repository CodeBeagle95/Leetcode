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

// 从前序与中序遍历序列构造二叉树
class Solution {
private:
    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int i, int j, int len) {
        if (i < 0 || j < 0 || len <= 0 || i + len > preorder.size() || j + len > inorder.size()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[i]);
        for (int cnt = 0; cnt < len; ++cnt) { // 计算左子树的节点个数
            if (inorder[j + cnt] == root->val) {
                auto leftTree = buildSubTree(preorder, inorder, i + 1, j, cnt);
                auto rightTree = buildSubTree(preorder, inorder, i + cnt + 1, j + cnt + 1, len - cnt - 1);
                root->left = leftTree;
                root->right = rightTree;
                return root;
            }
        }
        return nullptr;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || preorder.size() != inorder.size()) return nullptr;
        return buildSubTree(preorder, inorder, 0, 0, preorder.size());
    }
};