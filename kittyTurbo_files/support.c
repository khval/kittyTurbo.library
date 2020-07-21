
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

