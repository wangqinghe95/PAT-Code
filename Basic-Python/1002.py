week = ('ling','yi','er','san','si','wu','liu','qi','ba','jiu')

numbers = input();

len = len(numbers)

sum = 0
for i in range (0,len):
      sum = sum + int(numbers[i])
strnum = str(sum)
print(len(strnum))
print(sum%10)
sum = sum / 10
print(sum)
