def _print_(x):
    for i in x:
        print(i)

def sum(l:list, l1:list):
    if len(l) != len(l1) or len(l[0]) != len(l1[0]):
        print("Both matrices have to be in a same order for addition.")
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


a = [[2, 1, 4],[0, 1, 1]]

b = [[6, 3, -1, 0],[1, 1, 0, 4],[-2, 5, 0, 2]]

print("\nMatrix A ")
_print_(a)
print("\nMatrix B ")
_print_(b)
print("\nSum of matrix A & B : ")
sum(a,b)
print("\nProduct of matrix A & B : ")
product(a,b)