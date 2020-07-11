

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
#include "list.h"

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


void dump_blits(struct context *context);

extern void dispose_blit (void *ptr);
extern void dispose_object (void *ptr);

char *turboplusMultiYes KITTENS_CMD_ARGS
{
	struct context *context = instance -> extensions_context[ instance -> current_extension ];

	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (context -> multi_task_off_count )
	{
		context -> multi_task_off_count --;
		if (context -> multi_task_off_count == 0) Permit();
	}

	return tokenBuffer;
}

char *turboplusMultiNo KITTENS_CMD_ARGS
{
	struct context *context = instance -> extensions_context[ instance -> current_extension ];

	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (context -> multi_task_off_count == 0) Forbid();
	context -> multi_task_off_count ++;

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

char *_turboplusVblWait( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	unsigned int value;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 1:
			value = getStackNum(instance,__stack );
			api.waitvbl();
			return  NULL ;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusVblWait KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusVblWait, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusReserveCheck( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args = instance_stack - data->stack +1;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 1:
			context -> checks_allocated = getStackNum(instance,__stack );

			if (context -> checks) free ( context -> checks );
			context -> checks = (struct check *) malloc( sizeof( struct check ) * context -> checks_allocated ) ;

			return  NULL ;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusReserveCheck KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusReserveCheck, tokenBuffer );
	return tokenBuffer;
}

char *turboplusCheckErase KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	struct context *context = instance -> extensions_context[ instance -> current_extension ];

	if (context -> checks) free ( context -> checks );
	context -> checks = NULL;
	context -> checks_allocated = 0;

	return tokenBuffer;
}

char *_turboplusCheck( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args = instance_stack - data->stack +1;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 4:
			{
				int n;
				int first = getStackNum(instance,__stack-3)-1;
				int last = getStackNum(instance,__stack-2);
				int x = getStackNum(instance,__stack-1);
				int y = getStackNum(instance,__stack);

				popStack( instance, instance_stack - data->stack );

				if ((first>=0)&&(first<last)&&(last <= context -> checks_allocated))
				{
					for (n=first; n<last;n++)
					{
						struct check *c = context -> checks + n;
						if ( x < c -> x ) continue;
						if ( x > c -> x1 ) continue;
						if ( y < c -> y ) continue;
						if ( y > c -> y1 ) continue;
						
						printf("Found\n");

						setStackNum( instance, n+1);
						return  NULL ;
					}
					setStackNum( instance, 0);
				}
				else api.setError(24,data->tokenBuffer);
			}
			return  NULL ;			

		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	popStack( instance, instance_stack - data->stack );
	return  NULL ;
}

char *turboplusCheck KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusCheck, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusSetCheck( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args = instance_stack - data->stack +1;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 5:
			{
				int n = getStackNum(instance,__stack-4)-1;
				if ((context -> checks) && (n>-1) && (n<context -> checks_allocated))		// has checks and is in range
				{
					struct check *c = context -> checks + n;
					c->x = getStackNum(instance,__stack-3);
					c->y = getStackNum(instance,__stack-2);
					c->x1 = getStackNum(instance,__stack-1);
					c->y1 = getStackNum(instance,__stack);
				}
				else 	api.setError(25,data->tokenBuffer);
			}
			break;			

		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}
	popStack( instance, instance_stack - data->stack );


	return  NULL ;
}

char *turboplusSetCheck KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusSetCheck, tokenBuffer );
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

