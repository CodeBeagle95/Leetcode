// 丑数II - [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return -1;

        vector<int> uglyVec(n, 1);
        int cur2 = 0, cur3 = 0, cur5 = 0;
        for (int i = 1; i < n; ++i) {
            int next = min(uglyVec[cur2] * 2, min(uglyVec[cur3] * 3, uglyVec[cur5] * 5));
            uglyVec[i] = next;

            while (uglyVec[cur2] * 2 <= uglyVec[i]) ++cur2;
            while (uglyVec[cur3] * 3 <= uglyVec[i]) ++cur3;
            while (uglyVec[cur5] * 5 <= uglyVec[i]) ++cur5;
        }

        return uglyVec.back();
    }
};