use std::collections::HashMap;
use std::collections::HashSet;
use std::fs::read_to_string;

fn add_gears(i: usize, j: usize, matrix: &Vec<&str>, gears_set: &mut HashSet<(i32, i32)>) {
    let directions = [
        (-1, -1),
        (-1, 0),
        (-1, 1),
        (0, -1),
        (0, 1),
        (1, -1),
        (1, 0),
        (1, 1),
    ];

    for (di, dj) in directions.iter() {
        let new_i = i as i32 + di;
        let new_j = j as i32 + dj;
        if new_i >= 0 && new_i < matrix.len() as i32 && new_j >= 0 && new_j < matrix[0].len() as i32
        {
            let c = matrix[new_i as usize].chars().nth(new_j as usize).unwrap();
            if c == '*' {
                gears_set.insert((new_i, new_j));
            }
        }
    }
}

fn check_and_add_gears(
    line_idx: usize,
    first_idx: usize,
    last_idx: usize,
    matrix: &Vec<&str>,
    gear_map: &mut HashMap<(i32, i32), Vec<i32>>,
) {
    let mut gears_set: HashSet<(i32, i32)> = HashSet::new();
    for idx in first_idx..=last_idx {
        add_gears(line_idx, idx, matrix, &mut gears_set);
    }

    let string_val = matrix[line_idx][first_idx..=(last_idx as usize)]
        .to_string()
        .parse::<i32>()
        .unwrap();
    gears_set
        .iter()
        .for_each(|e| gear_map.entry(*e).or_default().push(string_val));
}

fn is_adjacent_to_symbol(i: usize, j: usize, matrix: &Vec<&str>) -> bool {
    let directions = [
        (-1, -1),
        (-1, 0),
        (-1, 1),
        (0, -1),
        (0, 1),
        (1, -1),
        (1, 0),
        (1, 1),
    ];

    for (di, dj) in directions.iter() {
        let new_i = i as i32 + di;
        let new_j = j as i32 + dj;
        if new_i >= 0 && new_i < matrix.len() as i32 && new_j >= 0 && new_j < matrix[0].len() as i32
        {
            let c = matrix[new_i as usize].chars().nth(new_j as usize).unwrap();
            if !c.is_ascii_digit() && c != '.' {
                return true;
            }
        }
    }
    false
}

fn has_adjacent_symbol(
    line_idx: usize,
    first_idx: usize,
    last_idx: usize,
    matrix: &Vec<&str>,
) -> bool {
    for idx in first_idx..=last_idx {
        if is_adjacent_to_symbol(line_idx, idx, matrix) {
            return true;
        }
    }
    false
}

fn compute_gears_result(gear_map: &mut HashMap<(i32, i32), Vec<i32>>) -> i32 {
    let mut res = 0;
    gear_map.values().filter(|v| v.len() == 2).for_each(|v| {
        res += v[0] * v[1];
    });

    res
}

fn solution_day3a(filename: &str, first_part: bool) -> i32 {
    let mut result = 0;
    let mut matrix: Vec<&str> = Vec::new();
    let file_contents = read_to_string(filename).unwrap();

    let mut gear_map: HashMap<(i32, i32), Vec<i32>> = HashMap::new();

    for line in file_contents.lines() {
        matrix.push(line);
    }

    for (line_idx, line) in matrix.iter().enumerate() {
        let mut first_idx_is_set = false;
        let mut first_idx: usize = 0;

        for (i, c) in line.chars().enumerate() {
            if !first_idx_is_set {
                if c.is_ascii_digit() {
                    first_idx = i;
                    first_idx_is_set = true;
                }
            } else {
                if !c.is_ascii_digit() {
                    first_idx_is_set = false;
                    let last_idx = i as i32 - 1;

                    if has_adjacent_symbol(line_idx, first_idx, last_idx as usize, &matrix) {
                        result += line[first_idx..=(last_idx as usize)]
                            .to_string()
                            .parse::<i32>()
                            .unwrap();
                    }
                    check_and_add_gears(
                        line_idx,
                        first_idx,
                        last_idx as usize,
                        &matrix,
                        &mut gear_map,
                    );
                } else {
                    if i as i32 == line.len() as i32 - 1 {
                        first_idx_is_set = false;
                        let last_idx = i as i32;

                        if has_adjacent_symbol(line_idx, first_idx, last_idx as usize, &matrix) {
                            result += line[first_idx..=(last_idx as usize)]
                                .to_string()
                                .parse::<i32>()
                                .unwrap();
                        }

                        check_and_add_gears(
                            line_idx,
                            first_idx,
                            last_idx as usize,
                            &matrix,
                            &mut gear_map,
                        );
                    }
                }
            }
        }
    }
    let result_b = compute_gears_result(&mut gear_map);

    if first_part {
        return result;
    } else {
        return result_b;
    }
}

fn main() {
    println!("{}", solution_day3a("src/day3_input.txt", true));
    println!("{}", solution_day3a("src/day3_input.txt", false));
}
