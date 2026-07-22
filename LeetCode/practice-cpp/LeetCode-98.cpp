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

// 验证二叉搜索树
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk; // 使用栈进行中序遍历
        TreeNode* node = root;

        bool isFirstNode = true;
        int nodeValue = 0;
        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            if (isFirstNode || nodeValue < node->val) {
                nodeValue = node->val;
                isFirstNode = false;
            } else {
                return false;
            }
            node = node->right;
        }
        return true;
    }
};