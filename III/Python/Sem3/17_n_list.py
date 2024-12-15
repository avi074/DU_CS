n = int(input("\nEnter the number of lists : "))
l = [[i*j for j in range(1,6)]for i in range(1,n+1)]

print("\nList SN : List elements\n")
for i in range(n):
    print("  %s\t: %s "%(i+1, l[i]))