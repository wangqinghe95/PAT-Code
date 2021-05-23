def isPrime(n, result):
    flag = [1] * (n+2)
    p = 2
    while( p <= n):
        result.append(p)
        for i in range(2*p, n+1, p):
            flag[i] = 0
        while 1:
            p += 1
            if (flag[p] == 1):
                break

str = input().split()
m = int(str[0])
n = int(str[1])

prime = []

isPrime(200000, prime)
result = prime[m-1: n]
if (len(result) == 1):
    print(result[0])
else:
    for i in range(len(result) - 1):
        if (i + 1) % 10 == 0:
            print(result[i])
        else:
            print(result[i], end = " ")
    if (i+2) % 10 == 0:
        print(result[i+1])
    else:
        print(result[i+1], end = "")