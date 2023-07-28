#ifndef LIBFIO_FO_H
#define LIBFIO_FO_H

#include "fdef.h"
#include "fbase.h"
#include "ferror.h"

libfio_ferr libfio_write_impl(libfio_fname fname, const libfio_buf content, libfio_fmode fmode) {
    libfio_fstream fstream = libfio_fopen(fname,fmode);
    if(libfio_ferror(LIBFIO_FERR_CHECK))
        return libfio_ferror(LIBFIO_FERR_CHECK);

    if(fprintf(fstream,"%s",content) < 0)
        return libfio_ferror(LIBFIO_FERR_WRITE);
    fflush(fstream);

    libfio_fclose(fstream);
    return libfio_ferror(LIBFIO_FERR_CHECK);
}

libfio_ferr fio_clear(libfio_fname fname) {
    return libfio_write_impl(fname,"",LIBFIO_MODE_WRITE);
}

libfio_ferr fio_write(libfio_fname fname, const libfio_buf content) {
    return libfio_write_impl(fname,content,LIBFIO_MODE_WRITE);
}

libfio_ferr fio_append(libfio_fname fname, const libfio_buf content) {
    return libfio_write_impl(fname,content,LIBFIO_MODE_APPEND);
}

#endif /* LIBFIO_FO_H */