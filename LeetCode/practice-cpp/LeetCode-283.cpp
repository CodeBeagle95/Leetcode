// 移动零
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int markIndex = nums.size() - 1;
        for (int i = 0; i < markIndex; ++i) {
            if (nums[i] == 0) {
                // i 需要减操作避免移动后错位
                for (int j = i--; j < markIndex; ++j) {
                    nums[j] = nums[j + 1]; // 数值前移
                }
                nums[markIndex--] = 0; // 数值更新&索引前移
            }
        }
    }
};