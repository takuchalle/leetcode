struct Solution {}

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let mut m = m as usize;
        let mut n = n as usize;
        let mut index = (nums1.len() - 1) as usize;

        while n > 0 && m > 0 {
            if nums1[m - 1] > nums2[n - 1] {
//                println!("m {:?}", m);
                nums1[index] = nums1[m - 1];
                m -= 1;
            } else {
//                println!("n {:?}", n);
                nums1[index] = nums2[n - 1];
                n -= 1;
            }
            index -= 1;
        }

        if n > 0 {
            for i in 0..n {
                nums1[i] = nums2[i];
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let mut nums1 = vec![1,2,3,0,0,0];
        let mut nums2 = vec![2,5,6];
        Solution::merge(&mut nums1, 3, &mut nums2, 3);
        assert_eq!(nums1, vec![1,2,2,3,5,6]);

        let mut nums1 = vec![0];
        let mut nums2 = vec![1];
        Solution::merge(&mut nums1, 0, &mut nums2, 1);
        assert_eq!(nums1, vec![1]);


    }
}
