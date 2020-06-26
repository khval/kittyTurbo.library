

struct star
{
	int x,y,speedx,speedy;
};

struct item
{
	int id;
};

struct blit
{
	int id;
	int screen;
	int x;
	int y;
	int x1;
	int y1;
	int shift;
	void (*fn) (struct blit *);
};

struct list
{
	struct item **items;
	int allocated;
	int used;
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
};

