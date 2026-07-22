// 子集
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        int count = nums.size();

        for (int i = 1; i < pow(2, count); ++i) {  // 使用二进制左移来求解
            int index = 0, bits = i;
            vector<int> vec;
            while (bits > 0) {
                if (bits & 0x01) {
                    vec.push_back(nums[index]);
                }
                ++index;
                bits >>= 1;
            }
            res.push_back(vec);
        }
        return res;
    }
};

// 子集
class Solution {
private:
    vector<vector<int>> result_{vector<int>{}};
    vector<int> sequence_;

    void dfs(vector<int>& nums) {
        if (!sequence_.empty()) {
            result_.emplace_back(sequence_);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!sequence_.empty() && nums[i] <= sequence_.back()) {
                continue;
            }
            sequence_.push_back(nums[i]);
            dfs(nums);
            sequence_.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> flags(nums.size(), true);
        dfs(nums);
        return result_;
    }
};