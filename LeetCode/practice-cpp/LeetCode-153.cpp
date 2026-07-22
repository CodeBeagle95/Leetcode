// 寻找旋转排序数组中的最小值
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return INT_MIN;
        if (nums.front() <= nums.back()) return nums.front(); // 说明数组是单元素或递增数组

        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[left] < nums[mid]) { // 中点落在左半段
                left = mid;
            } else {
                right = mid;              // 中点落在右半段
            }
        }
        return nums[right];
    }
};