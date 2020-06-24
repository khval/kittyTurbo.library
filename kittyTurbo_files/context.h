

struct star
{
	int x,y,speedx,speedy;
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
};

struct context
{
//--	MultiTasking --

	ULONG multiOffCount;

//--	Stars --

	struct star *stars;
	int star_count;

//--	Blits --

	struct blit **blits;
	int blits_allocated;
	int blits_used;
};