char *_turboplusRawKey( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args = instance_stack - data->stack +1;
	int key;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 1:
			key = getStackNum(instance,__stack );
			if (context -> multi_task_off_count )
			{
				Permit();
				setStackNum(instance, instance -> engine_key_state[key]);
				Forbid();
			}
			else 	setStackNum(instance, instance -> engine_key_state[key]);
			return  NULL ;

		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusRawKey KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusRawKey, tokenBuffer );
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

	if (screen)
	{
		switch (screen ->autoback)
		{
			case 0:
				retroLine( screen, screen -> double_buffer_draw_frame,x0,y0,x1,y1,screen -> ink0 );
				break;

			default:
				retroLine( screen, 0,x0,y0,x1,y1,screen -> ink0 );
				if (screen -> Memory[1])	 retroLine( screen, 1,x0,y0,x1,y1,screen -> ink0 );
				break;
		}
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

char *_turboplusReserveObject( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (args==2)
	{
		int obj_id = getStackNum(instance,__stack-1 );
		struct object *obj = (struct object *)	list_find( &context -> objects, obj_id );

		if (obj == NULL)
		{
			printf("need to allocate a object\n");

			obj = (struct object *) malloc( sizeof(struct object) );
			if (obj)
			{
				printf("add a id and push it to list\n");

				obj -> id = obj_id;
				obj -> elements = NULL;
				obj -> allocated = 0;
				list_push_back( &context -> objects, (struct list *) obj );
			}
		}

		if (obj)
		{
			obj -> allocated = getStackNum(instance,__stack );

			printf("obj -> allocated %d\n", obj -> allocated);

			if (obj -> elements) free( obj -> elements );
			obj -> elements = ( struct element *) malloc( sizeof(struct element ) * obj -> allocated );
		}
	}
	else api.setError(22,data->tokenBuffer);

	popStack( instance, instance_stack - data->stack );
	return NULL;
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

char *_turboplusObjectErase( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (args==1)
	{
		list_erase( &context -> objects, getStackNum(instance,__stack ), dispose_object );
	}
	else api.setError(22,data->tokenBuffer);

	popStack( instance, instance_stack - data->stack );
	return NULL;
}

char *turboplusObjectErase KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusObjectErase, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusLine3d( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args = instance_stack - data->stack +1;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 6:
			{ 
				struct retroScreen *screen = instance -> screens[ instance -> current_screen ];
				double x0,y0,z0,x1,y1,z1;
				double x0_2d,y0_2d,x1_2d,y1_2d;
				double scale = 180.0f;

				if (screen)
				{
					x0 = getStackDecimal(instance,__stack-5 );
					y0 = getStackDecimal(instance,__stack-4 );
					z0 = getStackDecimal(instance,__stack-3 ) + 100.0f;
					x1 = getStackDecimal(instance,__stack-2 );
					y1 = getStackDecimal(instance,__stack-1 );
					z1 = getStackDecimal(instance,__stack ) + 100.0f;

					x0_2d = (x0 * scale / z0) + context->eye3d.x;
					y0_2d = (y0 * scale / z0) + context->eye3d.y;

					x1_2d = (x1 * scale / z1) + context->eye3d.x;
					y1_2d = (y1 * scale / z1) + context->eye3d.y;

					retroLine( screen, screen -> double_buffer_draw_frame,x0_2d,y0_2d,x1_2d,y1_2d,screen -> ink0 );	
				}
			}

			popStack( instance, instance_stack - data->stack );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}

char *turboplusLine3d KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusLine3d, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusEye3d( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args = instance_stack - data->stack +1;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			context->eye3d.x = getStackNum(instance,__stack-1 );
			context->eye3d.y = getStackNum(instance,__stack );
			popStack( instance, instance_stack - data->stack );
			break;
		default:
			popStack( instance, instance_stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}

	return  NULL ;
}


char *turboplusEye3d KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusEye3d, tokenBuffer );
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

void fn_blitLeft(struct blit *blit)
{
	struct retroScreen *screen;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	screen = blit -> instance -> screens[ blit -> screen ];
	if (screen)
	{
		retroScroll( screen, 0, blit -> x, blit -> y, blit -> x1, blit -> y1, blit -> shift,0 );

		if (blit -> shift > 0)
		{
			if (blit -> x == 0) retroBAR( screen, 0, 0, blit -> y, blit-> shift, blit -> y1, 0 );
		}
		else if (blit -> shift < 0 )
		{
			if (blit -> x1 == screen -> realWidth -1  ) retroBAR( screen, 0, blit -> x1 + blit -> shift, blit -> y, blit -> x1, blit -> y1, 0 );
		}
	}

}

void fn_blitUp(struct blit *blit)
{

	struct retroScreen *screen;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	screen = blit -> instance -> screens[ blit -> screen ];
	if (screen) 
	{
		retroScroll( screen, 0, blit -> x, blit -> y, blit -> x1, blit -> y1, 0, blit -> shift );

		if (blit -> shift > 0)
		{
			if (blit -> y == 0) retroBAR( screen, 0, blit -> x, 0, blit -> x1, blit -> shift-1, 0 );
		}
		else if (blit -> shift < 0 )
		{
			if (blit -> y1 == screen -> realHeight -1  ) retroBAR( screen, 0, blit -> x, blit -> y1+blit -> shift+1, blit -> x1, blit -> y1, 0 );
		}
	}

}

char *_turboplusBlitLeft( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 6:
			{
				struct blit blit;
				struct retroScreen *screen;

				blit.instance = instance;
				blit.screen = getStackNum(instance,__stack-5 );
				blit.x = getStackNum(instance,__stack-4 );
				blit.y = getStackNum(instance,__stack-3 );
				blit.x1 = getStackNum(instance,__stack-2 )-1;
				blit.y1 = getStackNum(instance,__stack-1 )-1;
				blit.shift = getStackNum(instance,__stack );
				
				screen = instance -> screens[ blit.screen ];
				if (screen)
				{
					if (blit.x <0) blit.x = 0;
					if (blit.x1 >= screen -> realWidth) blit.x1 = screen -> realWidth -1;

					if (blit.y <0) blit.y = 0;
					if (blit.y1 >= screen -> realHeight) blit.y1 = screen -> realHeight -1;

					fn_blitLeft( &blit );
				}
				else api.setError( 36, data->tokenBuffer );
			}
			break;
		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusBlitLeft KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusBlitLeft, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusBlitStoreLeft( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 7:
			{
				int id = getStackNum(instance,__stack-5 );

				struct blit *blit = (struct blit *) list_find( &context -> blits, id );

				if (blit == NULL)
				{
					blit = (struct blit *) malloc(sizeof(struct blit));
					list_push_back( &context -> blits, (struct item *) blit );
				}

				if (blit)
				{
					struct retroScreen *screen;

					blit -> instance = instance;
					blit -> screen = getStackNum(instance,__stack-6 );
					blit -> id = id;
					blit -> x = getStackNum(instance,__stack-4 );
					blit -> y = getStackNum(instance,__stack-3 );
					blit -> x1 = getStackNum(instance,__stack-2 )-1;
					blit -> y1 = getStackNum(instance,__stack-1 )-1;
					blit -> shift = getStackNum(instance,__stack );
					blit -> fn = fn_blitLeft;

					screen = instance -> screens[ blit -> screen ];
					if (screen)
					{
						if (blit -> x <0) blit -> x = 0;
						if (blit -> x1 >= screen -> realWidth) blit -> x1 = screen -> realWidth -1;

						if (blit -> y <0) blit -> y = 0;
						if (blit -> y1 >= screen -> realHeight) blit -> y1 = screen -> realHeight -1;
					}
				}
				else api.setError( 36, data->tokenBuffer );
			}
			break;
		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );

	return NULL;
}

char *turboplusBlitStoreLeft KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusBlitStoreLeft, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusBlitUp( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 6:
			{
				struct blit blit;
				struct retroScreen *screen;

				blit.instance = instance;
				blit.screen = getStackNum(instance,__stack-5 );
				blit.x = getStackNum(instance,__stack-4 );
				blit.y = getStackNum(instance,__stack-3 );
				blit.x1 = getStackNum(instance,__stack-2 )-1;
				blit.y1 = getStackNum(instance,__stack-1 )-1;
				blit.shift = getStackNum(instance,__stack );
				
				screen = instance -> screens[ blit.screen ];
				if (screen)
				{
					if (blit.x <0) blit.x = 0;
					if (blit.x1 >= screen -> realWidth) blit.x1 = screen -> realWidth -1;

					if (blit.y <0) blit.y = 0;
					if (blit.y1 >= screen -> realHeight) blit.y1 = screen -> realHeight -1;

					fn_blitUp( &blit );
				}
				else api.setError( 36, data->tokenBuffer );
			}
			break;
		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusBlitUp KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusBlitUp, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusBlitStoreUp( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 7:
			{
				int id = getStackNum(instance,__stack-5 );
				struct blit *blit = (struct blit *) list_find( &context -> blits, id );

				if (blit == NULL)
				{
					blit = (struct blit *) malloc(sizeof(struct blit));
					list_push_back( &context -> blits, (struct item *) blit );
				}

				if (blit)
				{
					blit -> instance = instance;
					blit -> screen = getStackNum(instance,__stack-6 );
					blit -> id = id;
					blit -> x = getStackNum(instance,__stack-4 );
					blit -> y = getStackNum(instance,__stack-3 );
					blit -> x1 = getStackNum(instance,__stack-2 )-1;
					blit -> y1 = getStackNum(instance,__stack-1 )-1;
					blit -> shift = getStackNum(instance,__stack );
					blit -> fn = fn_blitUp;
				}
				else api.setError( 36, data->tokenBuffer );
			}
			break;
		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusBlitStoreUp KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusBlitStoreUp, tokenBuffer );
	return tokenBuffer;
}


void dump_blits(struct context *context)
{
	if (context -> blits.items) 
	{
		struct item **blit = context -> blits.items;
		struct item **blit_end = context -> blits.items + context -> blits.used;

		for ( ; blit < blit_end ; blit ++)
		{
			printf("pos %08x, %08x -> id %d\n",blit, *blit, (*blit) -> id);
		}
	}
}


void __multi_blit__(struct context *context, int from, int to)
{
	if (context -> blits.items) 
	{
		struct item **blit = context -> blits.items;
		struct item **blit_end = context -> blits.items + context -> blits.used;
		int delta = to-from+1;

		for ( ; blit < blit_end ; blit ++)
		{
			printf("pos %08x, %08x -> id %d\n",blit, *blit, (*blit) -> id);

			if  ((*blit) -> id < from) continue;
			if  ((*blit) -> id > to) continue;

			printf("call function\n");

			((struct blit *) *blit) -> fn ( (struct blit *) *blit );

			delta --;
			if (delta == 0) break;
		}
	}
}

char *_turboplusMultiBlit( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2: __multi_blit__( context, getStackNum(instance,__stack-1 ), getStackNum(instance,__stack ));
			break;
		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusMultiBlit KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusMultiBlit, tokenBuffer );
	return tokenBuffer;
}


