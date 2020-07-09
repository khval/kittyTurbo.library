

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

struct check
{
	int x;
	int y;
	int x1;
	int y1;
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

struct int_stars
{
	struct retroScreen **screens;
	int screen_id;
	int clear;
};

struct context
{
	ULONG multi_task_off_count;

	struct xy eye3d;

	struct star *stars;
	int stars_allocated;

	struct check *checks;
	int checks_allocated;

	struct list blits;
	struct list objects;

	struct int_blit int_blit;
	struct int_stars int_stars;
};

