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
    fn _level_order_bottom(
        root: &Option<Rc<RefCell<TreeNode>>>,
        level: usize,
        vec: &mut Vec<Vec<i32>>,
    ) {
        if let Some(node) = root {
            if level == vec.len() {
                vec.push(vec![]);
            }

            Solution::_level_order_bottom(&node.borrow().left, level + 1, vec);
            Solution::_level_order_bottom(&node.borrow().right, level + 1, vec);

            vec[level].push(node.borrow().val);
        }
    }

    pub fn level_order_bottom(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut v: Vec<Vec<i32>> = vec![];

        Solution::_level_order_bottom(&root, 0, &mut v);

        v.reverse();
        v
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {}
}
