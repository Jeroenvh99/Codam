with open("input.txt") as f:
	lines = f.readlines()
visibletrees = 0
width = len(lines[0]) - 1
i = 0
while i < width:
	j = 0
	while j < width:
		treesize = lines[i][j]
		lvisible = 1
		rvisible = 1
		uvisible = 1
		dvisible = 1
		l = j - 1
		while l > -1:
			if lines[i][l] >= treesize:
				lvisible = 0
				break
			l -= 1
		r = j + 1
		while r < width:
			if lines[i][r] >= treesize:
				rvisible = 0
				break
			r += 1
		u = i - 1
		while u > -1:
			if lines[u][j] >= treesize:
				uvisible = 0
				break
			u -= 1
		d = i + 1
		while d < width:
			if lines[d][j] >= treesize:
				dvisible = 0
				break
			d += 1
		if lvisible or rvisible or uvisible or dvisible:
			visibletrees += 1
		j += 1
	i += 1
print("part one")
print(visibletrees)

with open("input.txt") as f:
	lines = f.readlines()
maxscenic = 0
width = len(lines[0]) - 1
i = 0
while i < width:
	j = 0
	while j < width:
		treesize = lines[i][j]
		lvisible = 0
		rvisible = 0
		uvisible = 0
		dvisible = 0
		l = j - 1
		while l > -1:
			lvisible += 1
			if lines[i][l] >= treesize:
				break
			l -= 1
		r = j + 1
		while r < width:
			rvisible += 1
			if lines[i][r] >= treesize:
				break
			r += 1
		u = i - 1
		while u > -1:
			uvisible += 1
			if lines[u][j] >= treesize:
				break
			u -= 1
		d = i + 1
		while d < width:
			dvisible += 1
			if lines[d][j] >= treesize:
				break
			d += 1
		scenicscore = lvisible * rvisible * uvisible * dvisible
		if scenicscore > maxscenic:
			maxscenic = scenicscore
		j += 1
	i += 1
print("part two")
print(maxscenic)