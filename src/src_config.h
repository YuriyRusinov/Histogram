#ifndef _HIST_CONFIG_H_
#define _HIST_CONFIG_H_


/* ==================================================================== */
/*      We will use WIN32 as a standard windows define.                 */
/* ==================================================================== */
#if defined(_WIN32) && !defined(WIN32)
    #define WIN32
#endif

#if defined(_WINDOWS) && !defined(WIN32)
    #define WIN32
#endif

/* ==================================================================== */
/*      Standard include files.                                         */
/* ==================================================================== */

#ifdef WIN32
    #ifndef _ERRCODE_DEFINED
        #define _ERRCODE_DEFINED
    #endif
    typedef int errno_t;
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>


#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

// assertion suport
#include <assert.h>

#if defined( WIN32 )
    #if defined( _HIST_DLL_ )
        #define _HIST_EXPORT_ __declspec(dllexport)
    #else
        #define _HIST_EXPORT_ __declspec(dllimport)
    #endif

    #ifndef DLLIMPORT
        #define DLLIMPORT __declspec(dllexport)
    #endif

#else
    #define _HIST_EXPORT_
#endif /* FFTMATR_DLL */

#ifndef NULL
    #define NULL  0
#endif

#ifndef FALSE
    #define FALSE 0
#endif

#ifndef TRUE
    #define TRUE  1
#endif

#ifndef MAX
    #define MIN(a,b)    ((a<b) ? a : b)
    #define MAX(a,b)    ((a>b) ? a : b)
#endif

#ifndef ABS
    #define ABS(x)      ((x<0) ? (-1*(x)) : x)
#endif

/* -------------------------------------------------------------------- */
/*      Macro to test equality of two floating point values.            */
/*      We use fabs() function instead of ABS() macro to avoid side     */
/*      effects.                                                        */
/* -------------------------------------------------------------------- */
#ifndef EQUAL_F
    #define EQUAL_F(x,y) (fabs((x) - (y)) < 0.0000000000001)
#endif

#ifndef EQUAL_S
    #if defined(WIN32)
        #define EQUAL_SN(a,b,n) (_strnicmp(a,b,n)==0)
        #define EQUAL_S(a,b)    (_stricmp(a,b)==0)
        #define MKDIR(a, b)     _mkdir(a)
    #else
        #define EQUAL_SN(a,b,n) (strncasecmp(a,b,n)==0)
        #define EQUAL_S(a,b)    (strcasecmp(a,b)==0)
        #define MKDIR(a, b)     mkdir(a, b)
    #endif
#endif

#if defined(WIN32)
    #define snprintf _snprintf
#endif

static const char HistRand_version[] = "LibHistRand Version 0.0.1";

#if defined( WIN32 )
#define __PRETTY_FUNCTION__ __FUNCTION__
#else
#define __FUNCTION__ __PRETTY_FUNCTION__
#endif

#endif /* _HIST_CONFIG_H_ */
