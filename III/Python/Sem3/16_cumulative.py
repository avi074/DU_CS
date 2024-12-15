def cum(l:list):
    l1 = [0]*len(l)
    for i in range(len(l)):
        for j in range(i,-1,-1):
            l1[i] += l[j] 
    return l1

'''n = int(input("\n How many numbers do you want to enter : "))
a = []
print()
if n > 0:
    for i in range(n):
        a.append(int(input("Enter "+str(i+1)+ " element : ")))'''
a = list(eval(input("Enter the numbers (use comma to seperate) : ")))
print("\nEntered list : %s \n\nYour cumulative list : %s"%(a,cum(a)))