with open("input.txt") as f:
	lines = f.readlines()
score = 0
for line in lines:
	line = line.strip('\n')
	if line[-1] == 'X':
		score += 1
		if line[0] == 'C':
			score += 6
	elif line[-1] == 'Y':
		score += 2
		if line[0] == 'A':
			score += 6
	elif line[-1] == 'Z':
		score += 3
		if line[0] == 'B':
			score += 6
	if ord(line[0]) == ord(line[-1]) - 23:
		score += 3
print('part one')
print(score)

with open("input.txt") as f:
	lines = f.readlines()
score = 0
for line in lines:
	line = line.strip('\n')
	if line[-1] == 'X':
		if line[0] == 'A':
			score += 3
		if line[0] == 'B':
			score += 1
		if line[0] == 'C':
			score += 2
	elif line[-1] == 'Y':
		score += 3
		score += ord(line[0]) - 64
	elif line[-1] == 'Z':
		score += 6
		if line[0] == 'A':
			score += 2
		if line[0] == 'B':
			score += 3
		if line[0] == 'C':
			score += 1
print('part two')
print(score)