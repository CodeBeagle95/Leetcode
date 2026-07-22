// 分割回文串
class Solution {
private:
    vector<vector<string>> result_;
    vector<string> sequence_;

    bool check(const string& s, const int beg, const int end) {
        for (int i = beg, j = end; i <= j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void dfs(const string& s, const int index) {
        if (index == s.size()) {
            result_.emplace_back(sequence_);
        }

        for (int i = index; i < s.size(); ++i) {
            if (check(s, index, i)) {
                sequence_.push_back(s.substr(index, i - index + 1));
                dfs(s, i + 1);
                sequence_.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return result_;
    }
};