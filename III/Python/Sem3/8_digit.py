def func(a:int):
    rev = 0
    sum = 0
   
    while a:
        sum += a%10 
        rev = rev*10 + a%10
        a = a//10 # '/' generate double & '//' generate int
    return sum, rev

a = int(input("Enter a number : "))
sum, rev = func(a)
print("You entered : ",a)
print("Sum of digits of %s : %s"%(a,sum))
print("Reverse of %s : %s"%(a,rev))