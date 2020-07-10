struct Solution;

impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let (mut left, mut right) = (0, nums.len() - 1);
        
        while left < right {
            let middle = (right + left) / 2; 
            
            if target == nums[middle] {
                left = middle;
                break;
            } else if target < nums[middle] {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        if nums[left] < target {
            left += 1;
        }

        left as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let vec = vec![1,3,5,6];
        assert_eq!(Solution::search_insert(vec, 5), 2);

        let vec = vec![1,3,5,6];
        assert_eq!(Solution::search_insert(vec, 2), 1);
    }
}
