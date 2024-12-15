def rev(s : str):
    s1 = ""
    for i in s:
        s1 = i + s1
    return s1

a = input("\nEnter the string : ")
print("\nReverse of %s : %s"%(a,rev(a)))