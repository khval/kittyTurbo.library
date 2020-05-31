

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#ifdef __amigaos4__
#include <proto/exec.h>
#include <proto/retroMode.h>
#endif

#ifdef __linux__
#include <string.h>
#include "os/linux/stuff.h"
#include <retromode.h>
#include <retromode_lib.h>
#endif

#include <amosKittens.h>
#include <amosString.h>
#include "stack.h"

#include <kittyErrors.h>

#include "cmdList.h"
#include "context.h"


#define kittyError instance->kittyError
#define api instance -> api
#define last_var instance -> last_var
#define cmdTmp instance -> cmdTmp

#define alloc_private(x) AllocVecTags( x , AVT_Type, MEMF_PRIVATE, TAG_END )
#define alloc_shared(x) AllocVecTags( x , AVT_Type, MEMF_SHARED, TAG_END )

#define proc_names_printf printf

#ifdef debug
	#warning compiling with debug 
	#define dprintf printf
#else
	#define dprintf(fmt,...)
#endif


char *turboplusMultiYes KITTENS_CMD_ARGS
{
	struct context *context = instance -> extensions_context[ instance -> current_extension ];

	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (context -> multiOffCount )
	{
		context -> multiOffCount --;
		if (context -> multiOffCount == 0) Permit();
	}

	return tokenBuffer;
}

char *turboplusMultiNo KITTENS_CMD_ARGS
{
	struct context *context = instance -> extensions_context[ instance -> current_extension ];

	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (context -> multiOffCount == 0) Forbid();
	context -> multiOffCount ++;

	return tokenBuffer;
}

