// 柱状图中最大的矩形 - 单调栈，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> indexStack;      // 需要用栈来记录的递增高度的索引
        heights.push_back(INT_MIN); // 这里写入 INT_MIN 来保证栈中先前所有元素都会被推出

        for (int i = 0; i < heights.size(); ++i) {
            while (!indexStack.empty() && heights[i] <= heights[indexStack.top()]) {
                int height = heights[indexStack.top()]; // 高度为被推出索引高度
                indexStack.pop();                       // 这里先推出元素来拿前一个元素
                int width = i - ((indexStack.empty()) ? 0 : indexStack.top() + 1); // 宽度要拉到前一个元素的下一个索引
                maxArea = max(maxArea, height * width);
            }
            indexStack.push(i); // 注意这里要推入的是索引
        }

        heights.pop_back(); // 将入参复原
        return maxArea;
    }
};