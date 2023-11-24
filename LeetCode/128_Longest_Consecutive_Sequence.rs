use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        if nums.len() == 0 { return 0; }
        
        let mut set: HashSet<i32> = HashSet::new(); 
        let mut ans: i32 = 1;
        nums.into_iter().for_each(|x| { set.insert(x); });

        set.iter().for_each(|x| {
            if !set.contains(&(*x - 1)) {
                let mut acc: i32 = 1;
                let mut num: i32 = *x;
                while set.contains(&(num + 1)) {
                    num += 1;
                    acc += 1;
                }
                ans = std::cmp::max(ans, acc);
            }
        });
        ans
    }
}

// Much more rustician solution
impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let num_set: HashSet<_> = nums.into_iter().collect();
        let mut ans = 0;
        for &num in &num_set {
            if !num_set.contains(&(num - 1)) {
                let count = (num..).take_while(|x| num_set.contains(x)).count();
                ans = ans.max(count);
            }
        }
        ans as i32
    }
}