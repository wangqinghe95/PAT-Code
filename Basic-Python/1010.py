str = input().split()

res = []

if str[-1] == '0':
    str_num = len(str) - 2

for i in range(0, str_num):
    if i % 2 == 0:
        res.append(int(str[i]) * int(str[i+1]))
    else:
        res.append(int(str[i]) - 1)

for i in res:
    if i == res[-1]:
        print(i)
    else:
        print(i, end = ' ') 