// 寻找两个正序数组的中位数 - O(n + m)
use std::{cmp::max, cmp::min};

struct Solution;

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        if nums1.len() > nums2.len() {
            return Solution::find_median_sorted_arrays(nums2, nums1);
        }

        let (total1, total2) = (nums1.len() as i32, nums2.len() as i32);
        let half = (total1 + total2 + 1) / 2;
        let (mut left1, mut right1) = (0, total1);
        let (mut median1, mut median2) = (0, 0);
        
        while left1 <= right1 {
            let i = (left1 + right1) / 2; // 将 i 之前的元素划分出去
            let j = half - i;

            let i1 = if i == 0 { i32::MIN } else { nums1[(i - 1) as usize] };
            let i2 = if i == total1 { i32::MAX } else { nums1[i as usize] };
            let j1 = if j == 0 { i32::MIN } else { nums2[(j - 1) as usize] };
            let j2 = if j == total2 { i32::MAX } else { nums2[j as usize] };

            if i1 > j2 {        // 说明划分的左半段过大
                right1 = i - 1; // 位置 i 剔除 
            } else {
                median1 = max(i1, j1);
                median2 = min(i2, j2);
                left1 = i + 1;
            }
        }
        if (total1 + total2) % 2 == 0 {
            return (median1 + median2) as f64 / 2.0;
        } else {
            return  median1 as f64;
        }
    }
}

fn main () {
    let l1 = Solution::find_median_sorted_arrays(vec![2, 4, 7], vec![1, 5, 9]);
    println!("{:?}", l1);
}