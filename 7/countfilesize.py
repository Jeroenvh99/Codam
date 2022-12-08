# with open("input.txt") as f:
# 	lines = f.readlines()
# totalsize = 0
# recursivedirs = []
# dirsizes = {"dir": 0}
# dirname = "dir"
# dirsize = 0
# for line in lines:
# 	if line.startswith('$ cd'):
# 		if line[5:-1] != '..':
# 			dirsizes.update({dirname: dirsize})
# 			dirsize = 0
# 			dirname = line[5:-1]
# 	try:
# 		dirsize += int(line.split()[0])
# 	except ValueError:
# 		dirsize += 0
# 	if line.startswith('dir'):
# 		try:
# 			dirsize += dirsizes.get(line[4:-1])
# 		except:
# 			if dirname not in recursivedirs:
# 				recursivedirs.append(dirname)
# dirname = "dir"
# complete = 1
# while (len(recursivedirs) > 0):
# 	for line in lines:
# 		if line.startswith('$ cd') and line[5:-1] in recursivedirs:
# 			if line[5:-1] != '..':
# 				dirsize = dirsizes[dirname]
# 				dirsizes.update({dirname: dirsize})
# 				dirname = line[5:-1]
# 		if line.startswith('dir'):
# 			try:
# 				dirsize += dirsizes.get(line[4:-1])
# 			except:
# 				complete = 0
# 			if complete == 1:
# 				if dirname in recursivedirs:
# 					recursivedirs.remove(dirname)
# for size in dirsizes.values():
# 	if size <= 100000:
# 		totalsize += size
# print(totalsize)
with open('input.txt', 'r') as f:
	lines = f.read().splitlines()

cwd = ''
directories = {
	'/': 0
}
for line in lines:
	tokens = line.split()
	if tokens[0] == '$':
		if tokens[1] == 'cd':
			path = tokens[-1]
			if path == '..':
				last_slash_idx = cwd.rfind('/')
				cwd = cwd[:last_slash_idx]
				if not cwd:
					cwd = '/' + cwd
			else:
				if cwd and cwd[-1] != '/':
					cwd += '/'
				cwd += path
	else:
		if tokens[0] == 'dir':
			continue
		size, filename = int(tokens[0]), tokens[1]
		subpath = cwd
		while subpath:
			directories[subpath] = directories.get(subpath, 0) + size
			new_subpath = subpath[:subpath.rfind('/')]
			if subpath != '/' and new_subpath == '':
				subpath = '/'
			else:
				subpath = new_subpath

part_1 = part_2 = 0
for directory, size in directories.items():
	if size <= 100000 and directory != '/':
		part_1 += size
print(f'Part_1: {part_1}')


TOTAL_SPACE, WANTED_UNUSED_SPACE = 70_000_000, 30_000_000
USED_SPACE, UNUSED_SPACE = directories['/'], TOTAL_SPACE - directories['/']
for size in sorted(directories.values()):
	if UNUSED_SPACE + size >= WANTED_UNUSED_SPACE:
		print(f'Part 2: {size}')
		break