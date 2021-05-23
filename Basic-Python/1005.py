"""
n = (int)(input())
i = 0
while n != 1:
      if n % 2 == 0:
            n /= 2
      else:
            n = (3 * n + 1) / 2
      i += 1
print(i)
"""
if __name__ == "__main__":
      n = int(input())
      num_list = input().split()

      hashTable = []

      for num in num_list:
            num = int(num)
            while num != 1:
                  if num % 2 == 0:
                        num = num / 2
                  else:
                        num = (num*3+1) / 2
                  hashTable[num] = 1

      hashTable.sort(reverse=1)
      print(hashTable)



