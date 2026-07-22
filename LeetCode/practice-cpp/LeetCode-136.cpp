// 只出现一次的数字
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto &n : nums) ret ^= n;
        return ret;
    }
};