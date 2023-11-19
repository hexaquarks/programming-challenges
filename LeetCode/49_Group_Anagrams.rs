use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut map = HashMap::with_capacity(s.len());
        s.chars().for_each(|c| *map.entry(c).or_insert(0) += 1);
        t.chars().for_each(|c| *map.entry(c).or_insert(0) -= 1);
        map.into_values().all(|v| v == 0)
    }

    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut map: HashMap<String, Vec<String>> = HashMap::with_capacity(strs.len());

        for s in strs.into_iter() {
            let mut chars: Vec<char> = s.chars().collect();
            chars.sort_unstable();
            map.entry(chars.into_iter().collect()).or_default().push(s);
        }
        map.into_values().collect()
    }
}