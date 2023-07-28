#include "fio.h"

int main() {
    char* file = "test.txt";
    fio_new("aaa.txt");
    fio_newc("bbb.txt","bbb");
    fio_write(file,"Bye World");
    fio_append(file," lmao");

    libfio_buf f = fio_read(file);
    
    printf("%s\n",f);
    printf("%ld\n",fio_size(file));

    free(f);
}