struct Solution {}

// Definition for singly-linked list.
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

impl Solution {
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {
            return None;
        }

        let mut org = head;
        let mut tail = org.as_mut().unwrap(); // 先頭ノード Box<ListNode> へのミュータブル参照

        while let Some(node) = tail.next.as_mut() { // none も Box<ListNode> へのミュータブル参照
            if tail.val == node.val {
                // node を削除して、tail->next に node->next を入れる
                let n = std::mem::replace(&mut node.next, None); // node.next を None と置き換えて n に束縛する。node->next の所有権が n に移る
                std::mem::replace(&mut tail.next, n); // n を tail.next と置き換える。n の所有権が tail.next に移る
            } else {
                tail = tail.next.as_mut().unwrap();
            }
        }

        org
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
    }
}
