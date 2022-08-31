fn main() {
    findPrimeNumbersInRange(100);
}

fn findPrimeNumbersInRange(end: usize) {
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

    possible_primes.retain(|x| *x != 0); // Clean 0 out of vector

    println!("{:?}", possible_primes);
}