def fact(num):
    f = 1
    for i in range(1,num+1):
        f *= i
    return f

def calc(x, n):
    if n < 1:
        return 0
    elif n == 1:
        return 1
    else:
        r = 1
        for i in range(1,n):
            r -= (x**(2*i) / fact(2*i))
        return r

x = float(input("Enter the value of x : "))
n = int(input("Enter the value of n : "))
print("\nCalculating (1 - x^2/2! - x^4/4! - ...... - x^n/n!)")
print("x = ", x, " n = ", n, " : ", calc(x,n))