
void list_push_back(struct list *list,struct item *item);
struct blit *list_find(struct list *list,int id);
void list_erase(struct list *list,int id, void (*dispose) (void *ptr));
void list_free(struct list *list, void (*dispose) (void *ptr));

