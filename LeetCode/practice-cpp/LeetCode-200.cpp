// 岛屿数量
class Solution {
    void dfs(vector<vector<char>>& grid, const int row, const int col) {
        int n = grid.size();
        int m = (n == 0) ? 0 : grid[0].size();

        grid[row][col] = '0';
        queue<pair<int, int>> openCoords; // 使用queue迭代相比vector能减少拷贝及内存占用
        openCoords.push(make_pair(row, col));
        int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};

        while (!openCoords.empty()) {
            auto [oi, oj] = openCoords.front();
            openCoords.pop();
            for(int k = 0; k < 4; ++k){
                int i = oi + di[k], j = oj + dj[k];
                if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1'){
                    grid[i][j] = '0';
                    openCoords.push(make_pair(i, j));
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = (n == 0) ? 0 : grid[0].size();

        int counter = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++counter;
                }
            }
        }
        return counter;
    }
};