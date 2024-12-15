s = input("\nEnter your sentence : ")
d = dict()

def count(c):
    n = 0
    for i in s:
        if i is c:
            n += 1
    return n

for i in s:
    d.__setitem__(i,count(i))

print("\nLetters with their frequencies are : ")
for i in d.items():
    print(i)
