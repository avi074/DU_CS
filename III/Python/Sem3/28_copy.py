import pdb

print("\n\tPractical 28 \n Files' Copying")
i = input("\nEnter File path/name for copying : ")
o = input("\nEnter File name for output : ")
pdb.set_trace()

try:
	with open(i,'r') as fi:
		with open(o,'w') as fo:
			fo.write(fi.read())
except IOError:
	print("Error: can\'t find file or read or write data")
else:
	print("\nData has been copied successfully !!!")
		
