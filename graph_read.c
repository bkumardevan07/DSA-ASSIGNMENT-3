#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"header.h"
#include"graph.h"

bool read_file(struct graph* graph,char* filename)
{
    int ver_1,ver_2;
    bool status = true;
    FILE *fptr = fopen(filename,"r");
    if(!fptr)
    {
        status = false;
    }
    while(fscanf(fptr,"%d %d %*d",&ver_1,&ver_2)!=EOF)
    {
        add_edge(graph,ver_1,ver_2);
    }
    fclose(fptr);
    return status;
}    
