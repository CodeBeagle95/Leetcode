// 罗马数字转整数
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dict{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int prev = 0;
        int ans = 0;
        for (auto& c : s) {
            int num = dict[c];
            if (prev != 0 && num > prev) {
                ans = ans - 2 * prev + num; // 发现后面的数比前面的大，减去双倍prev
            } else {
                ans += num;
            }
            prev = num;
        }
        return ans;
    }
};