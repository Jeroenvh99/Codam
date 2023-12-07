use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {
	let mut total = 0;
    let numeric = ['1', '2', '3', '4', '5', '6', '7', '8', '9'];
	let numbers = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
    if let Ok(lines) = read_lines("/home/jvan-hal/Desktop/Codam/aoc/day1/input.txt") {
        for line in lines {
            let mut str = line.unwrap();
			for i in 0..6 {
				for num in numbers {
					let index = str.find(num);
					match index {
						None => {},
						Some(begin) => {
							match num {
								"one" => {str.replace_range(begin + 1..begin + num.len() - 2, "1");},
								"two" => {str.replace_range(begin + 1..begin + num.len() - 2, "2");},
								"three" => {str.replace_range(begin + 1..begin + num.len() - 2, "3");},
								"four" => {str.replace_range(begin..begin + num.len(), "4");},
								"five" => {str.replace_range(begin..begin + num.len() - 1, "5");},
								"six" => {str.replace_range(begin..begin + num.len(), "6");},
								"seven" => {str.replace_range(begin..begin + num.len() - 1, "7");},
								"eight" => {str.replace_range(begin + 1..begin + num.len() - 2, "8");},
								"nine" => {str.replace_range(begin + 1..begin + num.len() - 2, "9");},
								_ => {}
							}
						}
					}
				}
			}
			let start = str.chars().position(|c| numeric.contains(&c)).unwrap();
            let strrev: String = str.chars().rev().collect();
            let stop = strrev.chars().position(|c| numeric.contains(&c)).unwrap();
			let mut res = String::new();
			res.push(str.chars().nth(start).unwrap());
			res.push(str.chars().nth(str.len() - 1 - stop).unwrap());
			println!("{str} {res} {start} {}", str.len() - 1 - stop);
            total += res.parse::<i32>().unwrap();
        }
    }
	println!("{total}");
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}
