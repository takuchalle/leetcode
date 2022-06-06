struct Solution {}

impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        if x == 0 {
            return 0i32;
        }

        let x = x as u32; // To avoid overflow
        let mut n = x;
        while n > x / n {
            n = (n + x / n) / 2;
        }

        n as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(Solution::my_sqrt(4), 2);

        assert_eq!(Solution::my_sqrt(8), 2);

        assert_eq!(Solution::my_sqrt(2147395599), 46339);

        assert_eq!(Solution::my_sqrt(2147483647), 46340);
    }
}
