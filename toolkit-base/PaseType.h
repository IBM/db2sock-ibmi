#ifndef _PASETYPE_H
#define _PASETYPE_H

#include <qp2user.h>

#ifndef ILEpointer
typedef void * ILEpointer;
#endif

#ifndef int8
#define int8 char
#endif
#ifndef uint8
#define uint8 unsigned char
#endif
#ifndef int16
#define int16 short
#endif
#ifndef uint16
#define uint16 unsigned short
#endif
#ifndef int32
#define int32 int
#endif
#ifndef uint32
#define uint32 unsigned int
#endif
#ifndef int64
#define int64 long long
#endif
#ifndef uint16
#define uint16 unsigned short
#endif
#ifndef uint16
#define uint16 unsigned short
#endif
#ifndef int32
#define int32 int
#endif
#ifndef uint32
#define uint32 unsigned int
#endif
#ifndef int64
#define int64 long long
#endif
#ifndef uint64
#define uint64 unsigned long long
#endif


/* positive arg_type_t values are length of aggregate argument */
/* (packed and zoned decimal passed as aggregate arguments) */
#define ARG_END         0       /* end-of-list sentinel */
#define ARG_INT8        (-1)
#define ARG_UINT8       (-2)
#define ARG_INT16       (-3)
#define ARG_UINT16      (-4)
#define ARG_INT32       (-5)
#define ARG_UINT32      (-6)
#define ARG_INT64       (-7)
#define ARG_UINT64      (-8)
#define ARG_FLOAT32     (-9)
#define ARG_FLOAT64     (-10)   /* 8-byte binary or decimal float */
#define ARG_MEMPTR      (-11)   /* Caller provides PASE memory address */
#define ARG_SPCPTR      (-12)   /* Caller provides tagged pointer */
#define ARG_OPENPTR     (-13)   /* Caller provides tagged pointer */
#define ARG_MEMTS64     (-14)   /* Caller provides PASE memory address */
#define ARG_TS64PTR     (-15)   /* Caller provides teraspace pointer */
#define ARG_SPCPTRI     (-16)   /* Caller provides address of tagged ptr */
#define ARG_OPENPTRI    (-17)   /* Caller provides address of tagged ptr */
#define ARG_FLOAT128    (-18)   /* 16-byte binary or decimal float */

/*
 * Function result types returned by ILE procedures
 */
typedef int16   result_type_t;
/* positive result_type_t values are length of aggregate result */
/* (zoned decimal and packed longer than 31 digits returned as aggregate result) */
#define RESULT_VOID     0
#define RESULT_INT8     (-1)
#define RESULT_UINT8    (-2)
#define RESULT_INT16    (-3)
#define RESULT_UINT16   (-4)
#define RESULT_INT32    (-5)
#define RESULT_UINT32   (-6)
#define RESULT_INT64    (-7)
#define RESULT_UINT64   (-8)
#define RESULT_FLOAT64  (-10)   /* 8-byte binary or decimal float */
#define RESULT_FLOAT128 (-18)   /* 16-byte binary or decimal float */
#define RESULT_PACKED15 (-19)   /* 15-digit packed decimal */
#define RESULT_PACKED31 (-20)   /* 31-digit packed decimal */

/* special for in proc calls */
void iCall400(char * blob);


#endif /* _PASETYPE_H */

