// 最长回文子串
struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        if s.is_empty() { return String::new(); }

        let mut str = vec!['#'; s.len() * 2 + 1];
        for (i, c) in s.as_bytes().iter().enumerate() {
            str[2 * i + 1] = *c as char;
        }

        let mut arm_lens = vec![0; str.len()];
        let (mut curr_center, mut curr_arm_len) = (0, 0);
        let (mut best_center, mut best_arm_len) = (0, 0);

        for (i, _) in str.iter().enumerate() {
            let mut len = 0;
            if i > curr_center + curr_arm_len {
                // nothing
            } else if i + arm_lens[2 * curr_center - i] > curr_center + curr_arm_len {
                len = curr_center + curr_arm_len - i;
            } else {
                len = arm_lens[2 * curr_center - i];
            }

            while i > len && i + len + 1 < str.len() && str[i - len - 1] == str[i + len + 1] {
                len += 1;
            }
            arm_lens[i] = len;

            if i + len > curr_center + curr_arm_len {
                curr_center = i;
                curr_arm_len = len;
            }

            if len > best_arm_len {
                best_center = i;
                best_arm_len = len;
            }
        }
        let start_index = (best_center - best_arm_len) / 2;
        s[start_index..start_index + best_arm_len].to_string()
    }
}

fn main () {
    let l1 = Solution::longest_palindrome(String::from("babad"));
    println!("{:?}", l1);
}