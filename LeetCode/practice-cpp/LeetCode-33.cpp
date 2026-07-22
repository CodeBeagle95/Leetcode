// 搜索旋转排序数组 - 整数数组 nums 按升序排列，数组中的值互不相同
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if (nums[left] == target) return left; // 处理首个元素
        if (nums[right] == target) return right; // 处理末尾元素

        while (left + 1 < right) { // 确保中间至少有一个元素
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } 
            if (nums[left] < nums[mid]) { // 中点落在左半段
                if (nums[left] < target && target < nums[mid]) {
                    right = mid;
                } else {
                    left = mid;
                }
            } else {                      // 中点落在右半段
                if (nums[mid] < target && target < nums[right]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }
        return -1;
    }
};