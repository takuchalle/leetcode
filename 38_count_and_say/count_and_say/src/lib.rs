struct Solution;

impl Solution {
    fn count(n: i32) -> String {
        if n == 1 {
            "1".to_string()
        } else {
            let prev = Solution::count(n - 1);
            let mut s = String::new();

            let mut cur = 0;
            let mut cnt = 1;

            for c in prev.chars() {
                let num = c as i32 - 48;

                if cur == 0 {
                    cur = num;
                } else {
                    if cur == num {
                        cnt += 1;
                    } else {
                        s.push_str(&cnt.to_string());
                        s.push_str(&cur.to_string());

                        cur = num;
                        cnt = 1;
                    }
                }
                println!("{}", num);
            }

            s.push_str(&cnt.to_string());
            s.push_str(&cur.to_string());

            s
        }
    }
    
    pub fn count_and_say(n: i32) -> String {
        Solution::count(n)
    }
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(Solution::count_and_say(1), "1".to_string());

        assert_eq!(Solution::count_and_say(2), "11".to_string());

        assert_eq!(Solution::count_and_say(3), "21".to_string());

        assert_eq!(Solution::count_and_say(4), "1211".to_string());

        assert_eq!(Solution::count_and_say(5), "111221".to_string());

        assert_eq!(Solution::count_and_say(6), "312211".to_string());

        assert_eq!(Solution::count_and_say(7), "13112221".to_string());
    }
}
