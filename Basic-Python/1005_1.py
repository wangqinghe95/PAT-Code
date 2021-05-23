if __name__ == "__main__":
      n = int(input())
      num_list = input().split()

      a = set()
      res = []

      for num in num_list:
            num = int(num)
            if num not in a:
                  res.append(num)

                  r = num
                  while r != 1 and r not in a:
                        a.add(int(r))
                        if r % 2 == 1:
                              r = (r * 3 + 1) / 2
                        else:
                              r = r / 2

                  if r in res:
                        res.remove(r)
      res.sort(reverse=1)
      for num in res:
            if num == res[-1]:
                  print(num)
                  break
            print(num, end = " ")

