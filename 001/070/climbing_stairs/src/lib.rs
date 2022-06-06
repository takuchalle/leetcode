struct Solution {}
use std::collections::HashMap;

impl Solution {

    fn climb(n: i32, map: &mut HashMap<i32, i32>) -> i32 {
        if map.contains_key(&n) {
            return *map.get(&n).unwrap();
        }

        let x = match n {
            1 => 1,
            2 => 2,
            _ => Self::climb(n - 1, map) + Self::climb(n - 2, map),
        };

        map.insert(n, x);

        x
    }

    pub fn climb_stairs(n: i32) -> i32 {
        let mut map = HashMap::new();

        Solution::climb(n, &mut map)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(Solution::climb_stairs(2), 2);

        assert_eq!(Solution::climb_stairs(3), 3);

        assert_eq!(Solution::climb_stairs(45), 1836311903);
    }
}
