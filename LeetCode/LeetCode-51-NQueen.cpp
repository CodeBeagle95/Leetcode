// N 皇后
class Solution {
private:
    vector<vector<string>> result_;

    bool check(const vector<string>& grid, const int row, const int col) {
        int n = grid.size();
        for (int i = 1; i <= row; ++i) {
            if (grid[row - i][col] == 'Q' || // 检查竖向上方
                col - i >= 0 && grid[row - i][col - i] == 'Q' || // 检查左斜上方
                col + i < n && grid[row - i][col + i] == 'Q') {  // 检查右斜上方
                return false;
            }
        }
        return true;
    }

    void dfs(vector<string>& grid, int row) {
        int n = grid.size();
        if (row == n) {
            result_.emplace_back(grid);
        }

        for (int i = 0; i < n; ++i) {
            if (check(grid, row, i)) {
                grid[row][i] = 'Q';
                dfs(grid, row + 1);
                grid[row][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        dfs(grid, 0);
        return result_;
    }
};