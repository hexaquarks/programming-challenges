use std::fs::read_to_string;

fn is_set_possible(set: Vec<&str>) -> bool {
    let cube_value_pairs: Vec<&str> = set.split(", ").collect();
    let mut red_value = 0;
    let mut blue_value = 0;
    let mut green_value = 0;

    for cube_value_pair in cube_value_pairs.iter() {
        let cube_value_split: Vec<&str> = cube_value_pair.split_whitespace().collect();
        let value = cube_value_split[0].parse::<i32>().unwrap();
        match cube_value_split[1] {
            "red" => red_value += value,
            "blue" => blue_value += value,
            "green" => green_value += value,
            _ => {}
        }
    }

    !(red_value > 12 || blue_value > 14 || green_value > 13)
}

fn solution_day2a(filename: &str) -> i32 {
    let mut result = 0;

    for line in read_to_string(filename).unwrap().lines() {
        let split: Vec<&str> = line.split(": ").collect();
        let game_id = split[0].split_whitespace().collect::<Vec<_>>()[1]
            .parse::<i32>()
            .unwrap();
        let mut is_game_possible = true;

        let sets: Vec<&str> = split[1].split("; ").collect();
        for set in sets.iter() {
            if (!is_set_possible(set)) {
                is_game_possible = false;
                break;
            }
        }

        if is_game_possible {
            result += game_id;
        }
    }
    result
}

fn solution_day2b(filename: &str) -> i32 {
    let mut result = 0;

    for line in read_to_string(filename).unwrap().lines() {
        let mut max_red = 0;
        let mut max_blue = 0;
        let mut max_green = 0;

        let tries: Vec<&str> = line.split(": ").collect::<Vec<_>>()[1]
            .split("; ")
            .collect();
        for local_try in tries.iter() {
            let cubes: Vec<&str> = local_try.split(", ").collect();

            for cube in cubes.iter() {
                let inner_split: Vec<&str> = cube.split_whitespace().collect();
                let val = inner_split[0].parse::<i32>().unwrap();
                match inner_split[1] {
                    "red" => max_red = std::cmp::max(max_red, val),
                    "blue" => max_blue = std::cmp::max(max_blue, val),
                    "green" => max_green = std::cmp::max(max_green, val),
                    _ => {}
                }
            }
        }

        result += (max_red * max_blue * max_green);
    }
    result
}

fn main_entry() {
    println!("{}", solution_day2a("src/day2_input.txt"));
    println!("{}", solution_day2b("src/day2_input.txt"));
}
