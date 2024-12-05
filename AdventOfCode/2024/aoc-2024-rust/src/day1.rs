use std::collections::HashMap;
use std::fs::read_to_string;

pub fn run(part: &str) {
    let filename = "inputs/day1.txt";

    match part {
        "a" => part_a(&filename),
        "b" => part_b(&filename),
        _ => println!("Invalid part: {}. Use 'a' or 'b'.", part),
    }
}

fn part_a(filename: &str) {
    println!("Running Day 1, Part A");
    let mut left_list = vec![];
    let mut right_list = vec![];

    for line in read_to_string(filename).unwrap().lines() {
        let (l, r) = line.split_once("   ").unwrap();
        left_list.push(l.to_string());
        right_list.push(r.to_string());
    }

    left_list.sort();
    right_list.sort();

    let mut sum: i32 = 0;

    for it in left_list.iter().zip(right_list.iter_mut()) {
        println!("{}, {}", it.0, it.1);
        sum += (it.0.parse::<i32>().unwrap() - it.1.parse::<i32>().unwrap()).abs();
    }

    println!("{}", sum);
}

fn part_b(filename: &str) {
    println!("Running Day 1, Part B");

    let mut right_map: HashMap<i32, u8> = HashMap::new();

    for line in read_to_string(filename).unwrap().lines() {
        let (_, r) = line.split_once("   ").unwrap();
        *right_map.entry(r.parse::<i32>().unwrap()).or_insert(0) += 1;
    }

    let mut similarity: i32 = 0;

    for line in read_to_string(filename).unwrap().lines() {
        let (l, _) = line.split_once("   ").unwrap();
        let li32 = l.parse::<i32>().unwrap();
        if let Some(val) = right_map.get(&li32) {
            similarity += li32 * *val as i32;
        }
    }

    println!("{}", similarity);
}
