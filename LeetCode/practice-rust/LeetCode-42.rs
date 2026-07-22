// 接雨水
use std::cmp;

struct Solution;

impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        if height.is_empty() { return 0; }

        let mut max_right = 0;
        let from_right: Vec<i32> = height.iter().rev()
            .map(|&num|{
                max_right = cmp::max(max_right, num);
                max_right
            }).collect();        

        let mut max_left = 0;
        height.iter().zip(from_right.iter().rev())
            .map(|(&num, &max_right)|{
                max_left = cmp::max(max_left, num);
                cmp::min(max_left, max_right) - num
            }).sum()
    }
}

fn main () {
    let l1 = Solution::trap(vec![0,1,0,2,1,0,1,3,2,1,2,1]);
    println!("{:?}", l1);
}