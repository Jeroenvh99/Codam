f = open("input.txt").read()
startnumber = 0
i = 3
inlen = len(f)
while i < inlen:
	marker = {f[i]}
	j = 1
	while j < 4:
		marker.add(f[i - j])
		if len(marker) < j + 1:
			i += 1
			break
		else:
			j += 1
	if j == 4:
		startnumber = i + 1
		break
print('part one')
print(startnumber)

f = open("input.txt").read()
startnumber = 0
i = 12
inlen = len(f)
while i < inlen:
	marker = {f[i]}
	j = 1
	while j < 14:
		marker.add(f[i - j])
		if len(marker) < j + 1:
			i += 1
			break
		else:
			j += 1
	if j == 14:
		startnumber = i + 1
		break
print('part two')
print(startnumber)