char *_turboplusBlitErase( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 1:
			{
				int id = getStackNum(instance,__stack );
				if (context -> blits.items == NULL) return NULL;
				list_erase( &context -> blits, id, dispose_blit );
			}
			break;
		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusBlitErase KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusBlitErase, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusBlitSpeed( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			{
				struct context *context = instance -> extensions_context[ instance -> current_extension ];
				int id = getStackNum(instance,__stack -1 );

				struct blit *blit = (struct blit *) list_find(&context -> blits, id);
				if (blit)
				{
					blit -> shift = getStackNum(instance,__stack );
				}
			}
			break;
		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusBlitSpeed KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusBlitSpeed, tokenBuffer );
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


char *_turboplusBlitClear( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (args !=1)
	{
		api.dumpStack();

		popStack( instance, instance_stack - data->stack );
		api.setError(22, data -> tokenBuffer);
		return NULL;
	}
	else
	{
		int bits;
		struct retroScreen *screen = instance -> screens[instance -> current_screen];

		if (screen)
		{
			bits = getStackNum( instance,__stack);
			retroAndClear( screen, screen -> double_buffer_draw_frame, 0, 0, screen -> realWidth, screen -> realHeight , ~bits );
		}
	}

	return NULL;
}


char *turboplusBlitClear KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusBlitClear, tokenBuffer );
	setStackNone( instance );
	return tokenBuffer;
}

