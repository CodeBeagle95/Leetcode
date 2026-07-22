// 寻找重复数 - 快慢指针 2 * (a + b) = a + n * (b + c) + b => a = (n - 1) * (b + c) + c ，结论：从哪里出发并不重要
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;
        
        int p1 = 0, p2 = 0;
        while(true){
            p1 = nums[p1];
            p2 = nums[nums[p2]];
            if(nums[p1] == nums[p2]) break;
        }
        p1 = 0;
        while(nums[p1] != nums[p2]){
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return nums[p1];
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;

        int p0 = 0, p1 = 0;
        while (true) {
            p0 = nums[p0];
            p1 = nums[nums[p1]];
            if (p0 == p1) {
                break;
            }
        }

        p0 = 0;
        while (p0 != p1) {
            p0 = nums[p0];
            p1 = nums[p1];
        }
        return p0;
    }
};