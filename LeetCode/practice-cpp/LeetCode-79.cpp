// 单词搜索
class Solution {
private:
    bool dfs(vector<vector<char>>& board, const string& word, const int index, const int row, const int col) {
        if (index == word.size()) {
            return true;
        }

        bool result = false;
        int n = board.size();
        int m = (n == 0) ? 0 : board[0].size();
        int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; ++k) {
            int i = row + di[k];
            int j = col + dj[k];
            if (i >= 0 && j >= 0 && i < n && j < m && board[i][j] == word[index]) {
                char temp = board[i][j];
                board[i][j] = ' ';
                result = result || dfs(board, word, index + 1, i, j);
                board[i][j] = temp;
            }
        }
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = (n == 0) ? 0 : board[0].size();
        if (n == 0 || m == 0 || word.empty()) return false;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bool match = false;
                if (board[i][j] == word.front()) {
                    char temp = board[i][j];
                    board[i][j] = ' ';
                    match = dfs(board, word, 1, i, j);
                    board[i][j] = temp;
                }
                if (match == true) {
                    return true;
                }
            }
        }
        return false;
    }
};