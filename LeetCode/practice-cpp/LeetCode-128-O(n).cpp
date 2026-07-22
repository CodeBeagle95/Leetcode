// 最长连续序列
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 需要使用 unordered_map 时间复杂度才为O(n)
        if (nums.empty()) return 0;

        int longest = 1;
        std::unordered_map<int, int> counterMap;
        for (auto& n : nums) {
            counterMap[n] = 1;
        }

        for (auto iter = counterMap.begin(); iter != counterMap.end(); ++iter) {
            int num = iter->first;
            auto find = counterMap.find(num - 1);
            while (find != counterMap.end() && find->second != 0) {
                iter->second += find->second;        // 衔接之前查找的长度
                find->second = 0;                    // 衔接过的元素置零
                find = counterMap.find((--num) - 1); // 继续查找下一个数值
            }
            longest = max(longest, iter->second);
        }
        return longest;
    }
};