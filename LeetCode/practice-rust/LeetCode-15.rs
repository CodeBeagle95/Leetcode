// 三数之和
use std::collections::HashMap;

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = vec![];
        let mut num_counter_map: HashMap<i32, i32> = HashMap::new();

        nums.sort_unstable();

        for num in nums.iter() {
            *num_counter_map.entry(*num).or_insert(0) += 1;
        }

        for i in 0..nums.len() {
            if i > 0 && nums[i - 1] == nums[i] {
                continue;
            }
            for j in i + 1..nums.len() {
                if j > i + 1 && nums[j - 1] == nums[j] {
                    continue;
                }
                let target = -(nums[i] + nums[j]);
                let counter = num_counter_map.get(&target).copied().unwrap_or(0);
                if target < nums[j] {
                    continue;
                } else if (nums[i] == target && nums[j] == target && counter <= 2) ||
                        ((nums[i] == target || nums[j] == target) && counter <= 1) ||
                        (counter == 0) {
                    continue;
                } else {
                    result.push(vec![nums[i], nums[j], target]);
                }
            }
        }
        result
    }
}
