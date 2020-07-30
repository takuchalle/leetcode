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

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn calc_depth(node: &Option<Rc<RefCell<TreeNode>>>) -> (i32, bool) {
        match node {
            None => (0, true),
            Some(n) => {
                let l = Solution::calc_depth(&n.borrow().left);
                let r = Solution::calc_depth(&n.borrow().right);

                let depth = std::cmp::max(l.0, r.0) + 1;
                let balanced = r.1 && l.1 && (l.0 - r.0).abs() <= 1;

                (depth, balanced)
            },
        }
    }

    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let (_, balanced) = Solution::calc_depth(&root);
        balanced
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {}
}
