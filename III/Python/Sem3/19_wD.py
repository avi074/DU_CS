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
	for i in d.items():
		print(i)


n = int(input("\nHow many words you want to enter : "))
d = {}
for i in range(n):
	print("\n",i+1,":")
	w = input("Word\t: ")
	m = input("Meaning : ")
	d[w] = m

print("\n(Word, Meaning) : \n")
_print_(d)
print("\n(Meaning, Words) : \n")
_print_(change(d))
