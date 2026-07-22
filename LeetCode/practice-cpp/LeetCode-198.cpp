// 打家劫舍
class Solution {
public:
    int rob(vector<int>& nums) {
        int robMonney1 = 0;
        int robMonney2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int robMonney3 = max(robMonney1 + nums[i], robMonney2);
            robMonney1 = robMonney2;
            robMonney2 = robMonney3;
        }
        return robMonney2;
    }
};