// 括号生成
class Solution {
private:
    vector<string> result_;
    string sequence_;

    // 深度优先递归，每一层仅处理一个符合
    void dfs(int left, int right) {
        // 结束条件
        if (left == 0) {
            result_.emplace_back(sequence_ + string(right, ')'));
            return;
        }
        // 放左括号 - 仅一次，否则存在重复路径
        sequence_.push_back('(');
        dfs(left - 1, right);
        sequence_.pop_back();
        // 放右括号 - 仅一次，否则存在重复路径
        if (right > left) {
            sequence_.push_back(')');
            dfs(left, right - 1);
            sequence_.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return result_;
    }
};