use std::collections::HashSet;
use std::fs::read_to_string;

fn solution_day4a(filename: &str) -> i32 {
    let mut result = 0;

    for line in read_to_string(filename).unwrap().lines() {
        let split: Vec<&str> = line.split(": ").collect();
        let mut inner_result = 0;
        let mut count = 0;

        let win_data_split: Vec<&str> = split[1].split(" | ").collect();
        let mut win_vals: HashSet<&str> = win_data_split[0].split_whitespace().collect();

        win_data_split[1].trim().split_whitespace().for_each(|val| {
            if win_vals.contains(val) {
                inner_result = 2i32.pow(count);
                count += 1;
            }
        });

        result += inner_result;
    }
    result
}

fn main_entry() {
    println!("{}", solution_day4a("src/day4_input.txt"));
}
