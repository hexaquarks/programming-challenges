use std::io::{stdin, BufRead};

fn main() {
    let mut numbers = stdin().lock()
        .lines()
        .map(|l| l.unwrap().trim().parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
        
    let tot = numbers.iter().sum::<i32>();
    let diff = tot - 100;
    let mut indices = (0, 0);
    
    'outer: for i in 0..numbers.len() {
        for j in (i + 1)..numbers.len() {
            if numbers[i] + numbers[j] == diff {
                indices = (i, j);
                break 'outer;
            }
        }
    }
    numbers.iter()
        .enumerate()
        .filter(|(i, _)| *i != indices.0 && *i != indices.1)
        .for_each(|(_, e)| println!("{}", e));
}