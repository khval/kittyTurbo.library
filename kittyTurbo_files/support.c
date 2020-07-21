
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

#include <amosKittens.h>
#include "context.h"
#include "support.h"

void __past_icon__(struct context *context,  struct retroScreen *screen, int x, int y , int image)
{
	switch (screen -> autoback)
	{
		case 0:	retroPasteIcon( screen, screen -> double_buffer_draw_frame, context -> scene_icon,x,y,image);
				break;

		default:	retroPasteIcon( screen, 0, context -> scene_icon,x,y,image);
				if (screen -> Memory[1]) retroPasteIcon( screen, 1,  context -> scene_icon,x,y,image);
				break;
	}
}

void _draw_map16(struct context *context,struct retroScreen *screen, int px,int py,int mx,int my,int w,int h)
{
	int x,y,ppx,ppy;
	int oy;

	for (y = 0; y<h;y++)
	{
		ppy = (y << 4) + py;
		oy = y + my;

		for (x = 0; x<w;x++)
		{
			ppx = ( x << 4) + px;

			__past_icon__( context,  screen,  ppx,  ppy , *((char *) context -> scene_memory + x + mx + (oy * context -> scene_width)  ) );
		}
	}
}

void _draw_map32(struct context *context,struct retroScreen *screen, int px,int py,int mx,int my,int w,int h)
{
	int x,y,ppx,ppy;
	int oy;

	for (y = 0; y<h;y++)
	{
		ppy = (y << 5) + py;
		oy = y + my;

		for (x = 0; x<w;x++)
		{
			ppx = ( x << 5) + px;

			__past_icon__( context,  screen,  ppx,  ppy , *((char *) context -> scene_memory + x + mx + (oy * context -> scene_width)  ) );
		}
	}
}

