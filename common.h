/*
	   Copyright (C) 2004-2005 Sergey Koposov
   
    Author: Sergey Koposov, Sternberg Astronomical Institute
    Email: math@sai.msu.ru 
    http://lnfm1.sai.msu.ru/~math

    This file is part of Q3C.

    Q3C is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Q3C is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Q3C; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include <math.h>
#include <stdlib.h>
#include "postgres.h"
#ifndef Q3C_COMMON_H
#define Q3C_COMMON_H
#define _GNU_SOURCE


/* If You have not specified the Q3C_INT4 then use the Q3C_INT8 instead */
#ifndef Q3C_INT4 

#ifndef Q3C_INT8
#define Q3C_INT8
#endif /* Q3C_INT8 */

#ifndef q3c_ipix_t
//#define q3c_ipix_t long long 
//typedef long long q3c_ipix_t ;
typedef int64 q3c_ipix_t ;

#endif /* q3c_ipix_t */

#ifndef Q3C_IPIX_FMT
#define Q3C_IPIX_FMT "%lld"
#endif /* Q3C_IPIX_FMT */

#else 

#ifndef q3c_ipix_t
//#define q3c_ipix_t long int
//typedef unsigned long int q3c_ipix_t;
typedef uint32 q3c_ipix_t;
#endif /* q3c_ipix_t */

#ifndef Q3C_IPIX_FMT
#define Q3C_IPIX_FMT "%ld"
#endif /* Q3C_IPIX_FMT */  

#endif /* Q3C_INT8 */ 




/* If You have not specified the Q3C_LONG_DOUBLE macro then we will use simple 
   double functions */
#ifndef Q3C_LONG_DOUBLE
typedef double q3c_coord_t;
#define q3c_pow(a,b) pow(a, b)
#define q3c_fabs(a) fabs(a)
#define q3c_fmod(a,b) fmod(a, b)
#define q3c_cos(a) cos(a)
#define q3c_sin(a) sin(a)
#define q3c_asin(a) asin(a)
#define q3c_sincos(a, b, c) sincos(a, b, c)
#define q3c_tan(a) tan(a)
#define q3c_atan(a) atan(a)
#define q3c_atan2(a,b) atan2(a, b)
#define q3c_sqrt(a) sqrt(a)
#define q3c_log(a) log(a)
#define q3c_ceil(a) ceil(a)
#define q3c_HALF 0.5
#define Q3C_COORD_FMT "%f"
#define q3c_PI 3.1415926535897932384626433832795028841968
#define q3c_2PI 6.2831853071795864769252867665590057683936
#define q3c_PI_2 1.5707963267948966192313216916397514420984
#define q3c_DEGRA 0.0174532925199432957692369076848861271344
#define q3c_RADEG 57.2957795130823208767981548141051703324122
#define q3c_LG2 0.6931471805599453094172321214581765680755
/* 
I really do not see the reason to set them as const ... 
const q3c_coord_t q3c_PI=3.1415926535897932384626433832795028841968;
const q3c_coord_t q3c_2PI=6.2831853071795864769252867665590057683936;
const q3c_coord_t q3c_PI_2=1.5707963267948966192313216916397514420984;
const q3c_coord_t q3c_DEGRA=0.0174532925199432957692369076848861271344;
const q3c_coord_t q3c_RADEG=57.2957795130823208767981548141051703324122;
const q3c_coord_t q3c_LG2=0.6931471805599453094172321214581765680755;
*/
#else /* Q3C_LONG_DOUBLE */
typedef long double q3c_coord_t;
#define q3c_pow(a,b) powl(a, b)
#define q3c_fabs(a) fabsl(a)
#define q3c_fmod(a,b) fmodl(a, b)
#define q3c_cos(a) cosl(a)
#define q3c_sin(a) sinl(a)
#define q3c_asin(a) asinl(a)
#define q3c_sincos(a, b, c) sincosl(a, b, c)
#define q3c_tan(a) tanl(a)
#define q3c_atan(a) atanl(a)
#define q3c_atan2(a,b) atan2l(a, b)
#define q3c_sqrt(a) sqrtl(a)
#define q3c_log(a) logl(a)
#define q3c_ceil(a) ceill(a)
#define q3c_HALF 0.5L
#define Q3C_COORD_FMT "%.15Lf"
#define q3c_PI 3.1415926535897932384626433832795028841968L
#define q3c_2PI 6.2831853071795864769252867665590057683936L
#define q3c_PI_2 1.5707963267948966192313216916397514420984L
#define q3c_DEGRA 0.0174532925199432957692369076848861271344L
#define q3c_RADEG 57.2957795130823208767981548141051703324122L
#define q3c_LG2 0.6931471805599453094172321214581765680755L
#endif /* Q3C_LONG_DOUBLE */


