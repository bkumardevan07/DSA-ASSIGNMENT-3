#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include"cc.h"

struct node* createnode(int vertex_no)
{
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->vertex=vertex_no;
    ptr->next=NULL;
    return ptr;
}

struct graph* creategraph(int no_vertices)
{
    struct graph* graph;
    graph = (struct graph*)malloc(sizeof(struct graph));
    graph->no_vertices=no_vertices;
    graph->adj_list= (struct node**)malloc(no_vertices*sizeof(struct node*));

    for(int i=0;i<no_vertices;i++)
    {
        graph->adj_list[i]=NULL;
    }
    return graph;
}

void add_edge(struct graph* graph,int ver_1,int ver_2)
{
struct node* new_node;
new_node = createnode(ver_2);
new_node->next = graph->adj_list[ver_1];
graph->adj_list[ver_1] = new_node;

new_node = createnode(ver_1);
new_node->next = graph->adj_list[ver_2];
graph->adj_list[ver_2] = new_node;
}

void print_graph(struct graph* graph)
{
    struct node* ptr;
    printf("\nGRAPH -\n no.of vertices : %d",graph->no_vertices);
    printf("\n\nADJ LIST -\n");
    for(int i=0;i<graph->no_vertices;i++)
    {
      ptr = graph->adj_list[i];
      printf(" %d -",i);
      while(ptr!=NULL)
      {
          printf(" %d, ",ptr->vertex);
          ptr=ptr->next;
      }
      printf("\n");
    }
}


