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

// 路径总和III，前缀和 + 哈希表
class Solution {
private:
    int pathCounter_ = 0;
    unordered_map<long long, int> prefixSumMap{{0, 1}};  // long long 避免运算过程中溢出

    void recursiveSearch(TreeNode* node, long long prefixSum, int targetSum) {
        if (node == nullptr) return;

        prefixSum += node->val;
        auto iter = prefixSumMap.find(prefixSum - targetSum);
        if (iter != prefixSumMap.end()) {
            pathCounter_ += iter->second;
        }

        ++prefixSumMap[prefixSum];
        recursiveSearch(node->left, prefixSum, targetSum);
        recursiveSearch(node->right, prefixSum, targetSum);
        --prefixSumMap[prefixSum];
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        recursiveSearch(root, 0, targetSum);
        return pathCounter_;
    }
};