// 下一个排列
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;

        // 从右往左找到第一个 a < b
        int mark = nums.size() - 1;
        while (mark > 0 && nums[mark - 1] >= nums[mark]) {
            -- mark;
        }
        // 全部反转
        if (mark == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 将第一个大于 mark 的最小元素前置，然后翻转元素变为升序
        int candidate = nums.size() - 1;
        while (candidate >= mark && nums[candidate] <= nums[mark - 1]) {
            -- candidate;
        }
        swap(nums[mark - 1], nums[candidate]);
        reverse(nums.begin() + mark, nums.end());
        return;
    }
};