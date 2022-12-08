with open('input.txt') as f:
    lines = f.readlines()
ans = []
lst = []
temp = 0
for i in lines:
    i = i.strip('\n')
    if i != '':
        temp += int(i)
        lst.append(i)
    if i == '':
        ans.append(temp)
        print(lst)
        temp = 0
print("part 1 answer:")
print(max(ans))
print("part 2 answer:")
temp = 0
temp += max(ans)
ans.remove(max(ans))
temp += max(ans)
ans.remove(max(ans))
temp += max(ans)
print(temp)