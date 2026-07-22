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

// 对称二叉树
class Solution { // 层序遍历
public:
    bool isSymmetric(TreeNode* root) { 
        std::vector<TreeNode*> node_vec;
        node_vec.push_back(root);
        
        bool all_node_null = false;
        while (!all_node_null) {
            std::vector<TreeNode*> node_vec_new;
            for (int i = 0; i < node_vec.size(); ++i) {
                node_vec_new.push_back((node_vec[i] == nullptr) ? nullptr : node_vec[i]->left);
                node_vec_new.push_back((node_vec[i] == nullptr) ? nullptr : node_vec[i]->right);
            }

            all_node_null = true;
            for (int i = 0, j = node_vec_new.size()-1; i < j; ++i, --j) {
                if (node_vec_new[i] != nullptr || node_vec_new[j] != nullptr) {
                    all_node_null = false;
                }

                if (node_vec_new[i] == nullptr && node_vec_new[j] == nullptr) {
                    continue; // 都为空指针跳过
                }
                if (node_vec_new[i] != nullptr && node_vec_new[j] != nullptr) {
                    if (node_vec_new[i]->val == node_vec_new[j]->val) {
                        continue; // 都不为空指针且值相等跳过
                    }
                }
                return false;
            }

            node_vec = node_vec_new;
        }

        return true;
    }
};

class Solution { // 递归调用，效率更好
private:
    bool isSymmetric(TreeNode* r1, TreeNode* r2) {
        if (r1 == nullptr && r2 == nullptr) {
            return true;
        }
        if (r1 != nullptr && r2 == nullptr || r1 == nullptr && r2 != nullptr) {
            return false;
        }
        if (r1->val != r2->val) {
            return false;
        }
        return isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSymmetric(root->left, root->right);
    }
};