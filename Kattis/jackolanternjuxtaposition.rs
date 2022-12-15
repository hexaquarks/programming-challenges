use std::io::{self};

fn main() {
    let mut numbers = String::new();
    io::stdin().read_line(&mut numbers);

    let numbers: Vec<i32> = numbers
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let ans = numbers.iter().fold(1, |sum, val| sum * val);
    
    print!("{ans}");
}