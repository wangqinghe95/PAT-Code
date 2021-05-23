n = int(input())

for i in range(n):
    nums = input().split()
    print("Case #{}: ".format(i+1), end="")

    if int(nums[0]) + int(nums[1]) > int(nums[2]):
        print("true")
    else:
        print("false")
