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
    fn depth(node: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match node {
            None => 0,
            Some(n) => {
                let l = Solution::depth(&n.borrow().left);
                let r = Solution::depth(&n.borrow().right);
                1 + match (l, r) {
                    (0, r) => r,
                    (l, 0) => l,
                    (l, r) => std::cmp::min(l, r),
                }
            },
        }
    }
    
    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Solution::depth(&root)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {}
}
