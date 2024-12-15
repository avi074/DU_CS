def pattern(n:int):
    if n % 2:
        c = 1
        for j in range(1,n,2):
            c += 1
        for i in range(n):
            if c > i:
                for s in range(i % c):
                    print(end="  ")
                for j in range(c - i, 1, -1):
                    print(j % 10, end=" ")
                for k in range(1, c- i + 1):
                    print(k % 10, end=" ")
            else:
                for s in range(c - (i % c) - 2):
                    print(end="  ")
                for j in range(i - c + 2, 1, -1):
                    print(j % 10, end=" ")
                for k in range(1, i - c + 3):
                    print(k % 10, end=" ")
            print()
    else:
        print("Number of lines must be odd !!!")

n = int(input("No. of lines for pattern : "))
pattern(n)