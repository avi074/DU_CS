def count(s:str,s1:str):
    c = 0
    for i in range(len(s)):
        if s[i] in s1:
            c += 1
    return c

a = input("\nEnter first string : ")
b = input("\nEnter second string : ")
print("\nTotal matching characters in %s & %s : %d"%(a,b,count(a,b)))