#ifndef q3c_cbits
#define q3c_cbits sizeof(q3c_coord_t)
#endif /* q3c_cbits */

#ifndef q3c_ibits
#define q3c_ibits sizeof(q3c_ipix_t)
#endif /* q3c_ibits */

#ifndef q3c_interleaved_nbits 
#define q3c_interleaved_nbits 16
#endif /* q3c_interleaved_nbits */



/* this probably will work only in the case of long double variables ?? */

//#define q3c_PI    3.1415926535897932384626433832795029L
/* #define q3c_2_PI  3.1415926535897932384626433832795029L */
//#define q3c_2PI 6.2831853071795864769252867665590058L
//#define q3c_PI_2  1.5707963267948966192313216916397514L
//#define q3c_DEGRA 0.01745329251994329576923690768488612L
//#define q3c_RADEG 57.295779513082320876798154814105170L
//#define q3c_LG2   0.301029995663981195213738894724493026768L
//#define q3c_LG2   0.6931471805599453094172321214581765680755L
#define q3c_BOX_INTERSECT(x0, x1, y0, y1, a0, a1, b0, b1) ((((x0 < a0) && \
                                                          (x1 >= a0)) || \
                                                          (x0 <= a1)) && \
                                                          (((y0 < b0) && \
                                                          (y1 >= b0)) || \
                                                          (y0 <= b1)))
/* True if square(x0,x1,y0,y1) and square(a0,a1,b0,b1) have any common point*/ 

#define q3c_INTERSECT(a, b, x, y) (((a <= y) && (a >= x)) || \
                                  ((a < x) && (b >= x)))

#define q3c_DISJUNCT 0 /* disjunct areas */
#define q3c_PARTIAL 1 /* partial coverage */
#define q3c_EDGE 1 /* point lie on the edge of the region */
#define q3c_COVER 2 /* the point or the region is completely inside other */


struct q3c_prm 
{
  q3c_ipix_t nside;
  q3c_ipix_t *xbits;
  q3c_ipix_t *ybits;
  q3c_ipix_t *xbits1;
  q3c_ipix_t *ybits1;
};

struct q3c_square 
{
  q3c_ipix_t x0,y0; /* Integer coordinates of the center of the square for */
  int nside0;       /* the nside0 segmentation */
  char status;
};

struct q3c_poly
{
  int n;
  q3c_coord_t *ra;	/* array of RAs of vertices */
  q3c_coord_t *dec;	/* array of DECs of vertices */
  q3c_coord_t *x;		/* array of X coords on the cube face of vertices */
  q3c_coord_t *y;		/* array of Y coords on the cube face of vertices */
  q3c_coord_t *ax;		/* array of x projections of the edge between vertices */
  q3c_coord_t *ay;		/* array of y projections of the edge between vertices */
};


