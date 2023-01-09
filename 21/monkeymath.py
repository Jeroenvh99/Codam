with open("input.txt") as f:
	lines = f.read().splitlines()

monkeys = {}
rootoperands = []
while len(monkeys) < len(lines):
	for line in lines:
		instructions = line.split(': ')
		name = instructions[0]
		instruction = instructions[1]
		try:
			monkeys.update({name: int(instruction)})
		except:
			operation = instructions[1].split()
			leftoperand = operation[0]
			rightoperand = operation[2]
			if leftoperand in monkeys and rightoperand in monkeys:
				operator = operation[1]
				leftoperand = monkeys[leftoperand]
				rightoperand = monkeys[rightoperand]
				if name == "root":
					rootoperands = [leftoperand, rightoperand]
				if operator == '+':
					monkeys.update({name: leftoperand + rightoperand})
				elif operator == '-':
					monkeys.update({name: leftoperand - rightoperand})
				elif operator == '*':
					monkeys.update({name: leftoperand * rightoperand})
				elif operator == '/':
					monkeys.update({name: leftoperand / rightoperand})
print("part one")
print(monkeys["root"])

prevvalue = 52282191702834
prevname = "root"
	for line in lines:
		instructions = line.split(': ')
		name = instructions[0]
		instruction = instructions[1]
		if name in monkeys:
			operation = instructions[1].split()
			if len(operation) == 3:
				leftoperand = operation[0]
				rightoperand = operation[2]
				if leftoperand == prevname or rightoperand == prevname:
					operator = operation[1]
					prevname = name
					if leftoperand == prevname:
						leftoperand = prevvalue
						rightoperand = monkeys[rightoperand]
						if operator == '+':
							prevvalue = rightoperand - leftoperand
						elif operator == '-':
							prevvalue = rightoperand + leftoperand
						elif operator == '*':
							prevvalue = rightoperand / leftoperand
						elif operator == '/':
							prevvalue = rightoperand * leftoperand
					else:
						leftoperand = monkeys[leftoperand]
						rightoperand = prevvalue
						if operator == '+':
							prevvalue = leftoperand - leftoperand
						elif operator == '-':
							prevvalue = leftoperand + rightoperand
						elif operator == '*':
							prevvalue = leftoperand / rightoperand
						elif operator == '/':
							prevvalue = leftoperand * rightoperand
				monkeys.pop(name)
print("part two")
print(prevname)