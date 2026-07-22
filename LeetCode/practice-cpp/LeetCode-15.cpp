// 三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplet;
        unordered_map<int, int> numCounter;
        for (auto& n : nums) ++numCounter[n]; // map: 数值->频次

        std::sort(nums.begin(), nums.end()); // 先对原数组进行排序
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;         // 跳过相同的第一个元素
            for (int j = i + 1; j < nums.size(); ++j) {             // 限制 i < j
                if (j != i + 1 && nums[j] == nums[j - 1]) continue; // 跳过相同的第二个元素
                int third = -(nums[i] + nums[j]);                   
                if (third < nums[i] || third < nums[j]) continue;   // 限制 j < k
                auto find = numCounter.find(third);
                if (find == numCounter.end()) continue;             // 找不到数直接跳过
                if ((third != nums[i] && third != nums[j]) ||
                    ((third != nums[i] || third != nums[j]) && find->second > 1) || // 注意运算符优先级
                    ((third == nums[i] && third == nums[j]) && find->second > 2)) {
                    triplet.emplace_back(vector<int>{nums[i], nums[j], third});
                }
            }
        }
        return triplet;
    }
};
