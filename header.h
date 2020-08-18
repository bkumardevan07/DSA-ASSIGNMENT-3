#include<stdbool.h>
#ifndef GRAPH
#define GRAPH
typedef  struct node ** ADJ_LIST;

struct graph
{
    int no_vertices;
    ADJ_LIST adj_list;
};

#endif

bool read_file(struct graph*,char*);            //will form graph from given filename and returns status if successful or not
bool dfs_cc(struct graph*,char*);               //will check and if necessary extract giant component of graph, input filename and graph
float* bc_flyd_wrshl(struct graph*,char*,bool); //calculate bc values, takes graph, filename and boolean connected, will return bc values  
float* bc_bfs(struct graph*,char*,bool);        //calculate bc values, takes graph, filename and boolean connected, will return bc values  
void print_bc(float*,int);                      //will print obtained bc values