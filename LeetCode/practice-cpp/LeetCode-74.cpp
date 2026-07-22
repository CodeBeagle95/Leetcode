// 搜索二维矩阵 - 将矩阵维度展开再进行二分法
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = (n == 0) ? 0 : matrix[0].size();
        if (n == 0 || m == 0) {
            return false;
        }
        if (target < matrix[0][0] || target > matrix[n - 1][m - 1]) {
            return false;
        }
        if (target == matrix[0][0] || target == matrix[n - 1][m -1]) {
            return true;
        }

        int left = 0, right = n * m;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return false;
    }
};