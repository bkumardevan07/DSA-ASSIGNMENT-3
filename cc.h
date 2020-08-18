//Connected Component Accessories...

#ifndef GRAPH
#define GRAPH
typedef  struct node** ADJ_LIST;

struct graph
{
    int no_vertices;
    ADJ_LIST adj_list;
};
#endif

#ifndef NODE
#define NODE
struct node
{
    int vertex;
    struct node* next;
};
#endif


#define INF 30000
void giant_cc(int*,int,int,int);
void print_cc(struct graph*,int*,int*);
void file_write(struct graph*,int,char*);

