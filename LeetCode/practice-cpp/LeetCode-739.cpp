// 每日温度
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> nextHigherDay(temperatures.size(), 0);
        stack<int> stk;

        for (int i = 0; i < temperatures.size(); ++i) {
            if (stk.empty() || temperatures[i] <= temperatures[stk.top()]) {
                stk.push(i);
                continue;
            }

            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                nextHigherDay[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i); // 推出栈内较低温度后需将当前温度索引入栈
        }
        return nextHigherDay;
    }
};