
str = input()
len_str = len(str)
for i in str:
      num = int(i)
      #print("num = %d"%(num))
      #print("lens_str = %d"%(len_str))
      for j in range(1,num+1):
            #print("j = %d"%(j))
            if 3 == len_str:
                  print("B", end = "")
            elif 2 == len_str:
                  print("S", end = "")
            elif 1 == len_str:
                  print(j, end = ""
                        )
      len_str = len_str - 1


