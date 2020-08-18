#include<stdio.h> 
#include<stdlib.h>
#include"header.h"
#include"graph.h"
#include"cc.h"
#define filename "gen_graph.txt"

int main()
{
    struct graph* graph;
    int choice,v;
    float* bc;
    bool status,connected;
    printf("\nEnter no of vertices : ");
    scanf("%d",&v);
    graph = creategraph(v);                                         //create graph structure
    status = read_file(graph,filename);                             //update graph structure from .txt file
    if(status==true)
    {
      connected = dfs_cc(graph,filename);                           //connected component function
      if(connected == false)
      {
        file_write(graph,graph->no_vertices,filename);              //modifies .txt file if found disconnected
      }    
      printf("\nBetweenness Centrality using ...\n");
      printf("1.Floyd Warshall\n2.Breadth First Search\n");
      printf("3.Both\nEnter Value (1,2,3) : ");
      scanf("%d",&choice);
      if(choice == 1 || choice == 3)
      {
        bc = bc_flyd_wrshl(graph,filename,connected);               //bc using Floyd Warshall Algorithm
        print_bc(bc,graph->no_vertices);                            //prints bc values
      }
      if(choice == 2 || choice ==3)
      {
          bc = bc_bfs(graph,filename,connected);                    //bc using BFS Algorithm
          print_bc(bc,graph->no_vertices);                          //prints bc values
      }    
    }
    else
    {
      printf("\nFile Couldn't be read.\n");
      exit(0);
    }
    
    return 0;
}







