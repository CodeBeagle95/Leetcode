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
// 二叉树的后续遍历
class Solution {
private:
    void addPath(vector<int>& sequence, TreeNode* node) { // 逆序添加节点右侧链表
        int originalSize = sequence.size();
        while (node != nullptr) {
            sequence.emplace_back(node->val);
            node = node->right;
        }
        reverse(sequence.begin() + originalSize, sequence.end());
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> sequence;
        TreeNode* node = root;
        
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
                    predeccesor->right = nullptr; // 需要先断开连接再添加路径
                    addPath(sequence, node->left);
                    node = node->right;
                }
            } else {
                node = node->right;
            }
        }
        addPath(sequence, root); // 最后逆序添加根节点的右侧链表
        return sequence;
    }
};