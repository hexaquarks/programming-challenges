fn value_to_card(x: u8) -> char {
    match x {
        2..=10 => (x + b'0') as char,
        11 => 'J',
        12 => 'Q',
        13 => 'K',
        14 => 'A',
        _ => unreachable!(),
    }
}

fn card_to_value(card: char) -> u8 {
    match card {
        'A' => 14,
        'K' => 13,
        'Q' => 12,
        'J' => 11,
        'T' => 10,
        '2'..='9' => card as u8 - b'0',
        _ => 0,
    }
}

fn compute_multiples(card: &String, num: usize) -> Option<(String, u8)> {
    let mut multiples: Vec<(char, usize)> = Vec::new();

    (2..=14).for_each(|x| {
        let c = value_to_card(x as u8);
        multiples.push((c, num));
    });
    for multiple in multiples.iter() {
        if card.chars().filter(|c| c == &(multiple.0)).count() == multiple.1 {
            let remainder: String = card
                .to_string()
                .chars()
                .filter(|c| c != &multiple.0)
                .collect();
            return Some((remainder, card_to_value(multiple.0)));
        }
    }
    None
}

fn card_strength(card: &str) -> (usize, String, u8) {
    let card_str: String = card.to_string();

    // five of a kind
    match compute_multiples(&card_str, 5) {
        Some((remainder, value)) => {
            return (7 as usize, remainder, value);
        }
        None => {}
    };

    // four of a kind
    match compute_multiples(&card_str, 4) {
        Some((remainder, value)) => {
            return (6 as usize, remainder, value);
        }
        None => {}
    };

    // full house / three of a kind
    match compute_multiples(&card_str, 3) {
        Some((remainder, value)) => {
            let first = remainder.chars().nth(0).unwrap();
            if remainder.chars().all(|c| c == first) {
                // full house
                return (5 as usize, remainder, value);
            } else {
                // three of a kind
                return (4 as usize, remainder, value);
            }
        }
        None => {}
    };

    // Two pair / single pair
    match compute_multiples(&card_str, 2) {
        Some((remainder, value)) => {
            match compute_multiples(&remainder, 2) {
                Some((remainder_of_remainder, value_of_value)) => {
                    // two pairs
                    return (3 as usize, remainder_of_remainder, value_of_value);
                }
                None => {
                    // one pair
                    return (2 as usize, remainder, value);
                }
            };
        }
        None => {}
    };

    // High card
    let _high_vard_value = highest_card_value(&card_str);
    let high_card = value_to_card(_high_vard_value);
    let high_card_remainder = card_str.chars().filter(|c| c != &high_card).collect();

    (1 as usize, high_card_remainder, _high_vard_value)
}

fn solution_day7a(filename: &str) -> i32 {
    let mut result = 0;
    let file_contents = read_to_string(filename).unwrap();

    let mut hands_map: HashMap<usize, Vec<(String, u8, i32)>> = HashMap::new();
    for line in file_contents.lines() {
        let [card, bid]: [&str; 2] = line
            .split_whitespace()
            .collect::<Vec<&str>>()
            .try_into()
            .expect("ignore");

        let (inner_strength, remainder, key_value) = card_strength(card);
        hands_map.entry(inner_strength).or_default().push((
            remainder,
            key_value,
            bid.to_string().parse::<i32>().unwrap(),
        ));
    }

    // sort the hands at each type
    for hands_same_type in hands_map.values_mut() {
        hands_same_type.par_sort_by(
            |(remainder_1, key_val_1, bid_1), (remainder_2, key_val_2, bid_2)| {
                if key_val_1 == key_val_2 {
                    let mut highest_1 = highest_card_value(remainder_1);
                    let mut highest_2 = highest_card_value(remainder_2);
                    while highest_1 == highest_2 {
                        highest_1 = highest_card_value(
                            &remainder_1
                                .chars()
                                .filter(|c| c != &value_to_card(highest_1))
                                .collect(),
                        );
                        highest_2 = highest_card_value(
                            &remainder_2
                                .chars()
                                .filter(|c| c != &value_to_card(highest_2))
                                .collect(),
                        );
                    }
                    if highest_1 > highest_2 {
                        std::cmp::Ordering::Less
                    } else {
                        std::cmp::Ordering::Greater
                    }
                } else if key_val_1 > key_val_2 {
                    std::cmp::Ordering::Less
                } else {
                    std::cmp::Ordering::Greater
                }
            },
        );
        println!("Sorted hand");
    }

    let mut counter = 1;
    for hands_same_type in hands_map.into_values() {
        for (_, _, bid) in hands_same_type.iter() {
            result += counter * bid;
            counter += 1;
        }
    }

    result
}

fn main_entry() {
    println!("{}", solution_day7a("src/day7_input.txt"));
}
