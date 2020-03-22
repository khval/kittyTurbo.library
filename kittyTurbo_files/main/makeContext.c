/* :ts=4
 *  $VER: makeContext.c $Revision$ (22-Mar-2020)
 *
 *  This file is part of kittyTurbo.
 *
 *  Copyright (c) 2020 LiveForIt Software.
 *  MIT License..
 *
 * $Id$
 *
 * $Log$
 *
 *
 */


#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <libraries/kittyTurbo.h>
#include <proto/kittyTurbo.h>
#include <stdarg.h>

/****** kittyTurbo/main/makeContext ******************************************
*
*   NAME
*      makeContext -- Description
*
*   SYNOPSIS
*      void * makeContext(void);
*
*   FUNCTION
*
*   INPUTS
*
*   RESULT
*       The result ...
*
*   EXAMPLE
*
*   NOTES
*
*   BUGS
*
*   SEE ALSO
*
*****************************************************************************
*
*/

void * _kittyturbo_makeContext(struct kittyCompactIFace *Self)
{
  return makeContext();
}

