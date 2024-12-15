def _print_(x):
    for i in x:
        print(i)

def sum(l:list, l1:list):
    if len(l) != len(l1) or len(l[0]) != len(l1[0]):
        print("\nBoth matrices have to be in a same order for addition.")
    else:
        r = [[l[i][j] + l1[i][j]  for j in range(len(l[0]))] for i in range(len(l))]
        _print_(r)

def product(l:list, l1:list):
    if len(l[0]) != len(l1):
        print("Matrices are not compatible to product.")
    else:
        r = [[0 for j in range(len(l1[0]))]for i in range(len(l))]
        for i in range(len(l)):
            for j in range(len(l1[0])):
                for k in range(len(l1)):
                    r[i][j] += l[i][k] * l1[k][j]
        _print_(r)


a = [[1,2,1],[4,5,2],[7,8,3]]

b = [[1,2],[4,5],[7,1]]

c = [[1,2,3],[4,5,6],[7,8,9]]

print("\nMatrix A \n")
_print_(a)
print("\nMatrix B \n")
_print_(b)
print("\nMatrix C \n")
_print_(c)
print("\nSum of matrix A & C\n")
sum(a,c)
print("\nProduct of matrix A & B\n")
product(a,b)