void init_q3c(struct q3c_prm *, q3c_ipix_t);
void init_q3c1(struct q3c_prm *, q3c_ipix_t);
void q3c_dump_prm(struct q3c_prm *,char *);
void q3c_ang2ipix(struct q3c_prm *, q3c_coord_t, q3c_coord_t, q3c_ipix_t *);
void q3c_ipix2ang(struct q3c_prm *, q3c_ipix_t , q3c_coord_t *, q3c_coord_t *);
void q3c_radial_query(struct q3c_prm *, char *, char *, char *,
                      q3c_coord_t, q3c_coord_t, q3c_coord_t, char *);
void q3c_get_nearby_split(struct q3c_prm *, q3c_coord_t, q3c_coord_t,
                      q3c_coord_t, q3c_ipix_t *, int);
void q3c_get_nearby(struct q3c_prm *, q3c_coord_t, q3c_coord_t,
                    q3c_coord_t, q3c_ipix_t *);
void q3c_get_xy_minmax(q3c_coord_t, q3c_coord_t, q3c_coord_t, 
                       q3c_coord_t, q3c_coord_t, q3c_coord_t,
                       q3c_coord_t *, q3c_coord_t *, q3c_coord_t *,
                       q3c_coord_t *);
void ang2ipix_xy(struct q3c_prm *hprm, q3c_coord_t ra, q3c_coord_t dec,
                 char *out_face_num, q3c_ipix_t *ipix, q3c_coord_t *x_out, 
                 q3c_coord_t *y_out);
void q3c_get_poly_coefs(char, q3c_coord_t, q3c_coord_t, 
                        q3c_coord_t, q3c_coord_t *, q3c_coord_t *,
                        q3c_coord_t *, q3c_coord_t *, q3c_coord_t *,
                        q3c_coord_t *);
char q3c_xy2facenum(q3c_coord_t, q3c_coord_t, char);
char q3c_getfacenum(q3c_coord_t, q3c_coord_t);
void q3c_fast_get_xy_minmax(char, q3c_coord_t, q3c_coord_t, q3c_coord_t,
                            q3c_coord_t *, q3c_coord_t *, q3c_coord_t *,
                            q3c_coord_t *);
q3c_coord_t q3c_dist(q3c_coord_t, q3c_coord_t, q3c_coord_t, q3c_coord_t);
q3c_coord_t q3c_sindist(q3c_coord_t, q3c_coord_t, q3c_coord_t, q3c_coord_t);
void q3c_new_radial_query(struct q3c_prm *hprm, q3c_coord_t ra0,
                          q3c_coord_t dec0, q3c_coord_t rad,
                          q3c_ipix_t *out_ipix_arr_fulls,
                          q3c_ipix_t *out_ipix_arr_partials);
void q3c_init_poly(struct q3c_poly *qp, int n);
void q3c_prepare_poly(struct q3c_poly *qp);
void q3c_project_poly(struct q3c_poly *qp, char facenum);
char q3c_get_facenum_poly(struct q3c_poly *qp);
int q3c_check_point_in_poly(struct q3c_poly *qp, q3c_coord_t x0,
                            q3c_coord_t y0);
int q3c_poly_cover_check(struct q3c_poly *qp, q3c_coord_t xc_cur,
                         q3c_coord_t yc_cur, q3c_coord_t cur_size);                         
void q3c_get_minmax_poly(struct q3c_poly *qp, q3c_coord_t *xmin,
                         q3c_coord_t *xmax, q3c_coord_t *ymin, 
                         q3c_coord_t *ymax);
void q3c_poly_query(struct q3c_prm *hprm, struct q3c_poly *qp,
                          q3c_ipix_t *out_ipix_arr_fulls,
                          q3c_ipix_t *out_ipix_arr_partials);
int q3c_check_sphere_point_in_poly(struct q3c_prm *hprm, int n,
                                   q3c_coord_t in_ra[], q3c_coord_t in_dec[],
                                   q3c_coord_t ra0, q3c_coord_t dec0,
                                   int invocation);

                
#endif/*  Q3C_COMMON_H  */