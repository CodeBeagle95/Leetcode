// 两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> numsMap; // 使用 map 加快查询
        for (int i = 0; i < nums.size(); i++) {
            numsMap[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            auto index = numsMap.find(target - nums[i]);
            if (index != numsMap.end() && index->second != i) {
                return vector<int>{i, index->second};
            }
        }
        return vector<int>{};
    }
};