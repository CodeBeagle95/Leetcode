// 和为K的子数组
class Solution {
public:
    // 方法一：枚举
    // 方法二：前缀和 + 哈希表优化 需要考虑正负数, 多序列组合和为零，非空序列
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;

        unordered_map<int, int> sumFreqMap;
        sumFreqMap[0] = 1; // 初始化和为零的起始索引为0的情况

        int sumFromBegin = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sumFromBegin += nums[i];
            auto find = sumFreqMap.find(sumFromBegin - k); // 先迭代运算
            if (find != sumFreqMap.end()) {
                res += find->second;
            }
            ++ sumFreqMap[sumFromBegin];  // 再更新字典
        }
        return res;
    }
};