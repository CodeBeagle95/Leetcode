// 反转链表
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }


impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut p0 = None;
        let mut p1 = head;
        
        while let Some(mut node) = p1 { // node 获取了所有权
            p1 = node.next.take();
            node.next = p0;
            p0 = Some(node);
        }
        p0
    }
}