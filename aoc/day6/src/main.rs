use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {
	let mut totalchance = 1;
	let mut recordings: [i64; 2] = [0; 2];
    if let Ok(lines) = read_lines("/home/jvan-hal/Desktop/Codam/aoc/day6/input.txt") {
		let mut i = 0;
        for line in lines {
			let mut str = line.unwrap();
			str.retain(|c| !c.is_whitespace());
			let start = str.find(':').unwrap();
			let str = &str[start + 1..str.len()];
			println!("{str}");
			recordings[i] = str.parse::<i64>().unwrap();
			i += 1;
        }
    }
	let mut winning = 0;
	let time = recordings[0];
	let best_distance = recordings[1];
	for t in 0..time { 
		let speed = t;
		let distance = speed * (time - t);
		if distance > best_distance {
			winning += 1;
		}
	}
	totalchance *= winning;
	println!("{totalchance}");
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}
