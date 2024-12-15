# a) 1 - x^2/2! + x^4/4! - x^6/6! + .... + x^n/n!
# b) 1 + x^2/2! + x^4/4! + x^6/6! + .... + x^n/n!
import math as m
def series(x:int,n:int):
    if n < 1:
        return
    sum1 = 0
    sum2 = 0
    for i in range(n):
        term = m.pow(x,2*i)/m.factorial(2*i)
        sum2 += term
        if i % 2: sum1 -= term
        else: sum1 += term
    return sum1,sum2

x = int(input("Enter the value of x : ")) 
n = int(input("Enter the value of n : "))
print("Series : \n 1) 1 - x^2/2! + x^4/4! - x^6/6! + .... + x^n/n! \n 2) 1 + x^2/2! + x^4/4! + x^6/6! + .... + x^n/n!")
print("Sum of the series (sum1, sum2) with x = %s & n = %s : %s"%(x,n,series(x,n)))