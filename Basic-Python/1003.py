import re
n = input()

for i in range(int(n)):
      str = input()
      if re.match(r'A*PA+TA*',str):
            a = re.split(r'[P|T]',str)
            print("a[0] = %s, a[1] = %s, a[2] = %s"%(a[0],a[1],a[2]))
            if (a[0] * len(a[1]) == a[2]):
                  print("YES")
            else:
                  print("NO")
      else:
            print("NO")
