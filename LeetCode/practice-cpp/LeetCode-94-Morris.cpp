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

// 二叉树的中序遍历
// 1. 递归
// 2. 通过栈进行迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            res.emplace_back(node->val);
            node = node->right;
        }
        return res;
    }
};

// 3. Morris 中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* predecessor = new TreeNode();
        TreeNode* node = root;

        while (node != nullptr) {
            if (node->left != nullptr) {
                predecessor = node->left;
                while (predecessor->right != nullptr && predecessor->right != node) {
                    predecessor = predecessor->right; // predecessor 节点就是当前 node 节点向左走一步，然后一直向右走至无法走为止
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = node;
                    node = node->left;            // 左子树未遍历完，继续向左步进
                } else {
                    res.push_back(node->val);
                    predecessor->right = nullptr; // 左子树访问完毕，需要断开链接
                    node = node->right;           // 左子树访问完毕，需要向右步进
                }
            } else { // 如果没有左孩子，则直接访问右孩子
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};
