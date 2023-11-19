use std::collections::HashMap;
use std::cmp::Reverse;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut map: HashMap<i32, i32> = HashMap::with_capacity(nums.len());

        nums.into_iter().for_each(|val| *map.entry(val).or_default() += 1);

        // Vector of el, frequency tuples
        let mut vec: Vec<(i32, i32)> = map.into_iter().collect();

        // note here the closure take by reference since we're borrowing the vector
        vec.sort_by_key(|&(key, freq)| Reverse(freq));

        // The vector doesnt have into_keys so here we convert into map then 
        // take the first k elements
        // Note here the closure does not take by reference since it's consuming vec
        vec.into_iter().map(|(key, freq)| key).take(k as usize).collect()
    }
}