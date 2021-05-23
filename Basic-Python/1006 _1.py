
num = int(input())
B = num // 100
S = num % 100 // 10
N = num % 10


print("B"*B, end = "")
print("S"*S, end = "")
for i in range(N):
      print(i+1, end = "")