char *turboplusLeftClick KITTENS_CMD_ARGS
{
	struct context *context = instance -> extensions_context[ instance -> current_extension ];

	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (context -> multi_task_off_count )
	{
		Permit();
		setStackNum(instance, instance -> engine_mouse_key == 1 ? ~0 : 0);
		Forbid();
	}
	else 	setStackNum(instance, instance -> engine_mouse_key == 1 ? ~0 : 0);

	return tokenBuffer;
}


char *_turboplusReserveStars( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (args !=1)
	{
		api.dumpStack();

		popStack( instance, instance_stack - data->stack );
		api.setError(22, data -> tokenBuffer);
		return NULL;
	}
	else
	{
		struct context *context = instance -> extensions_context[ instance -> current_extension ];

		if (context)
		{
			context -> stars_allocated = getStackNum( instance,__stack);
			if (context -> stars)	free( context -> stars );
			context -> stars = (struct star *) malloc( context -> stars_allocated * sizeof(struct star) );
		}
	}

	return NULL;
}

char *turboplusReserveStars KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusReserveStars, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusDefineStar( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("args: %d\n",args);

	if (args !=5)
	{
		popStack( instance, instance_stack - data->stack );
		api.setError(22, data -> tokenBuffer);
		return NULL;
	}
	else
	{
		struct context *context = instance -> extensions_context[ instance -> current_extension ];

		if (context)
		{
			int32 num = getStackNum( instance,__stack-4)-1;

			if ((context -> stars) && (num>=0) && (num <= context -> stars_allocated))
			{
				struct star *star = context -> stars + num;
				star -> x = getStackNum( instance,__stack-3);
				star -> y = getStackNum( instance,__stack-2);
				star -> speedx = getStackNum( instance,__stack-1);
				star -> speedy = getStackNum( instance,__stack);
			}
			else api.setError(34,data -> tokenBuffer);
		}
		popStack( instance, instance_stack - data->stack );
	}

	return NULL;
}

