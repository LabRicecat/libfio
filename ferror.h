#ifndef LIBFIO_FERROR_H
#define LIBFIO_FERROR_H

#ifndef LIBFIO_FERROR_ERR_DEF
#define LIBFIO_FERROR_ERR_DEF
typedef int libfio_ferr;

#define LIBFIO_FERR_CHECK   ((libfio_ferr)-1)
#define LIBFIO_FERR_OK      ((libfio_ferr)0 )
#define LIBFIO_FERR_OPEN    ((libfio_ferr)1 )
#define LIBFIO_FERR_CLOSE   ((libfio_ferr)2 )
#define LIBFIO_FERR_READ    ((libfio_ferr)3 )
#define LIBFIO_FERR_WRITE   ((libfio_ferr)4 )
#define LIBFIO_FERR_ALLOC   ((libfio_ferr)5 )
#define LIBFIO_FERR_NEW     ((libfio_ferr)6 )
#define LIBFIO_FERR_REMOVE  ((libfio_ferr)7 )
#define LIBFIO_FERR_RNAME   ((libfio_ferr)8 )

#endif

libfio_ferr libfio_ferror(libfio_ferr ferr) {
    static libfio_ferr libfio_ferrg;
    if(ferr == LIBFIO_FERR_CHECK) 
        return libfio_ferrg;

    return libfio_ferrg = ferr;
}

#endif