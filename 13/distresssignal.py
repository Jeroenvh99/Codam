with open('input.txt', 'r') as f:
    lines = f.read().splitlines()

i = 0
for line in lines:
	if line == '\n':
		continue
	else:
		