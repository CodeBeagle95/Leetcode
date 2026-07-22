// 除了自身以外数组的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        // [1, 2, 3, 4] -> [24, 12, 4, 1]
        for (int i = ans.size() - 2; i >= 0; --i) {
            ans[i] = ans[i + 1] * nums[i + 1];
        }

        int mulFromleft = 1;
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = ans[i] * mulFromleft;
            mulFromleft *= nums[i];
        }
        return ans;
    }
};