char *turboplusDefineStar KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusDefineStar, tokenBuffer );
	return tokenBuffer;
}

char *turboplusDisplayStars KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	if (context)
	{
		if (context -> stars) 
		{
			int x,y;
			struct star *star;
			struct star *star_end;
			struct retroScreen *screen = instance -> screens[instance -> current_screen];

			if (screen)
			{
				unsigned char *mem = screen -> Memory[ screen -> double_buffer_draw_frame ];
				int sw,sh;

				sw = screen -> realWidth;
				sh = screen -> realHeight;

				star_end = context -> stars + context -> stars_allocated;
				for (  star = context -> stars; star < star_end ; star++)
				{
					retroPixel( screen, mem, star -> x, star -> y, screen -> ink0 );
					x = star -> x + star -> speedx;
					y = star -> y + star -> speedy;

					if (x<0) { x = sw - x; } else if (x>=sw) x -= sw;
					if (y<0) {  y = sh - y;} else if (y>=sh) y -= sh;

					star -> x = x;
					star -> y = y;
				}
			}
		}
	}

	return tokenBuffer;
}

char *turboplusStarsErase KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	struct context *context = instance -> extensions_context[ instance -> current_extension ];

	if (context)
	{
		if (context -> stars)	free( context -> stars );
		context -> stars = NULL;
	}

	return tokenBuffer;
}

void __compute_stars(struct context *context,struct retroScreen *screen,int start, int end)
{
	int i;
	struct star *star = context -> stars + start;

	for (i = start; i <= end ; i++)
	{
		star -> x = (star -> x + star -> speedx) % screen -> realWidth ;
		star -> y = (star -> y + star -> speedy) % screen -> realHeight;
		star ++;
	}
}

