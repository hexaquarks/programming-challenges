use std::io::{self};

fn main() {
    let mut num = String::new();
    io::stdin().read_line(&mut num).unwrap();
    let n = num.trim().parse::<i32>().unwrap();
    
    print!("{}", (n * (n-1) * (n-2) * (n-3)) / 24);
}