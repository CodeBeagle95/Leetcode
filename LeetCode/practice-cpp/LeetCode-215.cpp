// 数组中的第K个最大元素 - 最小堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || nums.size() < k) {
            return INT_MIN;
        }

        priority_queue<int, vector<int>, greater<int>> pq; // 最小堆
        for (int i = 0; i < nums.size(); ++i) {
            pq.push(nums[i]);
            if (i >= k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};