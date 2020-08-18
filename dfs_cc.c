#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include"cc.h"
int *cc;
int dfs(struct graph*,int,int,int,int*,int*);
int find_index(int,int,int);
void file_write(struct graph*,int,char*);

bool dfs_cc(struct graph* graph,char* filename)
{
    struct node* ptr;
    bool connected = false;
    int comp_num=0,comp_count,max_comp,max_count = 0;
    int *component,*visited;
    visited  = (int*)calloc(graph->no_vertices,sizeof(int));
    component = (int*)calloc(graph->no_vertices,sizeof(int));
    for(int i=0;i<graph->no_vertices;i++)
    {
        comp_count = 1;
        ptr = graph->adj_list[i];
        if(!visited[i])
        {
            visited[i] = 1;
            component[i] = ++comp_num;
            comp_count = dfs(graph,i,comp_num,comp_count,visited,component);
            if(max_count<comp_count)
            {
                max_count = comp_count;
                max_comp = comp_num;
            }
        }
    }
    /*printf("\nDFS :\n");
    print_cc(graph,visited,component);
    printf("\nmax_count : %d\n No. : %d",max_count,max_comp);
    */
    free(visited);
    if(graph->no_vertices==max_count)
    {
        connected = true;
    }
    else
    {
        giant_cc(component,max_count,max_comp,graph->no_vertices);
        graph->no_vertices = max_count;
    }
    return connected;
}

void giant_cc(int *component,int max_count,int max_comp,int no_vertices)
{
    int j=0;
    cc = (int*)malloc(max_count*sizeof(int));
    for(int i=0;i<no_vertices;i++)
    {
        if(component[i]==max_comp)
        {
            cc[j] = i;
            j++;
        }
    }
/*    printf("\nGiant CC : \n");
    for(int i=0;i<max_count;i++)
    {
        printf(" %d",cc[i]);
    }
    printf("\n");
*/    
}

int dfs(struct graph* graph,int i,int comp_num,int comp_count,int *visited,int* component)
{
    struct node* ptr;
    ptr = graph->adj_list[i];
    while(ptr)
    {
        if(!visited[ptr->vertex])
        {
            visited[ptr->vertex] = 1;
            component[ptr->vertex] = comp_num;
            comp_count++;
            comp_count = dfs(graph,ptr->vertex,comp_num,comp_count,visited,component);
        }
        ptr=ptr->next;
    }
    return comp_count;
}

int find_index(int value,int left,int right)
{
    int mid;
    if((left+right)%2==0)
        mid = (left+right)/2;
    else
        mid = (left+right+1)/2;
    if(value == cc[mid])
    {
        return mid;
    }
    else if(value<cc[mid])
    {
        mid=find_index(value,left,mid-1);
    }
    else
    {
        mid=find_index(value,mid+1,right);
    }
    return mid;
}

void file_write(struct graph* graph,int ver,char* filename)
{
    struct node* pt;
    int index;
    FILE *fptr = fopen(filename,"w");
    for(int q=0;q<ver;q++)
        {
            pt = graph->adj_list[cc[q]];
            while(pt)
            {
                index = find_index(pt->vertex,0,(ver-1));
                if(q<index)
                {
                    fprintf(fptr,"%d %d %d\n",index,q,1);
                }
                pt=pt->next;
            }
        }
    fclose(fptr);    
}

void print_cc(struct graph* graph,int* visited,int* component)
{
    printf("Visited : \n");
    for(int i=0;i<graph->no_vertices;i++)
    {
        printf(" %d",visited[i]);
        visited[i] = 0;
    }
    printf("\nComp. no. : \n");
    for(int i=0;i<graph->no_vertices;i++)
    {
        printf(" %d",component[i]);
    }
    printf("\n");
    return;
}