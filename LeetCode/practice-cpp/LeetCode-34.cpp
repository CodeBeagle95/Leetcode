// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]
// 在排序数组中查找元素的第一个和最后一个位置
class Solution {
private:
    int findNumber(const vector<int>& nums, int target, int startIndex, bool findLast) {
        if (startIndex < 0 || startIndex >= nums.size()) {
            return -1;
        }

        int left = startIndex, right = nums.size();
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (!findLast && nums[mid] == target) { // 找第一个位置
                if (mid == 0 || nums[mid - 1] != target) {
                    return mid;
                } else {
                    right = mid;
                }
            } else if (findLast && nums[mid] == target) { // 找最后一个位置
                if (mid + 1 == nums.size() || nums[mid + 1] != target) {
                    return mid;
                } else {
                    left = mid;
                }
            }
            
            if (nums[mid] < target) {
                left = mid;
            } else if (nums[mid] > target) {
                right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty() ||target < nums.front() || target > nums.back()) {
            return {-1, -1};
        }

        int rangeLeft = findNumber(nums, target, 0, false);
        if (rangeLeft == -1) {
            return {-1, -1};
        }
        int rangeRight = findNumber(nums, target, rangeLeft, true);
        return {rangeLeft, rangeRight};
    }
};