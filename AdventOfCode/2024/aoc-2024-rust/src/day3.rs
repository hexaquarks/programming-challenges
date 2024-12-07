use std::collections::HashMap;
use std::fs::read_to_string;

pub fn run(part: &str) {
    let filename = "inputs/day3.txt";

    match part {
        "a" => part_a(&filename),
        "b" => part_b(&filename),
        _ => println!("Invalid part: {}. Use 'a' or 'b'.", part),
    }
}

fn find_all_occurrences(input: &str, word: &str) -> Vec<usize> {
    let mut indices = Vec::new();
    let mut start = 0;
    while let Some(index) = input[start..].find(word) {
        let absolute_index = start + index;
        indices.push(absolute_index);
        start = absolute_index + word.len();
    }
    indices
}

fn parse_instructions(input: &str, start: usize) -> Option<i32> {
    let start_of_args = start + "mul(".len();
    let rest = &input[start_of_args..];

    if let Some(idx_closed_bracket) = rest.find(')') {
        let range = &rest[..idx_closed_bracket];
        let split: Vec<&str> = range.split(',').collect();

        if split.len() != 2 {
            return None;
        }

        if let Ok(val_1) = split[0].parse::<i32>() {
            if let Ok(val_2) = split[1].parse::<i32>() {
                return Some(val_1 * val_2);
            }
        }
    }

    None
}

fn get_enabled_intervals(
    input: &str,
    do_occurrences: &Vec<usize>,
    dont_occurrences: &Vec<usize>,
) -> Vec<(usize, usize)> {
    let mut events = Vec::new();
    for &d in do_occurrences {
        events.push((d, "do"));
    }
    for &d in dont_occurrences {
        events.push((d, "dont"));
    }
    events.sort_by_key(|(pos, _)| *pos);

    let mut intervals = Vec::new();
    let mut enabled = true;
    let mut current_start = 0;

    for (pos, t) in events.iter() {
        if enabled && *t == "dont" {
            intervals.push((current_start, *pos));
            enabled = false;
            current_start = *pos;
        } else if !enabled && *t == "do" {
            enabled = true;
            current_start = *pos;
        }

        if *t == "do" {
            enabled = true;
            current_start = *pos;
        } else if *t == "dont" {
            if enabled {
                intervals.push((current_start, *pos));
            }
            enabled = false;
            current_start = *pos;
        }
    }

    if enabled {
        intervals.push((current_start, input.len()));
    }

    intervals
}

fn part_a(filename: &str) {
    println!("Running Day 3, Part A");
    let input: String = read_to_string(filename).unwrap().to_string();
    let occurences: Vec<usize> = find_all_occurrences(input.as_str(), "mul(");
    let mut sum = 0;

    for occcurence in occurences.iter() {
        // println!("considering {}", occcurence);
        if let Some(res) = parse_instructions(input.as_str(), *occcurence) {
            sum += res;
        }
    }

    println!("{}", sum);
}

fn part_b(filename: &str) {
    println!("Running Day 3, Part B");
    let input: String = read_to_string(filename).unwrap().to_string();
    let mul_occurences: Vec<usize> = find_all_occurrences(input.as_str(), "mul(");
    let do_occurences: Vec<usize> = find_all_occurrences(input.as_str(), "do()");
    let dont_occurences: Vec<usize> = find_all_occurrences(input.as_str(), "don't()");

    let intervals = get_enabled_intervals(&input, &do_occurences, &dont_occurences);

    let mut sum = 0;
    for (start, end) in intervals.iter() {
        for occ in mul_occurences.iter() {
            if occ >= start && occ < end {
                if let Some(idx_close) = input[*occ..].find(')') {
                    let full_call_end = occ + idx_close;
                    if full_call_end < *end {
                        if let Some(res) = parse_instructions(&input, *occ) {
                            sum += res;
                        }
                    }
                }
            }
        }
    }

    println!("{}", sum);
}