char *_turboplusLsl_b( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	int ret = 0,shift, mask;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			ret = getStackNum(instance,__stack-1 );
			shift = getStackNum(instance,__stack );
			mask = 0xFF >> shift;

			popStack( instance, instance_stack - data->stack );
			setStackNum( instance, (ret & 0xFFFFFF00) | ((ret & mask) << shift) );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusLsl_b KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusLsl_b, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusLsl_w( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	int ret = 0,shift, mask;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			ret = getStackNum(instance,__stack-1 );
			shift = getStackNum(instance,__stack );
			mask = 0xFFFF >> shift;

			popStack( instance, instance_stack - data->stack );
			setStackNum( instance, (ret & 0xFFFF0000) | ((ret & mask) << shift) );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusLsl_w KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusLsl_w, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusLsl_l( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	int ret = 0,shift;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			ret = getStackNum(instance,__stack-1 );
			shift = getStackNum(instance,__stack );

			popStack( instance, instance_stack - data->stack );
			setStackNum( instance, ret << shift );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusLsl_l KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusLsl_l, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusLsr_b( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	unsigned int ret = 0,shift;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			ret = getStackNum(instance,__stack-1 );
			shift = getStackNum(instance,__stack );

			popStack( instance, instance_stack - data->stack );
			setStackNum( instance, (ret & 0xFFFFFF00) | ((ret & 0xFF)>> shift) );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusLsr_b KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusLsr_b, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusLsr_w( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	unsigned int ret = 0,shift;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			ret = getStackNum(instance,__stack-1 );
			shift = getStackNum(instance,__stack );
			popStack( instance, instance_stack - data->stack );

			popStack( instance, instance_stack - data->stack );
			setStackNum( instance, (ret & 0xFFFF0000) | ((ret & 0xFFFF) >>  shift) );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusLsr_w KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusLsr_w, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusLsr_l( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;

	// hemm.. shift works different with signed values

	unsigned int ret = 0,shift;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			ret = getStackNum(instance,__stack-1 );
			shift = getStackNum(instance,__stack );

			popStack( instance, instance_stack - data->stack );
			setStackNum( instance, (ret >> shift) );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusLsr_l KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusLsr_l, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusLSwap( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;

	// hemm.. shift works different with signed values

	unsigned int value;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 1:
			value = getStackNum(instance,__stack );
			setStackNum( instance, ( ((value & 0xFFFF0000) >> 16) | ((value & 0x0000FFFF) << 16)  ));
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusLSwap KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusLSwap, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusTest_b( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	unsigned int value1,value2;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			value1 = getStackNum(instance,__stack-1 );
			value2 = getStackNum(instance,__stack );
			popStack( instance, instance_stack - data->stack );
			setStackNum( instance, ((value1 ^ value2) & 0xFF) ? 0 : ~0 );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusTest_b KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusTest_b, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusTest_w( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	unsigned int value1,value2;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			value1 = getStackNum(instance,__stack-1 );
			value2 = getStackNum(instance,__stack );
			popStack( instance, instance_stack - data->stack );
			setStackNum( instance, ((value1 ^ value2) & 0xFFFF) ? 0 : ~0 );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusTest_w KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusTest_w, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusTest_l( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	unsigned int value1,value2;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			value1 = getStackNum(instance,__stack-1 );
			value2 = getStackNum(instance,__stack );
			setStackNum( instance, (value1 ^ value2) ? 0 : ~0 );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusTest_l KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusTest_l, tokenBuffer );
	return tokenBuffer;
}

char *turboplusVblWait KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusReserveCheck KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusCheckErase KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusCheck KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusSetCheck KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusResetCheck KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusHitSprZone KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusHitBobZone KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusHitSprCheck KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusRawKey KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *_turboplusRMove( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("args: %d\n",args);

	switch (args)
	{
		case 2:
			instance->xgr += getStackNum(instance,__stack-1 );
			instance->ygr += getStackNum(instance,__stack );
			popStack( instance, instance_stack - data->stack );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusRMove KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusRMove, tokenBuffer );
	setStackNum( instance, 0 );
	return tokenBuffer;
}

char *_turboplusRHome( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("args: %d\n",args);

	switch (args)
	{
		case 2:
			instance->xgr = getStackNum(instance,__stack-1 );
			instance->ygr = getStackNum(instance,__stack );
			popStack( instance, instance_stack - data->stack );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusRHome KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusRHome, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusRDraw( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;
	int x0 ,y0,x1=0,y1=0;
	struct retroScreen *screen = instance -> screens[instance -> current_screen];

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	x0 = instance->xgr;
	y0 = instance->ygr;

	switch (args)
	{
		case 2:
			x1 = x0 + getStackNum(instance,__stack-1 );
			y1 = y0 + getStackNum(instance,__stack );
			instance->xgr = x1;
			instance->ygr = y1;
			break;

		default:
			popStack(instance,__stack - data->stack );
			api.setError(22,data->tokenBuffer);
			return NULL;
	}

	popStack(instance,__stack - data->stack );

	switch (screen ->autoback)
	{
		case 0:
				if (screen) retroLine( screen, screen -> double_buffer_draw_frame,x0,y0,x1,y1,screen -> ink0 );
				break;

		default:
				if (screen)
				{
					retroLine( screen, 0,x0,y0,x1,y1,screen -> ink0 );
					if (screen -> Memory[1])	 retroLine( screen, 1,x0,y0,x1,y1,screen -> ink0 );
				}
				break;
	}

	return NULL;
}

char *turboplusRDraw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusRDraw, tokenBuffer );
	setStackNone(instance);
	return tokenBuffer;
}


char *_turboplusRBox( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;
	int x0 ,y0,x1,y1;
	int t;
	struct retroScreen *screen = instance -> screens[instance -> current_screen];

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("args: %d\n",args);

	if (args==2)
	{
		x0 = instance->xgr;
		y0 = instance->ygr;
		x1 = x0 + getStackNum(instance,__stack-1 );
		y1 = y0 + getStackNum(instance,__stack );

		if (x1<x0) { t = x0; x0 = x1; x1 = t; }
		if (y1<y0) { t = y0; y0 = y1; y1 = t; }

		if (screen) 
		{
			switch (screen -> autoback)
			{
				case 0 :
						retroBox( screen, screen -> double_buffer_draw_frame,x0,y0,x1,y1,screen -> ink0 );
						break;
				default:
						retroBox( screen, 0, x0,y0,x1,y1,screen -> ink0 );
						if (screen -> Memory[1]) retroBox( screen, 1, x0,y0,x1,y1,screen -> ink0 );
						break;
			}
		}

	}
	else api.setError(22,data->tokenBuffer);

	popStack( instance, instance_stack - data->stack );

	return NULL;
}


char *turboplusRBox KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusRBox, tokenBuffer );
	setStackNone(instance);
	return tokenBuffer;
}

char *_turboplusRBar( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;
	int x0 ,y0,x1,y1;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (args==2)
	{
		struct retroScreen *screen = instance -> screens[instance -> current_screen];

		x0 = instance->xgr;
		y0 = instance->ygr;
		x1 = x0+getStackNum(instance,__stack-1 );
		y1 = y0+getStackNum(instance,__stack );

		if (screen)
		{
			switch (screen -> autoback)
			{
				case 0:	retroBAR( screen, screen -> double_buffer_draw_frame, x0, y0, x1, y1,screen -> ink0 );
						break;
				default:	retroBAR( screen, 0,  x0, y0,  x1,  y1,screen -> ink0 );
						if (screen -> Memory[1]) retroBAR( screen, 1,  x0, y0,  x1,  y1,screen -> ink0 );
						break;
			}
		}
	}
	else api.setError(22,data->tokenBuffer);

	popStack( instance, instance_stack - data->stack );
	return NULL;
}

char *turboplusRBar KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusRBar, tokenBuffer );
	return tokenBuffer;
}

char *turboplusReserveObject KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusDefineDraw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusDefineMove KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusDefineStop KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusDefineAttr KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusObjectDraw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusRObjectDraw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusObjectMagDraw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusRObjectMagDraw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusObjectErase KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusLine3d KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusEye3d KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusObjectSave KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusObjectLoad KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBlitStoreLeft KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusMultiBlit KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBlitErase KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBlitSpeed KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBlitLeft KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *_turboplusFPlot( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct retroScreen *screen = instance->screens[instance->current_screen];
	int args =__stack - data->stack +1 ;
	int x,y;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 3:
			x = getStackNum(instance,__stack-2 );
			y =  getStackNum(instance,__stack-1 );

			printf("%d,%d\n",x,y);

			if (screen) retroPixel( screen, screen -> Memory[ screen -> double_buffer_draw_frame ], x,y,getStackNum(instance,__stack ) );
			break;
		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusFPlot KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusFPlot, tokenBuffer );
	setStackNone(instance);
	return tokenBuffer;
}

char *turboplusBlitClear KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusLeftClick KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusReserveStars KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusDefineStar KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusDisplayStars KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusStarsErase KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusStarsCompute KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusStarsDraw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusStarsSpeed KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusStarsClip KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *_turboplusFPoint( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			{
				int x,y;
				x = getStackNum(instance,__stack-1 );
				y = getStackNum(instance,__stack );
				popStack(instance,__stack - data->stack );

				if (instance -> screens[instance -> current_screen])
				{
					setStackNum(instance, retroPoint(instance -> screens[instance -> current_screen], x, y)) ;
				}
				else
				{
					setStackNum(instance, -1) ;
				}
			}
			return NULL;

		default:
			popStack(instance,__stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}
	return NULL;
}

char *turboplusFPoint KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusFPoint, tokenBuffer );
	setStackNone(instance);
	return tokenBuffer;
}

char *turboplusFCircle KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *_turboplusFSqr( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;
	double d = 0.0;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__ ,__LINE__);
	if (args == 1)	d = getStackDecimal(instance,__stack);
	popStack(instance,__stack - data->stack);
	setStackDecimal(instance, sqrt( d ) );
	instance -> kittyStack[__stack].state = state_none;
	return NULL;
}

