#ifndef _FEATURES_H_
#define _FEATURES_H_

/* certain Linux-specific programs expect a <features.h> header file
 * that defines various features macros
 */

/* we do include a number of BSD extensions */
#define  _BSD_SOURCE  1

/* we do include a number of GNU extensions */
#define  _GNU_SOURCE  1

/* C95 support */
#undef __USE_ISOC95
#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199409L
# define __USE_ISOC95   1
#endif

/* C99 support */
#undef __USE_ISOC99
#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
# define __USE_ISOC99   1
#endif

/* Posix support */
#define  __USE_POSIX   1
#define  __USE_POSIX2  1
#define  __USE_XPG     1

#endif /* _FEATURES_H_ */
