// 最大子数组和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int maxTailSum = 0;
        
        for (auto& n : nums) {
            maxTailSum = max(n, maxTailSum + n);
            result = max(result, maxTailSum);
        }
        return result;
    }
};