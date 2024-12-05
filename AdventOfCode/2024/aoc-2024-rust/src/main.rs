use std::env;

mod day1;
mod day2;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        println!("Usage: cargo run [day] [part]");
        return;
    }

    let day = &args[1];
    let part = if args.len() > 2 { &args[2] } else { "a" };

    match day.as_str() {
        "1" => day1::run(part),
        "2" => day2::run(part),
        // Add more days here
        _ => println!("Invalid day: {}", day),
    }
}
