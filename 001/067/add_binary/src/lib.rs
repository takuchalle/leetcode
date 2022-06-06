struct Solution {}

impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut s = String::new();
        let max_len = std::cmp::max(a.len(), b.len()) as usize;
        let mut carry = 0;
        let mut a = a.chars().map(|i| i as i32 - 48).collect::<Vec<i32>>();
        let mut b = b.chars().map(|i| i as i32 - 48).collect::<Vec<i32>>();
        a.reverse();
        b.reverse();

        for i in 0..max_len {
            let a = if i < a.len() { a[i] } else { 0 };
            let b = if i < b.len() { b[i] } else { 0 };

            let c = a + b + carry;
            match c {
                0 => {
                    carry = 0;
                    s.insert(0, '0');
                }
                1 => {
                    carry = 0;
                    s.insert(0, '1');
                }
                2 => {
                    carry = 1;
                    s.insert(0, '0');
                }
                3 => {
                    carry = 1;
                    s.insert(0, '1');
                }
                _ => panic!(),
            };

            println!("{}", c);
        }

        if carry == 1 {
            s.insert(0, '1');
        }

        s
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(
            Solution::add_binary("11".to_string(), "1".to_string()),
            "100".to_string()
        );

        assert_eq!(
            Solution::add_binary("1010".to_string(), "1011".to_string()),
            "10101".to_string()
        );

        assert_eq!(
            Solution::add_binary("11".to_string(), "11".to_string()),
            "110".to_string()
        );
    }
}