char *turboplusFSqr KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusFSqr, tokenBuffer );
	return tokenBuffer;
}

char *turboplusStarsIntOn KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusStarsIntOff KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBlitIntOn KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBlitIntOff KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusFDraw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusObjectLimit KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusSetPlanes KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusPlaneOffset KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusPlaneSwap KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusPlaneShiftUp KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusPlaneShiftDown KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusPlaneUpdate KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusFPasteIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusF32Icon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusF16Icon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusF16procIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusF32procIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusXIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusYIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusPlanesIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusCpuInfo KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusMathInfo KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusFPutBlock KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusReserveStaticBlock KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusStaticBlockErase KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBuildStaticBlock KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusFPutStaticBlock KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusSceneBank KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusSceneCheck KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16Check KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusSceneChange KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16Change KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16Draw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16Def KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16Restore KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16Limit KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene32Check KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene32Change KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene32Draw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16View KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene32View KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16Do KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene32Do KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16Top KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene32Top KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16Bottom KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene32Bottom KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16Left KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene32Left KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene16Right KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusScene32Right KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusSceneX KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusSceneY KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusAmosPri KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBitFieldIns KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBitFieldExt KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusHitBobCheck KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusByteHunt KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusWorkbenchOpen KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusSceneLoad KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusMemoryFill KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBlitIntChange KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBlitIntWait KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *_ext_cmd_range( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	int ret = 0,_min,_max;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("args: %d\n",args);

	api.dumpStack();

	switch (args)
	{
		case 3:
			ret = getStackNum(instance,__stack-2 );
			_min = getStackNum(instance,__stack-1 );
			_max = getStackNum(instance,__stack );
	
			if (ret<_min) ret=_min;
			if (ret>_max) ret=_max;
			break;
		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack( instance, instance_stack - data->stack );
	setStackNum( instance, ret);

	return  NULL ;
}

char *turboplusRange KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setCmdTo(e_cmdTo_default);
	stackCmdParm( _ext_cmd_range, tokenBuffer );
	return tokenBuffer;
}

char *turboplusTexp KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBlitUp KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBlitStoreUp KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusIconCheck KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusSceneIconBank KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusTClip KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *_turboplusBetween( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	int ret = 0,_min,_value,_max;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 3:
			_min = getStackNum(instance,__stack-2 );
			_value = getStackNum(instance,__stack-1 );
			_max = getStackNum(instance,__stack );
			ret  = ((_min < _value) && (_value < _max)) ? ~0 : 0 ;
			break;

		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack( instance, instance_stack - data->stack );
	setStackNum( instance, ret);

	return  NULL ;
}

char *turboplusBetween KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusBetween, tokenBuffer );
	return tokenBuffer;
}

char *turboplusScenePalette KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusSceneMaskPalette KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusBankEnd KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

char *turboplusDebug KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.setError(22, tokenBuffer);
	return tokenBuffer;
}

