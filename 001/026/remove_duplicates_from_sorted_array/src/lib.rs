struct Solution;

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut cnt = 0;
        let len = nums.len();

        if len <=1 {
            return len as i32;
        }

        for i in 1..len {
            if nums[cnt] != nums[i] {
                cnt += 1;
                nums[cnt] = nums[i];
            }
        }

        (cnt + 1) as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let mut vec = vec![1,1,2,3,4];
        assert_eq!(Solution::remove_duplicates(&mut vec), 4);

        let mut vec2 = vec![0,0,1,1,1,2,2,3,3,4];
        assert_eq!(Solution::remove_duplicates(&mut vec2), 5);

        let mut vec3 = vec![0];
        assert_eq!(Solution::remove_duplicates(&mut vec3), 1);

        let mut vec4 = vec![];
        assert_eq!(Solution::remove_duplicates(&mut vec4), 0);
    }
}
