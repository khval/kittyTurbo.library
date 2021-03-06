#ifndef KITTYTURBO_INTERFACE_DEF_H
#define KITTYTURBO_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 53.6.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef LIBRARIES_KITTYTURBO_H
#include <libraries/kittyTurbo.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct kittyTurboIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct kittyTurboIFace *Self);
	ULONG APICALL (*Release)(struct kittyTurboIFace *Self);
	void APICALL (*Expunge)(struct kittyTurboIFace *Self);
	struct Interface * APICALL (*Clone)(struct kittyTurboIFace *Self);
	char * APICALL (*makeLookupTable)(struct kittyTurboIFace *Self);
	void APICALL (*FreeLookupTable)(struct kittyTurboIFace *Self, void * table);
	void * APICALL (*makeContext)(struct kittyTurboIFace *Self);
	void APICALL (*FreeContext)(struct kittyTurboIFace *Self, void * table);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* KITTYTURBO_INTERFACE_DEF_H */
