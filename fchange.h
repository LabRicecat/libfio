#ifndef LIBFIO_FCHANGE_H
#define LIBFIO_FCHANGE_H

#include "fdef.h"
#include "fbase.h"
#include "ferror.h"

libfio_ferr libfio_remove_impl(libfio_fname fname) {
    if(remove(fname)) 
        return libfio_ferror(LIBFIO_FERR_REMOVE);
    
    return libfio_ferror(LIBFIO_FERR_CHECK);
}

libfio_ferr libfio_rename_impl(libfio_fname fold, libfio_fname fnew) {
    if(rename(fold,fnew)) 
        return libfio_ferror(LIBFIO_FERR_REMOVE);
    
    return libfio_ferror(LIBFIO_FERR_CHECK);
}

libfio_ferr fio_remove(libfio_fname fname) {
    return libfio_remove_impl(fname);
}

libfio_ferr fio_rename(libfio_fname fold, libfio_fname fnew) {
    return libfio_rename_impl(fold,fnew);
}

#endif