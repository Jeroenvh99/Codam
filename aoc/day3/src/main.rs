use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {
	let mut totalpart = 0;
	let mut schematic: Vec<String> = vec![String::new(); 140];
    if let Ok(lines) = read_lines("/home/jvan-hal/Desktop/Codam/aoc/day3/input.txt") {
		let mut i = 0;
        for line in lines {
			schematic[i] = line.unwrap();
			i += 1;
        }
    }
	let mut y = 0;
	for str in &schematic {
		let mut x = 0;
		let mut part = 0;
		let mut valid = false;
		while x < str.len() {
			if str.chars().nth(x).unwrap().is_numeric() {
				part *= 10;
				part += str.chars().nth(x).unwrap().to_digit(10).unwrap();
				if !valid {
					if x > 0 {
						if y > 0 {
							let topleft = schematic[y - 1].chars().nth(x - 1).unwrap();
							if !topleft.is_numeric() && topleft != '.' && topleft != '\n' {
								println!("{topleft}");
								valid = true;
							}
						}
						let middleleft = schematic[y].chars().nth(x - 1).unwrap();
						if !middleleft.is_numeric() && middleleft != '.' && middleleft != '\n' {
							println!("{middleleft}");
							valid = true;
						}
						if y < 139 {
							let bottomleft = schematic[y + 1].chars().nth(x - 1).unwrap();
							if !bottomleft.is_numeric() && bottomleft != '.' && bottomleft != '\n' {
								println!("{bottomleft}");
								valid = true;
							}
						}
					}
					if y > 0 {
						let topmiddle = schematic[y - 1].chars().nth(x).unwrap();
						if !topmiddle.is_numeric() && topmiddle != '.' && topmiddle != '\n' {
							println!("{topmiddle}");
							valid = true;
						}
					}
					if y < 139 {
						let bottommiddle = schematic[y + 1].chars().nth(x).unwrap();
						if !bottommiddle.is_numeric() && bottommiddle != '.' && bottommiddle != '\n' {
							println!("{bottommiddle}");
							valid = true;
						}
					}
					if x < 139 {
						if y > 0 {
							let topright = schematic[y - 1].chars().nth(x + 1).unwrap();
							if !topright.is_numeric() && topright != '.' && topright != '\n' {
								println!("{topright}");
								valid = true;
							}
						}
						let middleright = schematic[y].chars().nth(x + 1).unwrap();
						if !middleright.is_numeric() && middleright != '.' && middleright != '\n' {
							println!("{middleright}");
							valid = true;
						}
						if y < 139 {
							let bottomright = schematic[y + 1].chars().nth(x + 1).unwrap();
							if !bottomright.is_numeric() && bottomright != '.' && bottomright != '\n' {
								println!("{bottomright}");
								valid = true;
							}
						}
					}
				}
			} else {
				if part > 0 && valid {
					totalpart += part;
				}
				valid = false;
				part = 0;
			}
			x += 1;
		}
		y += 1;
	}
	println!("{totalpart}");
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}