char *_turboplusStarsCompute( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("args: %d\n",args);

	if (args !=2)
	{
		popStack( instance, instance_stack - data->stack );
		api.setError(22, data -> tokenBuffer);
		return NULL;
	}
	else
	{
		struct context *context = instance -> extensions_context[ instance -> current_extension ];
		struct retroScreen *screen = instance -> screens[ instance -> current_screen ];

		if (context)
		{
			int32 start = getStackNum( instance,__stack-1)-1;
			int32 end = getStackNum( instance,__stack)-1;

			if ((start<0) || (start > context -> stars_allocated))
			{
				api.setError(34,data -> tokenBuffer);
				popStack( instance, instance_stack - data->stack );
				return NULL;
			}

			if ((end<0) || (end > context -> stars_allocated))
			{
				api.setError(34,data -> tokenBuffer);
				popStack( instance, instance_stack - data->stack );
				return NULL;
			}

			if (context -> stars) 
			{
				__compute_stars( context, screen, start, end );
			}
			else api.setError(34,data -> tokenBuffer);
		}
		popStack( instance, instance_stack - data->stack );
	}

	return NULL;
}

char *turboplusStarsCompute KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusStarsCompute, tokenBuffer );
	return tokenBuffer;
}

void __draw_stars(struct context *context, struct retroScreen *screen)
{
	if (context -> stars) 
	{
		struct star *star;
		struct star *stars_end = context -> stars + context -> stars_allocated ;
		unsigned char *mem = screen -> Memory[ screen -> double_buffer_draw_frame ];
		int ink0 = screen -> ink0;

		for (star = context -> stars; star <= stars_end ; star++)
		{
			retroPixel( screen, mem, star -> x, star -> y, ink0 );
		}
	}
}

char *turboplusStarsDraw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	struct retroScreen *screen = instance -> screens[ instance -> current_screen ];

	if (context) if (screen) __draw_stars( context, screen );

	return tokenBuffer;
}

char *_turboplusStarsSpeed( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("args: %d\n",args);

	switch (args)
	{
		case 4:
			{
				int i,start,end,speedx,speedy;
				start = getStackNum(instance,__stack-3 );
				end = getStackNum(instance,__stack-2 );
				speedx = getStackNum(instance,__stack-1 );
				speedy = getStackNum(instance,__stack );
				popStack(instance,__stack - data->stack );

				if (context -> stars) 
				{
					struct star *star;

					star = context -> stars + start;

					for (i = start; i <= end ; i++)
					{
						star -> speedx = speedx;
						star -> speedy = speedy;
						star ++;
					}
				}
				else api.setError(34,data -> tokenBuffer);
			}
			return NULL;

		default:
			popStack(instance,__stack - data->stack );
			api.setError(22,data->tokenBuffer);
	}
	return NULL;
}

char *turboplusStarsSpeed KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusStarsSpeed, tokenBuffer );
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

char *_turboplusFCircle( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct retroScreen *screen = instance -> screens[instance -> current_screen];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (args==4)
	{
		int x,y,r,c;

		x = getStackNum(instance,__stack-3 );
		y = getStackNum(instance,__stack-2 );
		r = getStackNum(instance,__stack-1 );
		c = getStackNum(instance,__stack );


		if (screen) 
		{
			switch(screen -> autoback)
			{
				case 0:	retroCircle( screen, screen -> double_buffer_draw_frame,x,y,r,c ); 
						break;
				default:
						retroCircle( screen, 0,x,y,r,c ); 
						if (screen -> Memory[1]) retroCircle( screen, 1,x,y,r,c ); 
						break;
			}
		}
	}
	else api.setError(22,data->tokenBuffer);

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusFCircle KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusFCircle, tokenBuffer );
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

void __draw_stars(struct context *context, struct retroScreen *screen);

