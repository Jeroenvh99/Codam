with open('input.txt', 'r') as f:
    lines = f.read().splitlines()

xcovered = [4000001]

for line in lines:
	parts = line.split()
	sx = int(parts[2][2:-1])
	sy = int(parts[3][2:-1])
	bx = int(parts[8][2:-1])
	by = int(parts[9][2:])
	mandist = abs(bx - sx) + abs(by - sy)
	for y in range(4000001):
		width = mandist - y
		if width > 0:
			minx = sx - width
			if minx < 0:
				minx = 0
			maxx = sx + width
			if maxx > 4000000:
				maxx = 4000000
			xcovered[y].append([minx, maxx])
print(xcovered)
# for covered in xcovered:
# 	possible = []
# 	for i in range(4000001):
# 		for comb in covered:
# 			if i >= comb[0] and i <= comb[1]:
# 				continue
# 			possible.append(i)
# 	print(possible)