# colup, coldown, rowleft, rowright
constraints = [4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2]
visible = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
blocks = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
pos = [0, 0]

def accept(height, pos):
	return height > visible[pos[1] * 4 + pos[0]]

def backtrack(height, pos, filledpos):
	for i in range(0, pos[0]):
		if blocks[pos[1] * 4 + pos[0]] < height:
			visible[pos[1] * 4 + pos[0]] += 1
	for j in range(pos[0], 4):
		if blocks[pos[1] * 4 + pos[0]] < height:
			visible[pos[1] * 4 + pos[0]] += 1
	for k in range(0, pos[1]):
		if blocks[pos[1] * 4 + pos[0]] < height:
			visible[pos[1] * 4 + pos[0]] += 1
	for l in range(pos[1], 0):
		if blocks[pos[1] * 4 + pos[0]] < height:
			visible[pos[1] * 4 + pos[0]] += 1
	if accept(height, pos) is False:
		filledpos -= 1
		if pos[0] < 5 and pos[0] > 0:
			pos[0] -= 1
		if pos[0] == 0:
			pos[1] -= 1
			pos[0] = 4
	if accept(height, pos) is True:
		filledpos += 1
		blocks[pos[1] * 4 + pos[0]] = height
		if (filledpos == 16):
			return
		if pos[0] < 5:
			pos[0] += 1
		if pos[0] == 4:
			pos[1] += 1
			pos[0] = 0
		for m in range(1, 4):
			backtrack(i, pos, filledpos)

filledpos = 0
backtrack(1, pos, filledpos)
print(blocks)