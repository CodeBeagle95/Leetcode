// 字符串相乘
class Solution {
private:
    string add(const string num1, const string num2) {
        const int len1 = num1.size(), len2 = num2.size();
        const int len3 = (len1 > len2) ? len1 : len2;
        string result(len3 + 1, '0');
        
        bool flag = false;
        int cur1 = len1 - 1, cur2 = len2 - 1;
        for (int i = 0; i <= len3; ++i) {
            int n1 = (cur1 >= 0) ? num1[cur1--] - '0' : 0;
            int n2 = (cur2 >= 0) ? num2[cur2--] - '0' : 0;
            result[len3 - i] += n1 + n2 + flag;
            flag = false;
            if (result[len3 - i] > '9') {
                result[len3 - i] -= 10;
                flag = true;
            }
        }
        return result[0] == '0' ? result.substr(1, len3) : result;
    }

    string multiply(const string num, const char count) {
        if (num.empty() || count == '0') return "0";
        string result(num.size() + 1, '0');

        int temp = 0;
        for (int i = num.size() - 1; i >= 0; --i) {
            temp += (num[i] - '0') * (count - '0');
            result[i + 1] += temp % 10;
            temp /= 10;
        }
        result[0] += temp;
        return result[0] == '0' ? result.substr(1, num.size()) : result;
    }
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "";
        if (num1.size() > num2.size()) return multiply(num2, num1);

        string result = "0";
        for (int i = num1.size() - 1; i >= 0; --i) {
            string temp = multiply(num2, num1[i]) + string(num1.size() - i - 1, '0');
            result = add(result, temp);
        }
        return result;
    }
};