// 乘积最大子数组
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;

        // 这里用double类型，否则会超出数值范围
        vector<double> maxV = vector<double>(sz, 1); // 记录以i为结束的子数组最大值
        vector<double> minV = vector<double>(sz, 1); // 记录以i为结束的子数组最小值
        maxV[0] = minV[0] = nums[0];
        for (int i = 1; i < sz; ++i) {
            maxV[i] = max(double(nums[i]), max(maxV[i-1]*nums[i], minV[i-1]*nums[i]));
            minV[i] = min(double(nums[i]), min(maxV[i-1]*nums[i], minV[i-1]*nums[i]));
        }
        return *max_element(maxV.begin(), maxV.end());
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int prevMax = nums[0], prevMin = nums[0], result = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                prevMax = 0;
                prevMin = 0;
            } else if (nums[i] > 0) {
                prevMax = max(prevMax * nums[i], nums[i]);
                prevMin = min(prevMin * nums[i], nums[i]);
            } else {
                int tmp = max(prevMin * nums[i], nums[i]); // 注意使用中间变量
                prevMin = min(prevMax * nums[i], nums[i]);
                prevMax = tmp;
            }
            result = max(result, prevMax);
        }
        return result;
    }
};