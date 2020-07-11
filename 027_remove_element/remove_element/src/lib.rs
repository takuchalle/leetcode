struct Solution;

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut cnt = 0;

        for i in 0..nums.len() {
            if val != nums[i] {
                nums[cnt] = nums[i];
                cnt += 1;
            }
        }

        (cnt) as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let mut vec = vec![3,2,2,3];
        assert_eq!(Solution::remove_element(&mut vec, 3), 2);

        let mut vec = vec![0,1,2,2,3,0,4,2];
        assert_eq!(Solution::remove_element(&mut vec, 2), 5);
    }
}
