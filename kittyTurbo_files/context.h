

struct star
{
	int x,y,speedx,speedy;
};

struct item
{
	struct KittyInstance *instance;
	int id;
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
//--	MultiTasking --

	ULONG multiOffCount;

//--	Stars --

	struct star *stars;
	int star_count;

//--	Blits --

	struct list blits;

//--   Object --

	struct list objects;

//-- interrupts --

	struct int_blit int_blit;
};

