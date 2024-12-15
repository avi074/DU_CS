def cchar(s:list):
    c = 0
    t = 0
    for i in range(len(s)):
        if 'the' in s[i]:
            t += 1
        c += len(s) - s.count(' ')
    return c, t

def count(s:str, s1:str):
    try:
        c = 0
        t = 0
        with open(s,'r') as fi:
          data = fi.readlines()
          c,t = cchar(data)
          with open(s1, 'w') as fo:
              for i in range(1,len(data)+1):
                  if i % 2 == 0:
                      fo.write(data[i-1])
    except IOError:
        print("IOERROR : Error in files !!!")
    finally:
        print("Total number of characters : ", c)
        print("Total number of \"the\" : ", t)
        print("Files have been copied successfully !!!")

count("abcd", "file")