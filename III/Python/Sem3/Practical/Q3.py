def change(d:dict):
	d1 = {}
	l = []
	for m in d.values():
		for w in d.keys():
			if d[w] == m:
				l.append(w)
		d1[m] = l.copy()
		l.clear()
	return d1

def _print_(d):
	for i in d.keys():
		print("%s \t : \t %s"%(i, d[i]))


n = int(input("\nHow many sets you want to enter : "))
d = {}
for i in range(n):
	print("\n %s : "%(i+1))
	w = input("Color : ")
	m = input("Fruit : ")
	d[w] = m

print("\nColor\t :\t Fruit")
_print_(d)
print("\nFruits\t :\t Colors")
_print_(change(d))