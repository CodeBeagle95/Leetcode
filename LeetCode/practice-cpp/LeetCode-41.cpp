// 缺失的第一个正数
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (auto& n : nums) {
            if (n < 0) {
                n = 0; // 为了将INT_MIN设置为标记，先将负数变为0
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            int curNum = nums[i];
            while (curNum > 0 && curNum <= nums.size()) { // 确保不会越界
                int nextNum = nums[curNum - 1];
                nums[curNum - 1] = INT_MIN;  // 将出现过1-N的数字索引置为INT_MIN
                curNum = nextNum;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) { // 找到第一个值不为INT_MIN的索引
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
