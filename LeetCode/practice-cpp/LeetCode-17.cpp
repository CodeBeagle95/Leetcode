// 电话号码的字母组合
class Solution {
private:
    vector<string> result_; // 存储输出结果
    string sequence_;       // 存储递归过程中的生成序列
    unordered_map<char, string> keyDict_ {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void dfs(const string& digits, int depth) {
        if (digits.empty() || depth > digits.size()) {
            return;
        }

        if (depth == digits.size()) {
            result_.emplace_back(sequence_);
            return;
        }

        string val = keyDict_[digits[depth]];
        for (auto& alpha : val) {
            sequence_.push_back(alpha);
            dfs(digits, depth + 1);
            sequence_.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        dfs(digits, 0);
        return result_;
    }
};