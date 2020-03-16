#ifndef PROTO_KITTYTURBO_H
#define PROTO_KITTYTURBO_H

/*
**	$Id$
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef LIBRARIES_KITTYTURBO_H
#include <libraries/kittyTurbo.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * kittyTurboBase;
 #else
  extern struct Library * kittyTurboBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/kittyTurbo.h>
 #ifdef __USE_INLINE__
  #include <inline4/kittyTurbo.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_KITTYTURBO_PROTOS_H
  #define CLIB_KITTYTURBO_PROTOS_H 1
 #endif /* CLIB_KITTYTURBO_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct kittyCompactIFace *IkittyTurbo;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_KITTYTURBO_PROTOS_H
  #include <clib/kittyTurbo_protos.h>
 #endif /* CLIB_KITTYTURBO_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/kittyTurbo.h>
  #else /* __PPC__ */
   #include <ppcinline/kittyTurbo.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/kittyTurbo_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/kittyTurbo_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_KITTYTURBO_H */
