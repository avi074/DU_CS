def valid(a, b, c):
    return (a + b > c) and (a + c > b) and (b + c > a)

def Area(a, b, c):
    s = (a + b + c)/2
    return (s*(s-a)*(s-b)*(s-c))**0.5

s1 = float(input("\nEnter the side1 value : "))
s2 = float(input("Enter the side2 value : "))
s3 = float(input("Enter the side3 value : "))

if valid(s1, s2, s3):
    print("The Area of triangle is :",Area(s1, s2, s3))
else:
    print("Invalid length of Sides !!!!")
print()