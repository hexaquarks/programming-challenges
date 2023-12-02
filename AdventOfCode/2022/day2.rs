use std::io::{self};

fn main() {
    let mut total_part1 = 0;
    let mut total_part2 = 0;
    
    loop {
        let mut input = String::new();
        io::stdin().read_line(&mut input);
        
        let input = input.trim().to_string();
        
        if input.len() == 0 {
            break;
        }
        
        let input = &*input;
        
        let value_part1 = match input {
            "A X" => 4,
            "A Y" => 8, 
            "A Z" => 3, 
            "B X" => 1, 
            "B Y" => 5, 
            "B Z" => 9, 
            "C X" => 7, 
            "C Y" => 2, 
            "C Z" => 6, 
            _ => 0,
        };
        total_part1 += value_part1;
        
        let value_part2 = match input {
            "A X" => 3, 
            "A Y" => 4, 
            "A Z" => 8, 
            "B X" => 1, 
            "B Y" => 5, 
            "B Z" => 9, 
            "C X" => 2, 
            "C Y" => 6, 
            "C Z" => 7, 
            _ => 0,
        };
        total_part2 += value_part2;
    }
    
    println!("total for part 1 and part 2 are: {}, {}", total_part1, total_part2);
}