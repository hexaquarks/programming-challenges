use std::io::{self};

fn main() {
    let mut first_line = String::new();
    io::stdin().read_line(&mut first_line).unwrap();
    let mut cases = first_line.trim().parse::<u16>().unwrap();
    
    while cases > 0 {
        let mut line_a = String::new();
        io::stdin().read_line(&mut line_a).unwrap();
        let line_a_1 = line_a.as_bytes();

        let mut line_b = String::new();
        io::stdin().read_line(&mut line_b).unwrap();
        let line_b_1 = line_b.as_bytes();
        
        let mut difference = String::new();
        
        for i in 0..line_a.len() - 1 { 
            difference.push(if line_a_1[i] == line_b_1[i] {'.'} else {'*'});
        }
        print!("{line_a}");
        print!("{line_b}");
        print!("{difference}");
        println!();
        cases -= 1;
    }
}