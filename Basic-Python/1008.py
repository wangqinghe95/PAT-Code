"""
test data
6 2
1 2 3 4 5 6
mright =  ['5', '6']
mleft =  ['1', '2', '3', '4']

"""
n = input().split()
m = input().split()

a = int(n[0])
b = int(n[1])

mright = m[a-b:]
mleft = m[:a-b]

res = mright + mleft
#print(res)
#print(' '.join(res)) #将列表的元素以空格隔开的方式输出

for i in (res):
    if (i == res[-1]):
        print(i)
    else:
        print(i, end = ' ')
