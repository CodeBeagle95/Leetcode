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

// 二叉搜索树中第K小的元素
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr || k <= 0) return -1;
        TreeNode* node = root;
        stack<TreeNode*> stk;

        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            if (--k == 0) {
                return node->val;
            }
            node = node->right;
        }
        return -1;
    }
};