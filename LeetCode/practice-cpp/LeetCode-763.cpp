// 划分字母区间
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> charMaxIndex;
        for (int i = 0; i < s.size(); ++i) {
            charMaxIndex[s[i]] = i;
        }

        int startIndex = 0;
        vector<int> partionLength;
        for (int i = 0; i < s.size(); ++i) {
            int maxIndex = charMaxIndex[s[i]];
            for (int j = i + 1; j <= maxIndex; ++j) {
                maxIndex = max(maxIndex, charMaxIndex[s[j]]);
            }
            partionLength.push_back(maxIndex - startIndex + 1);
            startIndex = maxIndex + 1;
            i = maxIndex;
        }
        return partionLength;
    }
};