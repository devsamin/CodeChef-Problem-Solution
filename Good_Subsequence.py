t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    countOdd = sum(1 for x in arr if x % 2 == 1)
    countEven = n - countOdd
    
    if countOdd == countEven:
        print(n)
    else:
        print(2 * min(countOdd, countEven) + 1)
