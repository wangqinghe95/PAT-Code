
def isPrime(n, result):
    flag = [1] * (n + 2)
    p = 2
    while (p <= n):
        result.append(p)
        for i in range(2 * p, n+1, p):
            flag[i] = 0
            
        while 1:
                p += 1
                if (flag[p] == 1):
                    break

n = int(input())

result = []
isPrime(n, result)

num = 0
for i in range(len(result) - 1):
    if (result[i+1] - result[i] == 2):
        num += 1
print(num)



