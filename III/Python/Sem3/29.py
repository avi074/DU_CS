def copy(s:str, s1:str):
    try:
        with open(s,'r') as fi:
          data = fi.readlines()
          with open(s1, 'w') as fo:
              for i in range(len(data)):
                  if i % 2 == 0:
                      fo.write(data[i])
    except IOError:
        print("IOERROR : Error in files !!!")
    else:
        print("Files have been copied successfully !!!")

copy("file1", "file2")