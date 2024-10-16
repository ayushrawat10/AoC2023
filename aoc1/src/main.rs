use std::collections::HashMap;
use std::fs::read_to_string;

fn main() {
    let filename: &str = "input.txt";
    let mut result = 0;
    let mut set: HashMap<String, i64> = HashMap::new();
    set.insert("one".to_string(), 1);
    set.insert("two".to_string(), 2);
    set.insert("three".to_string(), 3);
    set.insert("four".to_string(), 4);
    set.insert("five".to_string(), 5);
    set.insert("six".to_string(), 6);
    set.insert("seven".to_string(), 7);
    set.insert("eight".to_string(), 8);
    set.insert("nine".to_string(), 9);

    for line in read_to_string(filename).unwrap().lines() {
        if let Some(res) = process_line(line, &set) {
            result += res;
        }
    }
    println!("{}", result);
}

fn process_line(input: &str, set: &HashMap<String, i64>) -> Option<i64> {
    let mut first: i64 = 0;
    let mut last: i64 = 0;
    for c in input.chars() {
        if c.is_digit(10) {
            first = 10 * c.to_string().parse::<i64>().unwrap();
            break;
        } else {
            for val in set.keys() {
                let stri = val.chars();
                loop {
                    match stri.next() {
                        c => {

                        }
                    }
                }

            }
        }
    }
    for c in input.chars().rev() {
        if c.is_digit(10) {
            last = c.to_string().parse::<i64>().unwrap();
            break;
        }
    }
    Some(first + last)
}
