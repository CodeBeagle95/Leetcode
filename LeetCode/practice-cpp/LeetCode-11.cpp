// 盛最多水的容器
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) return 0;

        // 双指针法
        int left = 0;
        int right = height.size() - 1;

        int area = 0;
        while (left < right) {
            area = max(area, min(height[left], height[right]) * (right - left));
            // 移动较小端的指针
            if (height[left] < height[right]) {
                ++left;
            } else{
                --right;
            }
        }
        return area;
    }