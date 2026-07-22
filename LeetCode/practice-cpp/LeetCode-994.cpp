// 腐烂的橘子 广度优先
class Solution {
private:
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& openCoords) {
        const int n = grid.size();
        const int m = (n == 0) ? 0 : grid[0].size();

        const int broadcastSourceNum = openCoords.size();
        int broadcastSourceCnt = 0;
        int broadcastOrangeNum = 0;
        int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};

        while (broadcastSourceCnt != broadcastSourceNum) {
            auto [oi, oj] = openCoords.front();
            openCoords.pop();
            ++ broadcastSourceCnt;
            for (int k = 0; k < 4; ++k) {
                int i = oi + di[k], j = oj + dj[k];
                if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
                    grid[i][j] = 2;
                    ++ broadcastOrangeNum;
                    openCoords.push(make_pair(i, j));
                }
            }
        }
        return broadcastOrangeNum;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = (n == 0) ? 0 : grid[0].size();

        int rottingSteps = 0;
        int rottingOrangeNum = 0;
        int freshOrangeNum = 0;
        queue<pair<int, int>> openCoords;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++freshOrangeNum;
                }
                if (grid[i][j] == 2) {
                    openCoords.push(make_pair(i, j));
                }
            }
        }
        
        while (!openCoords.empty()) {
            int broadcastOrangeNum = bfs(grid, openCoords);
            rottingOrangeNum += broadcastOrangeNum;
            if (broadcastOrangeNum != 0) {
                ++rottingSteps;
            }
        }

        return (freshOrangeNum == rottingOrangeNum) ? rottingSteps : -1;
    }
};