/* This is "cppdefs.h": MODEL CONFIGURATION FILE
   ==== == ============ ===== ============= ==== */

/*
 * CHOOSE ONLY ONE PRIMARY FLAG FOR SWITCH LIST BELOW
 */

#define PACIFIC_PD /* PierreD's pacific coast model with tau-correction */
c-dd#define USWC_sample

/*
    Embedded (nested) grid configuration segment
*/

c--#ifndef MAX_GRID_LEVEL
c--# define MAX_GRID_LEVEL 2
c--# include "redefs.X"
c--#endif

/*
   Main switch starts here: model configuration choice.
*/

#if defined PACIFIC_PD || defined USWC_sample
/* PierreD's pacific coast model */

c-dd# define RIVER_SOURCE
c-dd# define PIPE_SOURCE
#define BIOLOGY_BEC2

c-dd# define WEC
# ifdef WEC
#    define BRK0
#    define SURFACE_BREAK
#    undef SPEC_DD
#    undef LOG_BDRAG
#    undef WKB_WWAVE
#    undef BBL
#    define WAVE_OFFLINE
#    define WAVE_FRICTION
#    define BBL_S95
c#    define BBL_F00
#    define SUP_OFF
#    define WAVE_DIFF_FROM_LM
# endif /* WEC */

/* Include standard CPP switches for UP ETH Zurich */
c-dd#include "cppdefs_UP.h"

/*
   Standard UP ETH Zurich Settings for Regional and Basin Configurations
   #### PLEASE do not change but use undef in cppdefs.h to undefine
   #### what as needed e.g., put #undef SPONGE in your personal cppdefs.h
*/
                     /* Basics */
#define SOLVE3D
#define UV_ADV
#define UV_COR
                     /*  Equation of State */
#define NONLIN_EOS
#define SPLIT_EOS
#define SALINITY
c-dd#define SFLX_CORR    /* DevinD turned off as new 25km input wrong for sss */
                     /*  Forcing */
                     /*         - surface */
#define DIURNAL_SRFLUX /* Note this is 'undef'ed' below */
c-dd#define QCORRECTION /* DevinD no longer used for bulk force */
                     /*         - lateral */
#define T_FRC_BRY
#define Z_FRC_BRY
#define M3_FRC_BRY
#define M2_FRC_BRY
#define SPONGE
#define SPONGE_WIDTH /* # of sponge points is input parameter */
                     /* Mixing */
                     /*        - lateral */
#define UV_VIS2
#define TS_DIF2
                     /*        - vertical */
#define LMD_MIXING
#define LMD_KPP
#define LMD_NONLOCAL
#define LMD_RIMIX
#define LMD_CONVEC
#define LMD_BKPP

                      /* Grid Configuration */
#define CURVGRID
#define SPHERICAL
#define MASKING

                      /* Output Options */
#define MASK_LAND_DATA

                      /* Restart */
!--> #define EXACT_RESTART

                      /* Open Boundary Conditions */
#define OBC_M2FLATHER  /* Barotop. BC: OBC_M2FLATHER, OBC_M2ORLANSKI, OBC_M2SPECIFIED */
#define OBC_M3ORLANSKI /* Baroclin. BC: OBC_M3ORLANSKI, OBC_M3SPECIFIED */
#define OBC_TORLANSKI  /* Tracer BC: OBC_TORLANSKI, OBC_TSPECIFIED */


/* End of UP ETH Standard Settings */

/* Open Boundaries */
#define OBC_WEST /* Open boundary in the west (in order: SO out, SO in, Ind. throughflow) */
#define OBC_NORTH  /* Open boundary North (Arctic) */
#define OBC_EAST
#define OBC_SOUTH
#undef SPONGE /* DevinD - defined in cppdefs_UP.h */

/* Switches required for Flux correction */
c-dd#define SFLX_CORR ! Already defined in cppdefs_UP.h & DEVIND IN NEW CODE
#undef VFLX_CORR
#undef QCORRECTION
c-dd#define TAU_CORRECTION
#undef DIURNAL_SRFLUX


#define ADV_ISONEUTRAL

/* Biology Settings */
#ifdef BIOLOGY_BEC2
# define BIOLOGY /* Needed for init_scalars.F */
# define DEFAULT_BRY_VALUES
# define BEC2_DIAG
# define Ncycle_SY
# define N2O_TRACER_DECOMP
# define N2O_NEV
# undef RIVER_LOAD_N /* PD had undef'ed */
# undef RIVER_LOAD_P /* PD had undef'ed */
# define PCO2AIR_FORCING
#endif /* BIOLOGY_BEC2 */

#define BULK_FRC
c-dd#define BULK_FLUX_OUTPUT /* DevinD added this for sustr and svstr outputs in new code */

    /* Flux Analysis */
c-dd# define WRITE_DEPTHS /* For Budget Analysis Closure */

    /* Tides */
#ifdef PACIFIC_PD
# define TIDES
#endif
# ifdef TIDES
#  define POT_TIDES
#  define SSH_TIDES
#  define UV_TIDES
c-dd-gone#  define TIDERAMP ! No longer using tideramp
# endif


#elif defined DUMMY_CASE

#  define MASKING

#endif


#include "set_global_definitions.h"

