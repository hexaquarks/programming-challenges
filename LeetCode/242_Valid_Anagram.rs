// My solution
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        use std::collections::HashMap;

        if s.len() != t.len() { return false; }
        let mut map: HashMap<char, i32> = HashMap::with_capacity(s.len());

        for c in s.chars() {
            *map.entry(c).or_insert(0) += 1;
        }
        for c in t.chars() {
            *map.entry(c).or_insert(0) -= 1;
        }
        
        map.iter().all(|(k, v)| *v == 0)
    }
}

// Cleaner solution
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut map = std::collections::HashMap::with_capacity(s.len());
        s.chars().for_each(|c| *map.entry(c).or_insert(0) += 1);
        t.chars().for_each(|c| *map.entry(c).or_insert(0) -= 1);
        map.into_values().all(|v| v == 0)
    }
}

// Notes
//  1. instead of for t in T, it's cleaner to chain .for_each with closure
//  2. use colon accessors immediately instead of importing with use
//  3. when returning it's more logical to consume the source item. so do into_