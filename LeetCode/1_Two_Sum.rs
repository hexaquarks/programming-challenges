use std::collections::HashMap;

// My solution
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, i32> = HashMap::new();

        for (i, &el) in nums.iter().enumerate() {
            for (&key, val) in map.iter() {
                if &target - val == el {
                    return vec![key, i as i32];
                }
            }
            map.insert(i as i32, el);
        }  

        return vec![]; 
    }
}

// Cooler solution
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        use std::collections::HashMap;

        let mut map: HashMap<i32, i32> = HashMap::new();

        for (i, el) in nums.iter().enumerate() {
            match map.get(&(target - *el)) {
                Some(&j) => return vec![i as i32, j],
                None => map.insert(*el, i as i32),
            };

        }  

        vec![] 
    }
}

// Notes: 
//  1. We can use the imports inside of function blocks lol
//  2. vec![] without semicolon and return keyword at the end of a function,
//     because expression matching of rust acts like return vec![];
//  3. match is genereally good for  


// Additionnal small performance improvements
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        use std::collections::HashMap;

        let mut map: HashMap<i32, i32> = HashMap::with_capacity(nums.len());

        for (i, el) in nums.iter().enumerate() {
            match map.get(&(target - *el)) {
                Some(&j) => return vec![i as i32, j],
                None => map.insert(*el, i as i32),
            };
        }  
        unreachable!()
    }
}

