fn solution_day6a() -> i64 {
    let mut races = vec![(55, 246), (82, 1441), (64, 1012), (90, 1111)];
    let mut result = 1;

    for (time_allowed, distance_to_beat) in races {
        let mut counter = 0;
        for i in 1..time_allowed {
            if (time_allowed - i) * i > distance_to_beat {
                counter += 1;
            }
        }
        result *= counter;
    }

    result
}

fn solution_day6b() -> i64 {
    let a = 55826490.0 as f64;
    let b = 246144110121111.0 as f64;

    // f(x) = (A - x) * x | f(x) > B
    // find x forall x : [1..A-1) | Ax - x^2 > B
    let discriminant = a.powf(2.0) - 4.0 * b;
    let sqrt_discriminant = discriminant.sqrt();
    let right = (a / 2.0 + sqrt_discriminant / 2.0).floor();
    let left = (a / 2.0 - sqrt_discriminant / 2.0).ceil();

    (right - left) + 1 as i64
}

fn main_entry() {
    println!("{}", solution_day6a());
    println!("{}", solution_day6b());
}
