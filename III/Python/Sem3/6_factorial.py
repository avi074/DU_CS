def factorial(n:int):
    fact = 1
    while n > 1:
        fact *= n
        n = n-1 
    return fact

a = int(input('Enter the number : '))
print("Factorial of ",a,':',factorial(a))