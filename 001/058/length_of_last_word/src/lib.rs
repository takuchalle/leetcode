struct Solution {}

impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        match s.split_whitespace().last() {
            Some(word) => word.len() as i32,
            None => 0i32
        }
    }
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(Solution::length_of_last_word("Helllo World".to_string()), 5);

        assert_eq!(Solution::length_of_last_word("a ".to_string()), 1);

        assert_eq!(Solution::length_of_last_word("".to_string()), 0);

        assert_eq!(Solution::length_of_last_word(" ".to_string()), 0);
    }
}
