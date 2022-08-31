///*
/// 
/// Euclid Algorithm
/// 
///  */

use std::time::{Duration, Instant};

fn main() {
    let mut val1: usize = 18446744073709551615;
    let mut val2: usize = 31415926;

    let instant = Instant::now();

    let value = GCM(val1, val2);

    let duration = instant.elapsed();

    println!("GCD is {}\nTook: {:?}", value, duration);
}

fn GCM(mut val1: usize, mut val2: usize) -> usize {
    if (val2 == 0) {
        return val1;
    }

    let r = val1 % val2;
    val1 = val2;
    val2 = r;
    return GCM(val1, val2);
}