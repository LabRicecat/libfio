#ifndef LIBFIO_FNEW_H
#define LIBFIO_FNEW_H

#include "fdef.h"
#include "fbase.h"
#include "ferror.h"
#include "fo.h"

libfio_ferr libfio_fnew_impl(libfio_fname fname, const libfio_buf content) {
    libfio_fstream fstream = libfio_fopen(fname,LIBFIO_MODE_APPEND);
    if(!fstream)
        return libfio_ferror(LIBFIO_FERR_NEW);
    
    if(content)
        fio_write(fname,content);

    libfio_fclose(fstream);
    return libfio_ferror(LIBFIO_FERR_CHECK);
}

libfio_ferr fio_new(libfio_fname fname) {
    return libfio_fnew_impl(fname,NULL);
}

libfio_ferr fio_newc(libfio_fname fname, const libfio_buf content) {
    return libfio_fnew_impl(fname,content);
}

#endif