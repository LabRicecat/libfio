#ifndef LIBFIO_FI_H
#define LIBFIO_FI_H

#include "fdef.h"
#include "fbase.h"
#include "ferror.h"

libfio_buf libfio_read_impl(libfio_fname fname) {
    libfio_fstream fstream = libfio_fopen(fname,LIBFIO_MODE_READ);
    
    if(!fstream) {
        libfio_ferror(LIBFIO_FERR_OPEN);
        return NULL;
    }

    libfio_fsize fsize = libfio_gfsize(fname);
    if(libfio_ferror(LIBFIO_FERR_CHECK)) {
        libfio_fclose(fstream);
        return NULL;
    }

    libfio_buf fbuf = libfio_allocbf(fsize + 1);

    if(!fbuf) {
        libfio_fclose(fstream);
        libfio_ferror(LIBFIO_FERR_ALLOC);
        return NULL;
    }

    for(int i_ = 0; i_ < fsize; ++i_)
        fbuf[i_] = fgetc(fstream);
    fbuf[fsize] = '\0';

    libfio_fclose(fstream);
    if(libfio_ferror(LIBFIO_FERR_CHECK)) {
        libfio_freebf(fbuf);
        return NULL;
    }

    return fbuf;
}

libfio_buf fio_read(libfio_fname fname) {
    return libfio_read_impl(fname);
}

#endif /* LIBFIO_FI_H */