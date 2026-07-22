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

// 恢复二叉搜索树
// 解法一：栈
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node = root, *prev = nullptr;
        TreeNode* change1 = nullptr, *change2 = nullptr;

        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();

            if (prev != nullptr && node->val < prev->val) {
                change1 = (change1 == nullptr) ? prev : change1;
                change2 = node;
            }
            prev = node;
            node = node->right;
        }
        if (change1 && change2) {
            swap(change1->val, change2->val);
        }
    }
};

// 解法二：Morris
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* node = root, *prev = nullptr;
        TreeNode* change1 = nullptr, *change2 = nullptr;

        while (node != nullptr) {
            if (node->left != nullptr) {
                TreeNode* predeccesor = node->left;
                while (predeccesor->right != nullptr && predeccesor->right != node) {
                    predeccesor = predeccesor->right;
                }
                if (predeccesor->right == nullptr) {
                    predeccesor->right = node;
                    node = node->left;
                } else {
                    prev = node;
                    predeccesor->right = nullptr;
                    node = node->right;
                }
            } else {
                prev = node;
                node = node->right;
            }
            // 记录中序遍历第一个和最后一个位置颠倒元素
            if (node != nullptr && prev != nullptr && node->val < prev->val) {
                change1 = (change1 == nullptr) ? prev : change1;
                change2 = node;
            }
        }
        if (change1 && change2) {
            swap(change1->val, change2->val);
        }
    }
};