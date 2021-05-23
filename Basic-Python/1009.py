str = input().split()
str.reverse()

for list in str:
    if list == str[-1]:
        print(list)
    else:
        print(list, end = ' ')