def fibonacci(n:int):
    f1 = 0
    f2 = 1
    if n == 1:
        return f1
    elif n == 2:
        return f2
    else:
        for i in range(2,n):
            f3 = f1 + f2
            f1 = f2
            f2 = f3
        return f3

a = int(input('Enter the value of n : '))
print(a,'term of Fibonacci series :',fibonacci(a))