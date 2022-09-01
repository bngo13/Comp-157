///*
///
/// Middle School Method
///
///*

use std::time::{Duration, Instant};

fn main() {
    let val1: usize = 8;
    let val2: usize = 5;

    let instant = Instant::now();

    let primeNum1 = findPrimeNumbersInRange(val1);
    let primeNum2 = findPrimeNumbersInRange(val2);
    let gcd = findGCD(primeNum1, primeNum2);

    let interval = instant.elapsed();

    println!("GCD: {}\nTook: {:?}", gcd, interval);
}

fn findPrimeNumbersInRange(end: usize) -> Vec<usize> {
    let mut possible_primes: Vec<usize> = Vec::new(); // Contains all possible primes
    let mut replacement_indexes: Vec<usize> = Vec::new();

    let mut primes: Vec<usize> = Vec::new(); // Contains primes

    for i in 2..end + 1 {
        possible_primes.push(i); // Generate the Array
    }

    for possible_prime in possible_primes.clone() {
        /* Load all unprimes into replacement indexes for removal */
        if (possible_prime) * (possible_prime) > end || possible_prime == 0 {
            break;
        }

        for i in 2..end {
            let mut tempnum = possible_prime * i;
            if tempnum > end {
                break;
            }

            replacement_indexes.push(tempnum - 2);
        }
    }

    for replace in replacement_indexes {
        // Replace all non prime with 0
        std::mem::replace(&mut possible_primes[replace], 0);
    }

    possible_primes.insert(0, 1);

    for test in &mut possible_primes {
        if *test == 0 {
            continue;
        }

        if end % *test != 0 {
            *test = 0;
        }
    }

    possible_primes.retain(|x| *x != 0); // Clean 0 out of vector

    return possible_primes;
}

fn findGCD(vec1: Vec<usize>, vec2: Vec<usize>) -> usize {
    let mut sum = 1;
    for i in &vec1 {
        for j in &vec2 {
            if i == j {
                sum = sum * i;
            }
        }
    }
    return sum;
}
