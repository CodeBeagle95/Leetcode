// 接雨水
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftHeight = height;
        for (int i = 1; i < height.size(); ++i) {
            leftHeight[i] = max(leftHeight[i - 1], height[i]);
        }

        vector<int> rightHeight = height;
        for (int i = height.size() - 2; i >= 0; --i) {
            rightHeight[i] = max(rightHeight[i + 1], height[i]);
        }

        int trapSum = 0;
        for (int i = 0; i < height.size(); ++i) {
            trapSum += min(leftHeight[i], rightHeight[i]) - height[i];
        }
        return trapSum;
    }
};
