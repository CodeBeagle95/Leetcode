// 分割等和子集 - 寻找子集的和为全集的平均数
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) return false;

        int maxNum = 0;
        long long totalSum = 0;
        for (auto& num : nums) {
            totalSum += num;
            maxNum = max(maxNum, num);
        }
        if (totalSum & 1) { // 无法等分
            return false;
        }

        int target = totalSum / 2;
        if (maxNum > target) { // 最大元素大于一半
            return false;
        }
        
        vector<bool> dp(target + 1, false); // 使用数组预分配内存效率更优
        dp[0] = true;

        for (auto& num : nums) {
            for (int j = target; j >= num; --j) { // 需从右往左更新，否则元素会重复使用
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};