// 寻找两个正序数组的中位数 - O(n + m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int leftIndex1 = 0;
        int leftIndex2 = 0;
        int rightIndex1 = nums1.size() - 1;
        int rightIndex2 = nums2.size() - 1;

        int smallNum, largeNum = 0;

        while(leftIndex1 <= rightIndex1 || leftIndex2 <= rightIndex2) { 
        
            // 从左侧取两个数组较小的数字
            if (leftIndex1 <= rightIndex1 && leftIndex2 <= rightIndex2) {
                if (nums1[leftIndex1] < nums2[leftIndex2]) {
                    smallNum = nums1[leftIndex1];
                    ++leftIndex1;
                } else {
                    smallNum = nums2[leftIndex2];
                    ++leftIndex2;
                }
            } else if (leftIndex1 <= rightIndex1 && leftIndex2 > rightIndex2) {
                smallNum = nums1[leftIndex1];
                ++leftIndex1;
            } else if (leftIndex1 > rightIndex1 && leftIndex2 <= rightIndex2) {
                smallNum = nums2[leftIndex2];
                ++leftIndex2;
            }

            // 从右侧取两个数组较大的数字
            if (leftIndex1 <= rightIndex1 && leftIndex2 <= rightIndex2) {
                if (nums1[rightIndex1] > nums2[rightIndex2]) {
                    largeNum = nums1[rightIndex1];
                    --rightIndex1;
                } else {
                    largeNum = nums2[rightIndex2];
                    --rightIndex2;
                }
            } else if (leftIndex1 <= rightIndex1 && leftIndex2 > rightIndex2) {
                largeNum = nums1[rightIndex1];
                --rightIndex1;
            } else if (leftIndex1 > rightIndex1 && leftIndex2 <= rightIndex2) {
                largeNum = nums2[rightIndex2];
                --rightIndex2;
            } else { // 处理数据被取完的情况
                largeNum = smallNum;
            }

        }

        return (largeNum + smallNum) / 2.0;
    }
};

// 寻找两个正序数组的中位数 - log(min(n, m))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) { // 交换数组使得第一个数组长度较小
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int total1 = nums1.size(), total2 = nums2.size();
        int half = (total1 + total2 + 1) / 2; // 左边数量可大于右边
        int left1 = 0, right1 = nums1.size();
        int midain1 = 0, midain2 = 0;
        
        while (left1 <= right1) {         // 从 left 到 right 都可作为分割点
            int i = (left1 + right1) / 2; // 将 i 之前的元素划分出去
            int j = half - i;             // 将 j 之前的元素划分出去，由于交换了数组 j 必然在索引范围内
            
            int i1 = (i == 0) ? INT_MIN : nums1[i - 1];  // 使用 INT_MIN 辅助计算
            int i2 = (i == total1) ? INT_MAX : nums1[i]; // 使用 INT_MAX 辅助计算
            int j1 = (j == 0) ? INT_MIN : nums2[j - 1];  // 使用 INT_MIN 辅助计算
            int j2 = (j == total2) ? INT_MAX : nums2[j]; // 使用 INT_MAX 辅助计算

            if (i1 > j2) {      // 说明划分的左半段过大
                right1 = i - 1; // 位置 i 剔除
            } else {            // 计算中位数，同时右半段仍存在符合条件的解
                midain1 = max(i1, j1);
                midain2 = min(i2, j2);
                left1 = i + 1;
            }
        }
        return (total1 + total2) % 2 ? midain1 : (midain1 + midain2) / 2.0;
    }
};