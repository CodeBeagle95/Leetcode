// 跳跃游戏II
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;

        vector<int> steps(nums.size(), INT_MAX);
        steps[0] = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= i + nums[i] && j < nums.size(); ++j) {
                steps[j] = min(steps[j], steps[i] + 1);
            }
        }
        return steps.back();
    }
};