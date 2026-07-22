// 滑动窗口最大值
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k) return vector<int>{}; // 处理特殊场景

        vector<int> result;
        deque<int> maxMemory; // 维护单调递减队列
        for (int i = 0; i < nums.size(); ++i) {
            while (!maxMemory.empty() && maxMemory.back() < nums[i]) {
                maxMemory.pop_back();
            }
            maxMemory.push_back(nums[i]);
            if (i < k) { // 未满足窗口大小
                result = vector<int>{maxMemory.front()};
                continue;
            }

            if (nums[i - k] == maxMemory.front()) {
                maxMemory.pop_front(); // 窗口移动中推出最大元素
            }
            result.push_back(maxMemory.front());
        }
        return result;
    }
};