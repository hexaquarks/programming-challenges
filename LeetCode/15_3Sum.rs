use std::collections::HashMap;
use std::collections::HashSet;

// My solution
impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut set: HashSet<Vec<_>> = HashSet::new();
        for i in 0..nums.len() {
            let curr = nums[i];
            let mut map: HashMap<i32, i32> = HashMap::new();
            let mut sub_target = 0 - nums[i];

            for j in (i + 1)..nums.len() {
                if (j == i) { continue; }

                let sub_curr = sub_target - nums[j];

                match map.get(&sub_curr) {
                    Some(&idx) => { 
                        if idx as usize != j && idx as usize != i {
                            let mut triplet = vec![curr, nums[j], sub_curr];
                            triplet.sort();  
                            set.insert(triplet);
                        }
                    },
                    None => { map.insert(nums[j], j as i32); }
                };
            }
        }
        set.into_iter().collect()
    }
}

// 2 pointer solution (much faster of course)
impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        nums.sort();

        for i in 0..nums.len() {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }

            let mut left = i + 1;
            let mut right = nums.len() - 1;

            while left < right {
                let sum = nums[i] + nums[left] + nums[right];
                if sum > 0 {
                    right -= 1;
                } else if sum < 0 {
                    left += 1
                } else {
                    res.push(vec![nums[i], nums[left], nums[right]]);
                    left += 1;

                    while nums[left] == nums[left - 1] && left < right {
                        left += 1;
                    }
                }
            }
        }

        return res;
    }
}