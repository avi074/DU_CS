def less(a, b):
    return a < b 

def greater(a, b):
    return a > b 

def bubbleSort(l:list, cmp = less):
    for i in range(len(l) - 1):
        for j in range(i+1,len(l)):
            if cmp(l[j], l[i]) : 
                l[i], l[j] = l[j], l[i]
    return l

def insertionSort(l:list, cmp = less):
    for i in range(1,len(l)):
        tmp = l[i]
        j = i - 1
        while j >= 0 and cmp(tmp, l[j]):
            l[j+1] = l[j]
            j -= 1
        l[j + 1] = tmp
    return l

def selectionSort(l:list, cmp = less):
    for i in range(len(l)):
        m_i = i
        for j in range(i+1,len(l)):
            if cmp(l[j], l[m_i]) : 
                m_i = j
        if m_i != i: 
            l[i], l[m_i] = l[m_i], l[i]
    return l

def _print(l:list, name:str, func):
    print("\nList : %s\n\n%s(list) :"%(l, name))
    print("Ascending Order  : %s"%(func(l)))
    print("Descending Order : %s\n"%(func(l, greater)))

l = [5, 8, 90, 10, 15, 7, 1, 6]
_print(l, "BubbleSort", bubbleSort)
l = [13.74, 10, 17, 0.1, 1.3, 3.14, 1.4]
_print(l, "InsertionSort", insertionSort)
l = ['Avinash', 'Magical', 'Python', 'Java', 'Program']
_print(l, "SelectionSort", selectionSort)
del(l)