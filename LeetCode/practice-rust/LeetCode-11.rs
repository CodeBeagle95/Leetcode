// 盛最多水的容器
use std::cmp;

struct Solution;

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut max_value = 0;
        let (mut left, mut right) = (0, height.len() - 1);

        while left < right {
            let deep = cmp::min(height[left], height[right]) as usize;
            max_value = cmp::max(max_value, deep * (right - left));
            if height[left] < height[right] {
                left += 1;
            } else {
                right -= 1;
            }
        }
        max_value as i32
    }
}

fn main () {
    let result = Solution::max_area(vec![1, 2, 3, 4]);
    println!("{:?}", result);
}