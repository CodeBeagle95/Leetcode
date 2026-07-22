// 生命游戏
class Solution {
private:
    int countAlive(const vector<vector<int>>& board, int i, int j) {
        int n = board.size();
        int m = (n == 0) ? 0 : board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m) return 0;

        int counter = 0;
        int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for (int k = 0; k < 8; ++k) {
            int ii = i + di[k], jj = j + dj[k];
            if (ii >= 0 && jj >= 0 && ii < n && jj < m && board[ii][jj] % 2) { // 使用奇偶来保留原本信息
                ++counter;
            }
        }
        return counter;
    } 
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = (n == 0) ? 0 : board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int aliveCnt = countAlive(board, i, j);
                if ((board[i][j] % 2 == 0) && aliveCnt == 3 ||
                    (board[i][j] % 2) && (aliveCnt > 3 || aliveCnt < 2)) {
                    board[i][j] += 2; // 使用奇偶来保留原本信息
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 3) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
};