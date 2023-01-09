with open("input.txt") as f:
	lines = f.read().splitlines()

coordinates = []
outsidesurfacearea = 0
for line in lines:
	splitvalues = line.split(',')
	coordinates.append((int(splitvalues[0]), int(splitvalues[1]), int(splitvalues[2])))

def getnewcoordinate(coordinate, direction):
	return (coordinate[0] + direction[0], coordinate[1] + direction[1], coordinate[2] + direction[2])

surfacearea = 0
tempcoordinate = (-1, -1, -1)
for coordinate in coordinates:
	directions = [[1,0,0],[0,1,0],[0,0,1],[-1,0,0],[0,-1,0],[0,0,-1]]
	for direction in directions:
		tempcoordinate = getnewcoordinate(coordinate, direction)
		if tempcoordinate not in coordinates:
			surfacearea += 1
			outsidesurfacearea += 1
			i = 0
			while tempcoordinate not in coordinates and i < 40:
				tempcoordinate = getnewcoordinate(tempcoordinate, direction)
				if tempcoordinate in coordinates:
					outsidesurfacearea -= 1
					break
				i += 1

print("part one")
print(surfacearea)

print("part two")
print(outsidesurfacearea)