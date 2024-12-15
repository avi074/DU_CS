def LCM_HCF(a:int,b:int):
    if a < 0 or b < 0:
        return

    if a < b:
        a,b = b,a

    def LCM():
        if a == 0 or b == 0:
            return 0
        elif b == 1 or a % b == 0:
            return a
        else:
            for i in range(1,b+1):
                if (a*i) % b == 0:
                    c = a*i
            return c
    
    def HCF():
        if b == 0:
            return a
        elif a % b == 0:
            return b
        else:
            return a * b // LCM() 

    return LCM(),HCF()

a = int(input("Enter the first number : "))
b = int(input("Enter the second number : "))
print("(LCM, HCF) of (%s,%s) : %s"%(a,b,LCM_HCF(a,b)))