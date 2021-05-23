
def isPrime(n):
    if n <= 1:
        return False
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

if __name__ == "__main__":
    str = input().split()
    m = int(str[0])
    n = int(str[1])

    prime = []
    num = 2
    prime.append(num)
    while len(prime) <= n:
        flag = 0
        for i in range(len(prime)): 
            if num < prime[i]:
                break
            if num % prime[i] == 0 :
                num += 1
                flag = 1
                break
    """    
        if isPrime(num):
            prime.append(num)
    """
    if flag == 0:
        prime.append(num)

    num = prime[m-1:n]

    while num:
        i = 0
        while len(num) > 1 and i < 9 :
            print(num.pop(0),end = ' ')
            i += 1
        if num:
            print(num.pop(0))


