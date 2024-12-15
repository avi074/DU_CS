def palindrome(st:str):
    return st == st[::-1]

'''def palindrome(str:str):
    c = len(str) -1
    for i in range(int(c/2)):
        b = a[i] is a[c-i]
        if ~b:
            break 
    return b'''

a = input("\nEnter the string : ")
if palindrome(a): 
    print("\n " + a + " is a palindrome !!!")
else:
    print("\n " + a + " is not a palindrome !!!")