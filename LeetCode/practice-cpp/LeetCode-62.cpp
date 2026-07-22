// 不同路径
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prevSteps(m, 1);
        for (int i = 1; i < n; ++i) {
            vector<int> nextSteps(m, 1);
            for (int j = 1; j < m; ++j) {
                nextSteps[j] = nextSteps[j - 1] + prevSteps[j];
            }
            prevSteps = nextSteps;
        }
        return prevSteps.back();
    }
};