void fn_int_star VBL_FUNC_ARGS
{
	struct context *context = (struct context *) custom;
	struct retroScreen *screen = context -> int_stars.screens[ context -> int_stars.screen_id ];

	__draw_stars( context, screen ) ;
	__compute_stars( context, screen, 0, context -> stars_allocated );

}

char *_turboplusStarsIntOn( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 1:
			context->int_stars.screens = instance -> screens;
			context->int_stars.screen_id = instance -> current_screen;
			context->int_stars.clear = getStackNum(instance,__stack-1 );
			api.engineAddVblInterrupt( fn_int_star , (void *) context );
			return NULL;

		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusStarsIntOn KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusStarsIntOn, tokenBuffer );
	return tokenBuffer;
}

char *turboplusStarsIntOff KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	api.engineRemoveVblInterrupt( fn_int_star );
	return tokenBuffer;
}

void fn_int_blit VBL_FUNC_ARGS
{
	struct context *context = (struct context *) custom;
	if (context -> int_blit.wait) return;
	__multi_blit__( custom, context -> int_blit.start, context -> int_blit.end );
}

char *_turboplusBlitIntOn( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			context->int_blit.start = getStackNum(instance,__stack-1 );
			context->int_blit.end = getStackNum(instance,__stack );
			api.engineAddVblInterrupt( fn_int_blit , (void *) context );
			break;

		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}


char *turboplusBlitIntOn KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusBlitIntOn, tokenBuffer );
	return tokenBuffer;
}

char *turboplusBlitIntOff KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	api.engineRemoveVblInterrupt( fn_int_blit );

	return tokenBuffer;
}

char *_turboplusFDraw( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct retroScreen *screen = instance -> screens[instance -> current_screen];
	int args =__stack - data->stack +1 ;
	int x0,y0,x1=0,y1=0;

	x0 = instance->xgr;
	y0 = instance->ygr;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			instance->xgr = x1 = getStackNum(instance,__stack-1 );
			instance->ygr = y1 = getStackNum(instance,__stack );

			break;

		case 4:
			stack_get_if_int(instance,__stack-3, &x0 );
			stack_get_if_int(instance,__stack-2, &y0 );
			instance->xgr = x1 = getStackNum(instance,__stack-1 );
			instance->ygr = y1 = getStackNum(instance,__stack );

			if (screen) retroLine( screen, screen -> double_buffer_draw_frame,x0,y0,x1,y1,screen -> ink0 );
			break;

		default:
			api.setError(22,data->tokenBuffer);
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

char *turboplusFDraw KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusFDraw, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusObjectLimit( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 1:
			list_allocate( &context->objects , getStackNum(instance,__stack ));
			return NULL;

		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}


char *turboplusObjectLimit KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusObjectLimit, tokenBuffer );
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

char *_turboplusFPasteIcon( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;
	struct retroScreen *screen;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 3:	if ((instance -> icons) && (screen = instance -> screens[instance -> current_screen]))
				{
					int x = getStackNum(instance,__stack-2 );
					int y = getStackNum(instance,__stack-1 );
					int image = getStackNum(instance,__stack );

					switch (screen -> autoback)
					{
						case 0:	retroPasteIcon( screen, screen -> double_buffer_draw_frame,  instance->icons,x,y,image-1);
								break;
						default:	retroPasteIcon( screen, 0, instance -> icons,x,y,image-1);
								if (screen -> Memory[1]) retroPasteIcon( screen, 1,  instance -> icons,x,y,image-1);
								break;
					}		
				}
				break;
			break;
		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusFPasteIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusFPasteIcon, tokenBuffer );
	return tokenBuffer;
}

char *turboplusF32Icon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusFPasteIcon, tokenBuffer );
	return tokenBuffer;
}

char *turboplusF16Icon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusFPasteIcon, tokenBuffer );
	return tokenBuffer;
}

char *turboplusF16procIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusFPasteIcon, tokenBuffer );
	return tokenBuffer;
}

