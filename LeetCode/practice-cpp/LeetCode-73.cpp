// 矩阵置零
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = (n == 0)? 0 : matrix[0].size();
        // 将所有标记放在一个循环中
        bool firstRowHasZero = false, firstColHasZero = false; // 标记首行首列是否含有0
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0) firstRowHasZero = true;
                    if (j == 0) firstColHasZero = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 第二次循环要逆序，否则首行首列存在更新会导致整个矩阵置零
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (firstRowHasZero && i == 0 ||
                    firstColHasZero && j == 0 ||
                    matrix[i][0] == 0 && i != 0 ||
                    matrix[0][j] == 0 && j != 0) {
                    matrix[i][j] = 0;    
                }
            }
        }
    }
};