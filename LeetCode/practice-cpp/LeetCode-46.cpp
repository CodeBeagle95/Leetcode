// 全排列
class Solution {
private:
    vector<vector<int>> result_;
    vector<int> sequence_;

    void dfs(const vector<int>& nums, vector<bool>& flags) {
        if (nums.empty()) return;
        if (sequence_.size() == nums.size()) {
            result_.emplace_back(sequence_);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (flags[i] == false) {
                continue;
            }
            flags[i] = false;
            sequence_.push_back(nums[i]);
            dfs(nums, flags);
            flags[i] = true;
            sequence_.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flags(nums.size(), true);
        dfs(nums, flags);
        return result_;
    }
};