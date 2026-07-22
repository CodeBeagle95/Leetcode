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

// 二叉树展开为链表，先序遍历展开链表
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* node = root;
        TreeNode* predecessor = nullptr;

        while (node != nullptr) {
            if (node->left != nullptr) {
                predecessor = node->left;
                while (predecessor->right != nullptr && predecessor->right != node) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = node;
                    node = node->left;                      // 左子树未遍历完，继续向左步进
                } else {
                    TreeNode* oriRightNode = node->right;   // 存储原先的右节点
                    node->right = node->left;               // 左节点切换到右节点
                    node->left = nullptr;                   // 断开左连接
                    predecessor->right = oriRightNode;      // 末尾节点续上原先的右节点
                    node = oriRightNode;                    // 左子树访问完毕，需要向右步进
                }
            } else {
                node = node->right; // 没有左节点向右走, 这里会经过之前修改过的右连接
            }
        }
    }
};
