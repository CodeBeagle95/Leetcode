// 杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows;
        for (int i = 0; i < numRows; ++i) {
            rows.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; ++j) {
                rows[i][j] = rows[i - 1][j] + rows[i - 1][j - 1];
            }
        }
        return rows;
    }
};