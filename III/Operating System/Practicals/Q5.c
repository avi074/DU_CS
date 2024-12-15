#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define buf_size 128

#define error(s) if(s == -1){\
                            perror("Error : Unable to Close File !!!");\
                            exit(-3);}

void copy(int *i, int *o){
    short len = -1;

    char *buf = (char *) malloc(buf_size * sizeof(char));

    while(len != 0){
        len = read(*i, buf, buf_size);

        if(write(*o, buf, len) == -1){
            perror("Error : Unable to Write !!!");
            exit(-4);
        }
    }
    free(buf);
}


int main()
{
    int fin, fout = 1;
    
    fin = open("input",O_RDONLY);

    if(fin == -1){
        perror("Error : Input File Not Found !!!");
        exit(-10);
    }
    
    fout = open("output", O_WRONLY | O_CREAT); 
    if(fout == -1){
        perror("Error : Output File Not Created !!!");
        exit(-11);
    }
   
    copy(&fin , &fout);
    error(close(fin));
    error(close(fout));
    printf("Files have been copied successsfully !!!");
    return 0;
}
