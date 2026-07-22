// 合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        std::sort(intervals.begin(), intervals.end());
        
        for (auto& interval : intervals) {
            int left = interval[0];
            int right = interval[1];
            if (res.empty()) {
                res.emplace_back(vector<int>{left, right});
                continue;
            }

            if (left > res.back()[1]) {         // ()[]
                res.emplace_back(vector<int>{left, right});
            } else if (right > res.back()[1]) { // ([)]
                res.back()[1] = right;
            } else {                            // ([])
                continue;
            }
        }
        return res;
    }
};