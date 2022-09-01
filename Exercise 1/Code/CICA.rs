///*
/// 
/// Consecutive integer checking algorithms
/// 
///  */

use std::time::{Duration, Instant};

fn main() {
    let val1: usize = 5243544;
    let mut val2: usize = 4587;

    // Time Start
    let instant = Instant::now();

    let t = CICA(val1, val2);

    let time = instant.elapsed();
    // Time End

    println!("GCD: {}\nTook: {:?}", t, time);
}

fn CICA(val1: usize, val2: usize) -> usize {
    let mut t = if val1 < val2 { val1 } else { val2 };

    let mut remainder = val1 % t;
    let mut nmod = val2 % t;

    while t > 1 {
        if nmod == 0 && remainder == 0 {
            break;
        }
        t = t - 1;
        remainder = val1 % t;
        nmod = val2 % t;
    }

    return t;
}
