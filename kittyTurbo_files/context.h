

struct star
{
	int x,y,speedx,speedy;
};

struct item
{
	struct KittyInstance *instance;
	int id;
};

struct xy
{
	int x;
	int y;
};

struct blit
{
	struct KittyInstance *instance;
	int id;
	int screen;
	int x;
	int y;
	int x1;
	int y1;
	int shift;
	void (*fn) (struct blit *);
};

struct element
{
	struct KittyInstance *instance;
	int x;
	int y;
	int color;
	int drawmode;
	void (*fn) (struct element *);
};

struct object
{
	struct element *elements;
	int allocated;
};

struct list
{
	struct item **items;
	int allocated;
	int used;
};

struct int_blit
{
	int start;
	int end;
	int wait;
};

struct context
{
	ULONG multi_task_off_count;

	struct xy eye3d;
	struct star *stars;
	int star_count;
	struct list blits;
	struct list objects;

	struct int_blit int_blit;
};

