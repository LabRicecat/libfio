#ifndef LIBFIO_BASE_H
#define LIBFIO_BASE_H

#ifndef LIBFIO_SIZE_DEF
#define LIBFIO_SIZE_DEF
# include <stdint.h>
typedef uint64_t libfio_size64;
typedef uint32_t libfio_size32;
typedef uint16_t libfio_size16;

typedef libfio_size64 libfio_size;
typedef libfio_size64 libfio_fsize;
typedef libfio_size64 libfio_asize;
#endif

#ifndef LIBFIO_BUFFER_DEF
#define LIBFIO_BUFFER_DEF
# include <stdlib.h>
typedef char* libfio_buf;

libfio_buf libfio_allocbf(libfio_asize alloc) {
    return (libfio_buf)malloc(alloc);
}

void libfio_freebf(libfio_buf buf) {
    free(buf);
}
#endif

#ifndef LIBFIO_NAME_DEF
#define LIBFIO_NAME_DEF
# include <stdlib.h>
typedef const char* libfio_fname;

#endif

#ifdef LIBFIO_USE_STDIO
# include <stdio.h>
# include "ferror.h"
typedef FILE* libfio_fstream;
typedef const char* libfio_fmode;
#define LIBFIO_MODE_WRITE "w+"
#define LIBFIO_MODE_APPEND "a+"
#define LIBFIO_MODE_READ "r"

extern libfio_fstream libfio_fopen(libfio_fname fname, libfio_fmode fmode) {
    return fopen(fname,fmode);
}

extern libfio_ferr libfio_fclose(libfio_fstream fstream) {
    if(fclose(fstream)) {
        return LIBFIO_FERR_CLOSE;
    }
    return LIBFIO_FERR_OK;
}

extern libfio_fsize libfio_gfsize(libfio_fname fname) {
    libfio_fsize s = 0;
    libfio_fstream fstream = libfio_fopen(fname,LIBFIO_MODE_READ);

    if(!fstream) {
        libfio_ferror(LIBFIO_FERR_OPEN);
        return 0;
    }

    while(fgetc(fstream) != EOF) 
        ++s;

    if(libfio_fclose(fstream)) {
        libfio_ferror(LIBFIO_FERR_CLOSE);
        return 0;
    }

    return s;
}

libfio_fsize fio_size(libfio_fname fname) {
    return libfio_gfsize(fname);
}

#endif

#endif /* LIBFIO_BASE_H */