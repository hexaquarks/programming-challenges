use std::fs::read_to_string;

fn generate_composite_cases(numbers_and_digits: Vec<(&str, &str)>) -> Vec<(String, String)> {
    let mut composite_numbers_and_digits = Vec::new();

    // Generate composite cases
    for (word1, digit1) in numbers_and_digits.iter() {
        for (word2, digit2) in numbers_and_digits.iter() {
            if *word1 == *word2 {
                continue;
            }
            if word1.chars().last() == word2.chars().next() {
                let new_str = format!("{}{}", &word1[0..word1.len()], &word2[1..word2.len()]);
                let new_digit = format!("{}{}", digit1, digit2);
                composite_numbers_and_digits.push((new_str, new_digit));
            }
        }
    }

     let numbers_and_digits_as_string: Vec<(String, String)> = numbers_and_digits
        .iter()
        .map(|&(word, digit)| (word.to_string(), digit.to_string()))
        .collect();

    composite_numbers_and_digits.extend(numbers_and_digits_as_string);
    composite_numbers_and_digits
}

fn check_word_digit(line: &str) -> String {
    let numbers_and_digits = vec![
        ("one", "1"),
        ("two", "2"),
        ("three", "3"),
        ("four", "4"),
        ("five", "5"),
        ("six", "6"),
        ("seven", "7"),
        ("eight", "8"),
        ("nine", "9"),
    ];

    // Prepend composite numbers cases to the standard numbers/digits pairs.
    let composite_numbers_and_digits = generate_composite_cases(numbers_and_digits);

    let mut res = line.to_string();
    for (word, digit) in composite_numbers_and_digits.into_iter() {
        res = res.replace(&word, &digit);
    }
    res
}

fn solution_day1b(filename: &str) -> i32 {
    let mut result = 0;

    for line in read_to_string(filename).unwrap().lines() {
        let formatted_line = check_word_digit(line);
        
        let first = formatted_line.chars().find(|&c| c.is_ascii_digit()).unwrap_or('0');
        let second  = formatted_line.chars().rev().find(|&c| c.is_ascii_digit()).unwrap_or('0');
        
        result += (first as i32 - '0' as i32) * 10 + (second as i32 - '0' as i32);
    }

    result
}

fn solution_day1a(filename: &str) -> i32 {
    let mut result = 0;

    for line in read_to_string(filename).unwrap().lines() {
        let first = line.chars().find(|&c| c.is_ascii_digit()).unwrap_or('0');
        let second  = line.chars().rev().find(|&c| c.is_ascii_digit()).unwrap_or('0');
        
        result += (first as i32 - '0' as i32) * 10 + (second as i32 - '0' as i32);
    }

    result
}

fn main_entry() {
    println!("{}", solution_day1a("src/day1_input.txt"));
    println!("{}", solution_day1b("src/day1_input.txt"));
}
