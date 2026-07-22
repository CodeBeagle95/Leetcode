// 两数之和
use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut num_index_map: HashMap<i32, usize> = HashMap::new();
        for (index, &num) in nums.iter().enumerate() {
            let component = target - num;
            if let Some(&another) = num_index_map.get(&component) {
                return vec![index as i32, another as i32];
            }
            num_index_map.insert(num, index);
        }
        panic!("Cann't found result!");
    }
}

fn main () {
    let result = Solution::two_sum(vec![1, 2, 3, 4], 6);
    println!("{:?}", result);
}