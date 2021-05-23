n = int(input())

max_score = 0
min_score = 101
for i in range(n):
      s = input()
      str = s.split()
      if int(str[2]) > max_score:
            max_score = int(str[2])
            max_res = str[0] + " " + str[1]
      if (int(str[2]) < min_score):
            min_score = int(str[2])
            min_res = str[0] + " " + str[1]

print(max_res)
print(min_res)
      
"""
测试数据：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

s = input()
str = s.split()
输入 Mary EE990830 95时
str[0] = Mary
str[1] = EE990830
str[2] = 95时
"""
