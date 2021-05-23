str = input().split()

sum_0 = 0
sum_1 = 0
A1_i = 1
count_2 = 0
sum_3 = 0
count_3 = 0
max_5 = -1
for num in (str):
    temp = int(num)
    if temp % 10 == 0:
        sum_0 = sum_0 + temp
    elif temp % 5 == 1:
        sum_1 = temp * (A1_i) + sum_1
        A1_i = A1_i * (-1)
    elif temp % 5 == 2:
        count_2 += 1
    elif temp % 5 == 3:
        sum_3 = sum_3 + temp
        count_3 += 1
    elif  temp % 5 == 4:
        if temp > max_5:
            max_5 = temp

print("{} {} {} {:.1f} {}".format(sum_0, sum_1, count_2, sum_3/count_3, max_5))