char *turboplusF32procIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusFPasteIcon, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusXIcon( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 1:
			{
				int image = getStackNum(instance,__stack )-1;
				if (image > instance -> icons -> number_of_frames) break;
				if (image < 0) break;
				setStackNum(instance, (instance -> icons -> frames + image) -> planarXSize );
			}
			return NULL;
	}

	popStack(instance,__stack - data->stack );
	api.setError(22,data->tokenBuffer);

	return NULL;
}

char *turboplusXIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusXIcon, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusYIcon( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 1:
			{
				int image = getStackNum(instance,__stack )-1;
				if (image > instance -> icons -> number_of_frames) break;
				if (image < 0) break;
				setStackNum(instance, (instance -> icons -> frames + image) -> height );
			}
			return NULL;
	}

	popStack(instance,__stack - data->stack );
	api.setError(22,data->tokenBuffer);
	return NULL;
}

char *turboplusYIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusYIcon, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusPlanesIcon( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 1:
			{
				int image = getStackNum(instance,__stack )-1;
				if (image > instance -> icons -> number_of_frames) break;
				if (image < 0) break;
				setStackNum(instance, (instance -> icons -> frames + image) -> numberOfPlains );
			}
			return NULL;
	}

	popStack(instance,__stack - data->stack );
	api.setError(22,data->tokenBuffer);
	return NULL;
}

char *turboplusPlanesIcon KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusPlanesIcon, tokenBuffer );
	return tokenBuffer;
}

char *turboplusCpuInfo KITTENS_CMD_ARGS
{
	ULONG id;
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	GetCPUInfoTags( GCIT_Model, &id , TAG_END );
	setStackNum(instance, 0x10000000 | id);
	return tokenBuffer;
}

char *turboplusMathInfo KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	setStackNum(instance, 882);
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

char *_turboplusMemoryFill( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 3:
			{
				char *start = (char *)  getStackNum(instance,__stack -2 );
				char *end = (char *) getStackNum(instance,__stack -1 );
				struct stringData *txt = getStackString(instance,__stack );
				char *ptr;
				char *sptr;
				int n;

				sptr = &txt -> ptr;

				n=0;
				for (ptr=start; ptr<end;ptr++)
				{
					*ptr = sptr[n];
					n=(n+1)%txt->size;
				}
			}
			break;
		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusMemoryFill KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusMemoryFill, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusBlitIntChange( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args =__stack - data->stack +1 ;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			api.engineLock();
			context->int_blit.start = getStackNum(instance,__stack-1 );
			context->int_blit.end = getStackNum(instance,__stack );
			api.engineUnlock();
			break;

		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack(instance,__stack - data->stack );
	return NULL;
}

char *turboplusBlitIntChange KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusBlitIntChange, tokenBuffer );
	return tokenBuffer;
}

char *_turboplusBlitIntWait( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	struct context *context = instance -> extensions_context[ instance -> current_extension ];
	int args = instance_stack - data->stack +1;

	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 1:
			context -> int_blit.wait = getStackNum(instance,__stack );
			return  NULL;		// don't need to pop stack nothing else to do.

		default:
			api.setError(22,data->tokenBuffer);
	}

	popStack( instance, instance_stack - data->stack );
	return  NULL ;
}

char *turboplusBlitIntWait KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdNormal( _turboplusBlitIntWait, tokenBuffer );
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

char *_turboplusTClip( struct glueCommands *data, int nextToken )
{
	struct KittyInstance *instance = data -> instance;
	int args = instance_stack - data->stack +1;
	int _value,_max;
	proc_names_printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (args)
	{
		case 2:
			_value = getStackNum(instance,__stack-1 );
			_max = getStackNum(instance,__stack );
			popStack( instance, instance_stack - data->stack );
			setStackNum( instance, _value - (_value % _max)) ;
			return NULL;

		default:
			api.setError(22,data->tokenBuffer);
	}
	return  NULL ;
}

char *turboplusTClip KITTENS_CMD_ARGS
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	stackCmdParm( _turboplusTClip, tokenBuffer );
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

