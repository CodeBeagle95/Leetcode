// 跳跃游戏
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }

        int remainStep = 0;
        for (int i = 0; i < nums.size(); ++i) {
            remainStep = max(remainStep - 1, nums[i]);
            if (remainStep <= 0 && i + 1 != nums.size()) {
                return false;
            }
        }
        return true;
    }
};
