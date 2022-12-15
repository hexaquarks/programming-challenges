while True:
    n = int(input())
    if n == 0: break
    n -= 1
    values = list(bin(n)[2:])
    values.reverse()
    
    nums = []
    powerOfThree = 1
    
    for i,value in enumerate(values):
        if value == "1": nums.append(str(3 ** i))
    
    print("{ " + ", ".join(nums) + " }")