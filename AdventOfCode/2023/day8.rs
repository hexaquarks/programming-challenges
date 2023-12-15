fn solution_day8a(filename: &str) -> i32 {
    let file_contents = read_to_string(filename).unwrap();

    let sections: Vec<&str> = file_contents.split("\n\n").collect();

    let instructions = sections[0].lines().nth(0).unwrap();

    let mut paths: HashMap<String, (String, String)> = HashMap::new();
    let mut next_node: String = String::from("AAA");

    for line in sections[1].lines() {
        let (key, val) = line.split_once(" = ").unwrap();

        let val_filtered = val
            .chars()
            .filter(|c| *c != ')' && *c != '(')
            .collect::<String>();

        let (val1, val2) = val_filtered.split_once(", ").unwrap();

        *paths.entry(key.to_string()).or_default() = (val1.to_string(), val2.to_string());
    }

    let mut steps = 0;
    let mut found_zzz = false;

    while !found_zzz {
        for c in instructions.chars() {
            match c {
                'L' => {
                    next_node = paths.entry(next_node).or_default().0.clone();
                }
                'R' => {
                    next_node = paths.entry(next_node).or_default().1.clone();
                }
                _ => panic!(),
            }
            steps += 1;
            if next_node == "ZZZ" {
                found_zzz = true;
                break;
            }
        }
    }
    steps
}

fn solution_day8b(filename: &str) -> i64 {
    let file_contents = read_to_string(filename).unwrap();

    let sections: Vec<&str> = file_contents.split("\n\n").collect();

    let instructions = sections[0].lines().nth(0).unwrap();

    let mut paths: HashMap<String, (String, String)> = HashMap::new();
    let mut begins: HashSet<String> = HashSet::new();

    for line in sections[1].lines() {
        let (key, val) = line.split_once(" = ").unwrap();

        let val_filtered = val
            .chars()
            .filter(|c| *c != ')' && *c != '(')
            .collect::<String>();

        let (val1, val2) = val_filtered.split_once(", ").unwrap();

        *paths.entry(key.to_string()).or_default() = (val1.to_string(), val2.to_string());

        // Add to begins
        if key.chars().nth(2).unwrap() == 'A' {
            begins.insert(key.to_string());
        }
    }

    let mut lengths: Vec<i64> = Vec::new();

    for instruction in begins.iter() {
        let mut steps = 0;
        let mut found_z = false;
        let mut next_node: String = instruction.clone();

        while !found_z {
            for c in instructions.chars() {
                match c {
                    'L' => {
                        next_node = paths.entry(next_node).or_default().0.clone();
                    }
                    'R' => {
                        next_node = paths.entry(next_node).or_default().1.clone();
                    }
                    _ => panic!(),
                }
                steps += 1;
                if next_node.chars().nth(2).unwrap() == 'Z' {
                    found_z = true;
                    break;
                }
            }
        }

        lengths.push(steps);
    }

    // find LCM between all paths
    fn gcd(a: i64, b: i64) -> i64 {
        if b == 0 {
            a.abs()
        } else {
            gcd(b, a % b)
        }
    }

    fn lcm(a: i64, b: i64) -> i64 {
        a.abs() / gcd(a, b) * b.abs()
    }

    fn lcm_of_vector(values: &[i64]) -> i64 {
        values.iter().fold(1, |acc, &num| lcm(acc, num))
    }

    lcm_of_vector(&lengths)
}

fn main_entry() {
    println!("{}", solution_day8a("src/day8_input.txt"));
    println!("{}", solution_day8b("src/day8_input.txt"));
}
