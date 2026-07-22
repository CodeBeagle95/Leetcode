// 组合总和
class Solution {
private:
    vector<vector<int>> result_;
    vector<int> sequence_;
    int sequenceSum_;

    void dfs(const vector<int>& candidates, int target) {
        if (sequenceSum_ > target) {
            return; // 总和超出目标直接返回
        } else if (sequenceSum_ == target) {
            result_.emplace_back(sequence_);
        }

        for (auto& num : candidates) {
            if (!sequence_.empty() && num < sequence_.back()) {
                continue; // 限制选取的序列为非严格递增序列
            }
            sequence_.push_back(num);
            sequenceSum_ += num;
            dfs(candidates, target);
            sequence_.pop_back();
            sequenceSum_ -= num;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target);
        return result_;
    }
};