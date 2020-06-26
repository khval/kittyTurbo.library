
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

#include "context.h"

void list_push_back(struct list *list,struct item *item)
{
	struct item **items;

	if ((list -> used +1) > list -> allocated)
	{
		int new_allocated = list -> allocated +10;

		items = (struct item **) malloc( sizeof(struct item *)  * new_allocated );
		if (items)
		{
			if (list -> items)
			{
				memcpy(items, list -> items, sizeof(struct item *) * list -> used );
				free(list -> items);
			}
			list -> items = items;
			list -> allocated = new_allocated;
			list -> items[ list -> used ] = item;
			list -> used ++;
		}
	}
	else
	{
		list -> items[ list -> used ] = item;
		list -> used ++;	
	}
}


struct blit *list_find(struct list *list,int id)
{
	int i;
	struct item **items = list -> items;
	if (items == NULL) return NULL;
	for (i=0;i<list -> used;i++)
	{
		if (items[i]->id == id) return items[i];
	}
	return NULL;
}

void list_free(struct list *list)
{
	int i;
	struct item **items = list -> items;

	if (items)
	{
		for (i=0;i<list -> used;i++)
		{
			free(items[i]);
			items[ i] = NULL;
		}
		free( items );
		list -> items = NULL;
	}
}

void list_erase(struct list *list,int id)
{
	int i;
	struct item **items = list -> items;
	for (i=0;i<list -> used;i++)
	{
		if (items[i]->id == id) 
		{
			free(items[i]);
			if (i)
			{
				i++;
				for ( ; i < list -> used;i++)
				{
					items[i-1] = items[i];
				}				
			}
			list -> used--;
			items[ list -> used ] = NULL;
			break;
		}
	}
}
