// 搜索二维矩阵 II
class Solution {
public:
    // Z 字形查找
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = (n == 0) ? 0 : matrix[0].size();
        if (n == 0 || m == 0) return false;

        int row = 0, col = m - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            if (matrix[row][col] > target) {
                --col;
            } else {
                ++row;
            }
        }
        return false;
    }
};