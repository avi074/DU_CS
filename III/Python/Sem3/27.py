def count(s:str):
    vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
    v_count = 0
    w_count = 0
    try:
        with open(s,'r') as fi:
            for char in fi.read():
                if char in vowels:
                    v_count += 1
                if char == " " or char == '\t' or char == '\n':
                    w_count += 1
    except IOError:
        print("IOERROR : Error in File !!!")
    else:
        print("Total number of vowels are: ", v_count)
        print("Total number of words are: ", w_count)

count("file1")