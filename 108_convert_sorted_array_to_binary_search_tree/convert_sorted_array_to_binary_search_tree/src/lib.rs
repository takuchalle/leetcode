struct Solution {}
// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn _sorted_array_to_bst(nums: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        match nums.len() {
            0 => None,
            n => {
                let mid = n / 2;
                let mut m = TreeNode::new(nums[mid]);

                if mid > 0 {
                    m.left = Solution::_sorted_array_to_bst(&nums[0..mid]);
                }

                if mid + 1 < n {
                    m.right = Solution::_sorted_array_to_bst(&nums[mid + 1..]);
                }

                Some(Rc::new(RefCell::new(m)))
            },
        }
    }

    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Solution::_sorted_array_to_bst(&nums[..])
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {}
}
