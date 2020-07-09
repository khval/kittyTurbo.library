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
#include "list.h"

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

void dispose_blit (void *ptr)
{
	printf("blit ptr %08x\n",ptr);
	free(ptr);
}

void dispose_object (void *ptr)
{
	printf("object ptr %08x\n",ptr);
	free(ptr);
}

void _kittyturbo_FreeContext(struct kittyTurboIFace *Self,
       struct context * context)
{
	if (context)
	{
		if (context -> stars) free (context -> stars);
		context -> stars = NULL;

		if (context -> checks) free (context -> checks);
		context -> checks = NULL;

		list_free( &context -> blits, dispose_blit );
		list_free( &context -> objects, dispose_object );

		if (context -> multi_task_off_count)		// prohibit hanging forbid
		{
			Permit();
			context -> multi_task_off_count = 0;
		}

		free (context);
	}
}

