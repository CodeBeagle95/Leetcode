// 螺旋矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = (n == 0) ? 0 : matrix[0].size();

        vector<int> ans;
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        while (left <= right || top <= bottom) {
            for (int i = left; i <= right && top <= bottom; ++i) { // 避免元素被重复遍历
                ans.emplace_back(matrix[top][i]);
            }
            ++ top;
            for (int i = top; i <= bottom && left <= right; ++i) {
                ans.emplace_back(matrix[i][right]);
            }
            --right;
            for (int i = right; i >= left && top <= bottom; --i) {
                ans.emplace_back(matrix[bottom][i]);
            }
            --bottom;
            for (int i = bottom; i >= top && left <= right; --i) {
                ans.emplace_back(matrix[i][left]);
            }
            ++left;
        }
        return ans;
    }
};