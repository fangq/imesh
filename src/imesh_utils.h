/***************************************************************************//**
**  \mainpage Monte Carlo eXtreme - GPU accelerated Monte Carlo Photon Migration
**
**  \author Qianqian Fang <q.fang at neu.edu>
**  \copyright Qianqian Fang, 2009-2018
**
**  \section sref Reference:
**  \li \c (\b Fang2009) Qianqian Fang and David A. Boas, 
**          <a href="http://www.opticsinfobase.org/abstract.cfm?uri=oe-17-22-20178">
**          "Monte Carlo Simulation of Photon Migration in 3D Turbid Media Accelerated 
**          by Graphics Processing Units,"</a> Optics Express, 17(22) 20178-20190 (2009).
**  \li \c (\b Yu2018) Leiming Yu, Fanny Nina-Paravecino, David Kaeli, and Qianqian Fang,
**          "Scalable and massively parallel Monte Carlo photon transport
**           simulations for heterogeneous computing platforms," J. Biomed. Optics, 23(1), 010504, 2018.
**
**  \section slicense License
**          GPL v3, see LICENSE.txt for details
*******************************************************************************/

/***************************************************************************//**
\file    imesh_utils.h

@brief   MCX configuration header
*******************************************************************************/
                                                                                         
#ifndef _MCEXTREME_UTILITIES_H
#define _MCEXTREME_UTILITIES_H

#include <stdio.h>
#include <vector_types.h>
#include "br2cu.h"
#include "cjson/cJSON.h"
#include "float.h"
#include "nifti1.h"

#define EPS                FLT_EPSILON                   /**< round-off limit */
#define VERY_BIG           (1.f/FLT_EPSILON)             /**< a big number */

#define MAX_FULL_PATH       2048                         /**< max characters in a full file name string */
#define MAX_PATH_LENGTH     1024                         /**< max characters in a full file name string */
#define MAX_SESSION_LENGTH  256                          /**< max session name length */
#define MAX_DEVICE          256                          /**< max number of GPUs to be used */

#define imesh_ERROR(id,msg)   imesh_error(id,msg,__FILE__,__LINE__)  /**< macro for error handling */
#define MIN(a,b)           ((a)<(b)?(a):(b))             /**< macro to get the min values of two numbers */
#define MAX(a,b)           ((a)>(b)?(a):(b))             /**< macro to get the max values of two numbers */


/*! \struct MCXConfig
 * Data structure for MCX simulation settings
 */

typedef struct MCXConfig{
     float angle;
     float ssize;
     float approx;
     float reratio;
     float vsize;
     unsigned int seed;
} Config;

#ifdef	__cplusplus
extern "C" {
#endif
void imesh_savejnii(float *vol, int ndim, uint *dims, float *voxelsize, char* name, int isfloat, Config *cfg);
void imesh_savebnii(float *vol, int ndim, uint *dims, float *voxelsize, char* name, int isfloat, Config *cfg);
void imesh_savejdet(float *ppath, void *seeds, uint count, int doappend, Config *cfg);

#ifdef imesh_CONTAINER
#ifdef __cplusplus
extern "C"
#endif
 int  imesh_throw_exception(const int id, const char *msg, const char *filename, const int linenum);
 void imesh_matlab_flush(void);
#endif

#ifdef	__cplusplus
}
#endif

#endif
