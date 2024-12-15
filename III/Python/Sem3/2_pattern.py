def Diamond(n:int,start = 0,step = 1):
    for i in range(start,n,step):
        if i > n: 
            c = start - i
        else: 
            c = n - i
        for k in range(c):    
            print(' ',end="")
        for j in  range(2*i-1): 
            print('*',end="")
        print()
        if i == n-1:
            Diamond(-1,n,-1)

def Num_pattrn(n:int):
    for i in range(n):
        for m in range(n-i):
            print(' ',end="")
        for j in range(i+1):
            print((i+j+1)%10,end="")
        for k in range(2*i,i,-1):
            print(k%10,end="")
        print()

n = int(input("Enter the number of rows : "))
print("\nDiamond Pattern : ")
Diamond(n)
print("\nNumber Pattern : \n")
Num_pattrn(n)