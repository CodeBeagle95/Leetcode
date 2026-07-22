use std::{cmp::max, collections::HashMap};

struct Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let str = s.as_bytes();
        let mut result = 0;
        let mut from_index = 0;
        let mut char_index_map :HashMap<_, _> = HashMap::new();

        for (i, c) in str.iter().enumerate() {
            match char_index_map.get(c) {
                Some(&repeat_index) => {
                    char_index_map.insert(c, i);
                    for j in from_index..repeat_index {
                        char_index_map.remove(&str[j]);
                    }
                    from_index = repeat_index + 1;
                },
                _ => {
                    char_index_map.insert(c, i);
                    result = max(result, i - from_index + 1);
                }
            }
        }
        result as i32
    }
}

fn main () {
    let l1 = Solution::length_of_longest_substring(String::from("jdhkasdjhfdjhf"));
    println!("{:?}", l1);
}