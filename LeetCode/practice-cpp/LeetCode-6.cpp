// Z 字形变换
class Solution {
public:
    string convert(string s, int numRows) {
        // 找出每一行的步长规律, 假设总行数N, 当前行数 n=0,1,2,...
        // 0: 2*(N-1)
        // 1: 2*(N-2), 2*1
        // 2: 2*(N-3), 2*2
        // ...
        // n: 2*(N-n-1), 2*n
        
        // 注意处理特殊情况
        if (numRows <= 1 || s.size() <= numRows) return s;

        string result(s.size(), ' ');
        int curIndex = 0;
        
        for (int i = 0; i < numRows; ++i) { // 按行数循环
            int index = i;
            int pace1 = 2 * (numRows - 1 - i);
            int pace2 = 2 * i;
            result[curIndex++] = s[index]; // 加入首个字母
            while (index < s.size()) {
                if (pace1 > 0 && index + pace1 < s.size()) {
                    result[curIndex++] = s[index + pace1];
                }
                if (pace2 > 0 && index + pace1 + pace2 < s.size()) {
                    result[curIndex++] = s[index + pace1 + pace2];
                }
                index += pace1 + pace2;
            }
        }
        return result;
    }
};