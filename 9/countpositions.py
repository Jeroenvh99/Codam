with open("input.txt") as f:
	lines = f.readlines()

hx, hy, tx, ty = 0, 0, 0, 0

def touching(hx, hy, tx, ty):
	return abs(hx - tx) <= 1 and abs(hy - ty) <= 1

def movehead(direction):
	global hx, hy
	hx += direction[0]
	hy += direction[1]

def movetail(hx, hy):
	global tx, ty
	if hx == tx:
		dx = 0
	else:
		dx = (hx - tx) / abs(hx - tx)
	if hy == ty:
		dy = 0
	else:
		dy = (hy - ty) / abs(hy - ty)
	tx += dx
	ty += dy

moves = {
	'L': [-1, 0],
	'R': [1, 0],
	'U': [0, 1],
	'D': [0, -1]
}

tailpositions = set()
tailpositions.add((tx, ty))
for line in lines:
	line = line.strip('\n')
	instruction, steps = line.split()
	steps = int(steps)
	for _ in range(steps):
		movehead(moves[instruction])
		if not touching(hx, hy, tx, ty):
			movetail(hx, hy)
			tailpositions.add((tx, ty))
print("part one")
print(len(tailpositions))

hx, hy, tx, ty = 0, 0, 0, 0
knotpositions = []
for _ in range(11):
	knotpositions.append([hx, hy])

tailpositions.clear()
tailpositions.add((tx, ty))
for line in lines:
	line = line.strip('\n')
	instruction, steps = line.split()
	steps = int(steps)
	for _ in range(steps):
		movehead(moves[instruction])
		knotpositions[0] = [hx, hy]
		for i in range(10):
			head = knotpositions[i]
			tail = knotpositions[i + 1]
			if not touching(head[0], head[1], tail[0], tail[1]):
				movetail(head[0], head[1])
				knotpositions[i + 1] = [tx, ty]
		tailpositions.add((tuple(knotpositions[-1])))
# print(tailpositions)
print("part two")
print(len(tailpositions))