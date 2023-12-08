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

fn solution_day4b(filename: &str) -> i32 {
    let mut result = 0;
    let file_contents = read_to_string(filename).unwrap();
    let mut card_counts: Vec<usize> = Vec::new();

    for line in file_contents.lines() {
        let split: Vec<&str> = line.split(": ").collect();
        let win_data_split: Vec<&str> = split[1].split(" | ").collect();
        let original_vals: HashSet<&str> = win_data_split[0].split_whitespace().collect();

        let matches = win_data_split[1]
            .trim()
            .split_whitespace()
            .filter(|&val| original_vals.contains(val))
            .count();

        // Add the original card
        card_counts.push(matches);
    }

    let mut updated_card_counts: Vec<usize> = vec![1; card_counts.len()];

    for (idx, &matches) in card_counts.iter().enumerate() {
        let curr_val = updated_card_counts[idx];
        result += curr_val;

        if idx == card_counts.len() || matches == 0 {
            continue;
        }

        for _ in 0..curr_val {
            for offset in 1..=matches {
                let new_idx = idx + offset;
                if (new_idx < card_counts.len()) {
                    updated_card_counts[new_idx] += 1;
                }
            }
        }
    }
    result as i32
}

fn main_entry() {
    println!("{}", solution_day4a("src/day4_input.txt"))
    println!("{}", solution_day4b("src/day4_input.txt"))
}
