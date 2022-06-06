struct Solution {}

impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut digits = digits;
        let mut carry = 1;

        for i in 0..digits.len() {
            let i = digits.len() - 1 - i;
            digits[i] += carry;
            carry = 0;
            if digits[i] >= 10 {
                digits[i] -= 10;
                carry = 1;
            }
        }

        if carry == 1 {
            digits.insert(0, 1)
        } 
        digits
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(Solution::plus_one(vec![1,2,3]), vec![1,2,4]);

        assert_eq!(Solution::plus_one(vec![9]), vec![1,0]);

        assert_eq!(Solution::plus_one(vec![9,9]), vec![1,0,0]);
    }
}
