def linearSearch(l, key):
    for i in l:
        if i == key:
            return True
    return False

def binarySearch(l, key):
    i = 0
    n = len(l) - 1

    while i <= n:
        mid = (i + n)//2

        if l[mid] == key: return True
        elif l[mid] < key: i = mid + 1
        else: n = mid - 1
    return False

items = [1,2,3,4,5,6,7,8,9,10]
print("\nList = %s"%(items))
print("\nLinear Search (List, 3)  : %s"%(linearSearch(items, 3)))
print("\nLinear Search (List, 13) : %s"%(linearSearch(items, 13)))
print("\nBinary Search (List, 5)  : %s"%(binarySearch(items, 5)))
print("\nBinary Search (List, 17) : %s"%(binarySearch(items, 17)))