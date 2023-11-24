impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let iter = s.chars().filter(|x| x.is_ascii_alphanumeric()).map(|x| x.to_ascii_lowercase());
        iter.clone().eq(iter.rev())
    }
}