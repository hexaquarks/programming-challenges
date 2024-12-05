use std::fs::read_to_string;

pub fn run(part: &str) {
    let filename = "inputs/day2.txt";

    match part {
        "a" => part_a(&filename),
        "b" => part_b(&filename),
        _ => println!("Invalid part: {}. Use 'a' or 'b'.", part),
    }
}

fn is_in_bounds(diff: i32, positive: bool) -> bool {
    if positive && !(diff == 1 || diff == 2 || diff == 3) {
        return false;
    }

    if !positive && !(diff == -1 || diff == -2 || diff == -3) {
        return false;
    }

    return true;
}

fn check_if_remove_one_makes_safe(numbers: &Vec<i32>) -> bool {
    for i in 0..numbers.len() {
        let reduced_numbers = [&numbers[..i], &numbers[i + 1..]].concat();
        if is_safe(&reduced_numbers) {
            return true;
        }
    }
    return false;
}

fn is_safe(numbers: &Vec<i32>) -> bool {
    let l = numbers[0];
    let r = numbers[1];

    if is_in_bounds(r - l, true) {
        for i in 1..numbers.len() - 1 {
            println!("considering {}, {}", numbers[i + 1], numbers[i]);
            let diff = numbers[i + 1] - numbers[i];
            if !is_in_bounds(diff, true) {
                return false;
            }
        }
    } else if is_in_bounds(r - l, false) {
        for i in 1..numbers.len() - 1 {
            println!("considering {}, {}", numbers[i + 1], numbers[i]);
            let diff = numbers[i + 1] - numbers[i];
            if !is_in_bounds(diff, false) {
                return false;
            }
        }
    } else {
        return false;
    }

    return true;
}

fn part_a(filename: &str) {
    println!("Running Day 2, Part A");

    let mut n_safe: i32 = 0;

    for line in read_to_string(filename).unwrap().lines() {
        let split: Vec<i32> = line
            .split(" ")
            .into_iter()
            .map(|s| s.parse::<i32>().unwrap())
            .collect();

        n_safe += is_safe(&split) as i32;
    }

    println!("{}", n_safe);
}

fn part_b(filename: &str) {
    println!("Running Day 2, Part B");

    let mut n_safe: i32 = 0;

    for line in read_to_string(filename).unwrap().lines() {
        let split: Vec<i32> = line
            .split(" ")
            .into_iter()
            .map(|s| s.parse::<i32>().unwrap())
            .collect();
        if is_safe(&split) {
            n_safe += 1;
        } else if check_if_remove_one_makes_safe(&split) {
            n_safe += 1;
        }
    }

    println!("{}", n_safe);
}
