// 前 K 个高频元素
class Solution {
private:
    static bool compareFreq(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // 最小堆
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numFreqMap;
        for (auto& num : nums) {
            ++ numFreqMap[num];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compareFreq)> pq(&compareFreq);
        for (auto iter = numFreqMap.begin(); iter != numFreqMap.end(); ++iter) {
            pq.push(*iter);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};