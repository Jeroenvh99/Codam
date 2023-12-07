use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {
	let mut totalpower = 0;
	let mut red = 0;
	let mut green = 0;
	let mut blue = 0;
    if let Ok(lines) = read_lines("/home/jvan-hal/Desktop/Codam/aoc/day2/input.txt") {
        'lines: for line in lines {
			let str = line.unwrap();
			let begin = str.find(':').unwrap();
			let games = &str[begin + 2..str.len()];
			for substr in games.split(';') {
				for sub in substr.split(',') {
					let mut color = sub.find("green");
					match color {
						None => {},
						Some(which) => {
							let curgreen = sub[0..which - 1].trim().parse::<i32>().unwrap();
							if curgreen > green {
								green = curgreen;
							}
						}
					}
					color = sub.find("red");
					match color {
						None => {},
						Some(which) => {
							let curred = sub[0..which - 1].trim().parse::<i32>().unwrap();
							if curred > red {
								red = curred;
							}
						}
					}
					color = sub.find("blue");
					match color {
						None => {},
						Some(which) => {
							let curblue = sub[0..which - 1].trim().parse::<i32>().unwrap();
							if curblue > blue {
								blue = curblue;
							}
						}
					}
				}
			}
			let power = red * green * blue;
			println!("{red} {green} {blue} {power}");
			totalpower += power;
			red = 0;
			green = 0;
			blue = 0;
        }
    }
	println!("{totalpower}");
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}
