struct tv{
    char series_name[256];
    int eps; 
    struct tv *next; 
}; 

struct tv *new_show(char *n, int e);
void modify(struct tv *ns, char *name, int ne); 
void watch(struct tv *ns);
struct tv *free_tv(struct tv *ns);

void print_list(struct tv *list); 
struct tv *insert_front(struct tv *list, char *n, int e); 
struct tv *free_list(struct tv *list); 
struct tv *remove_node(struct tv *front, char *n, int e);  
