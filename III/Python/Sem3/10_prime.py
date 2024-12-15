def is_prime(a:int):
    prime = False
    if a == 2:
        prime = True
    elif a % 2 == 1:
        c = 0
        for i in range(3,a//2 + 1,2):
            if a % i == 0:
                c += 1
        if c == 0:
            prime = True

    if prime:
        print("%s is a prime number !!!"%a)
    else:
        print("%s is not a prime number !!!"%a)

n = int(input("Enter the number : "))
is_prime(n)