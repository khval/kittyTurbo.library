/* :ts=4
 *  $VER: makeLookupTable.c $Revision$ (16-Mar-2020)
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
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <libraries/kittyTurbo.h>
#include <proto/kittyTurbo.h>
#include <stdarg.h>

#include <proto/retroMode.h>
#include <amoskittens.h>

/****** kittyTurbo/main/makeLookupTable ******************************************
*
*   NAME
*      makeLookupTable -- Description
*
*   SYNOPSIS
*      char * makeLookupTable(void);
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

char * _kittyturbo_makeLookupTable(struct kittyCompactIFace *Self)
{
	struct cmdData *cmd;
	char *ptr;
	ptr = (char *) AllocVecTags( 0x10000, 
			AVT_Type, MEMF_SHARED, 
			AVT_ClearWithValue, 0,
			TAG_END );

	Printf("makeLookupTable\n");

/*
	for (cmd=AMOSPro_Turbo;cmd -> fn;cmd++)
	{
		Printf("%08lx\n",((char *(**) KITTENS_CMD_ARGS) (ptr + cmd -> token)));

		*((char *(**) KITTENS_CMD_ARGS) (ptr + cmd -> token)) = cmd -> fn;
	}
*/

	return ptr;
}

