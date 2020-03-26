#ifndef KITTYTURBO_INTERFACE_DEF_H
#define KITTYTURBO_INTERFACE_DEF_H
/*
** This file is machine generated from idltool
** Do not edit
*/ 

#include <exec/types.i>
#include <exec/exec.i>
#include <exec/interfaces.i>

STRUCTURE kittyTurboIFace, InterfaceData_SIZE
	    FPTR IkittyTurbo_Obtain
	    FPTR IkittyTurbo_Release
	    FPTR IkittyTurbo_Expunge
	    FPTR IkittyTurbo_Clone
	    FPTR IkittyTurbo_makeLookupTable
	    FPTR IkittyTurbo_FreeLookupTable
	    FPTR IkittyTurbo_makeContext
	    FPTR IkittyTurbo_FreeContext
	LABEL kittyTurboIFace_SIZE

#endif
