// 超级丑数
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 0 || primes.empty()) return -1;

        vector<int> uglyVec(n, 1);
        vector<int> counter(primes.size(), 0);

        for (int i = 1; i < n; ++i) {
            long long next = INT_MAX;
            for (int j = 0; j < primes.size(); ++j) {
                next = min(next, (long long)(uglyVec[counter[j]]) * primes[j]);
            }
            uglyVec[i] = next;

            for (int j = 0; j < primes.size(); ++j) {
                while ((long long)(uglyVec[counter[j]]) * primes[j] <= uglyVec[i]) {
                    ++counter[j];
                }
            }
        }
        return uglyVec.back();
    }
};