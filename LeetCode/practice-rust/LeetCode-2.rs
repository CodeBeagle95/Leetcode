// 两数相加
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

struct Solution;

impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy_head = Some(Box::new(ListNode::new(0)));
        let mut curr_node = &mut dummy_head;
        let mut carry = 0;
        let mut p1 = &l1;
        let mut p2 = &l2;

        while p1.is_some() || p2.is_some() || carry != 0 {
            let mut sum = carry;

            if let Some(node) = p1 {
                sum += node.val;
                p1 = &node.next;
            }

            if let Some(node) = p2 {
                sum += node.val;
                p2 = &node.next;
            }

            carry = sum / 10;
            sum %= 10;

            curr_node.as_mut().unwrap().next = Some(Box::new(ListNode::new(sum)));
            curr_node = &mut curr_node.as_mut().unwrap().next;

            // let next_node = Some(Box::new(ListNode::new(sum)));
            // if let Some(node) = curr_node {
            //     node.next = next_node;
            //     curr_node = &mut node.next;
            // }
        }
        dummy_head.unwrap().next
    }
}

fn main () {
// 测试用例: 342 + 465 = 807
    // l1: 2 -> 4 -> 3
    let l1 = Some(Box::new(ListNode {
        val: 2,
        next: Some(Box::new(ListNode {
            val: 4,
            next: Some(Box::new(ListNode::new(3))),
        })),
    }));
    // l2: 5 -> 6 -> 4
    let l2 = Some(Box::new(ListNode {
        val: 5,
        next: Some(Box::new(ListNode {
            val: 6,
            next: Some(Box::new(ListNode::new(4))),
        })),
    }));

    let result = Solution::add_two_numbers(l1, l2);
    println!("{:?}", result);
}