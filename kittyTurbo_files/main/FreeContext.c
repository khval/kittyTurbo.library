/* :ts=4
 *  $VER: FreeContext.c $Revision$ (22-Mar-2020)
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <libraries/kittyTurbo.h>
#include <proto/kittyTurbo.h>
#include <stdarg.h>
#include "context.h"

/****** kittyTurbo/main/FreeContext ******************************************
*
*   NAME
*      FreeContext -- Description
*
*   SYNOPSIS
*      void FreeContext(void * table);
*
*   FUNCTION
*
*   INPUTS
*       table - 
*
*   RESULT
*       This function does not return a result
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

void _kittyturbo_FreeContext(struct kittyTurboIFace *Self,
       struct context * context)
{
	if (context)
	{
		free (context);
	}
}

