#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"cc.h"
#include"header.h"
#include"que.h"
#include"ini_mat.h"
#include"graph.h"

void free_list(struct graph*);

/* below bfs_cc code uses distance matrix, adj list, graph for bc s=computaion
   if generated graph is not completely connected then it will clear original adj list
   data and reads again from modified .txt file. Then it uses bfs algorithm to compute 
   bc values.*/ 

float* bc_bfs(struct graph* graph,char* filename,bool connected)
{
    int ver;
    bool out;
    ver = graph->no_vertices;
    if(!connected)
    {
        free_list(graph);
        graph = creategraph(ver);
        out = read_file(graph,filename);
        if(out == false)
        {
            printf("\nFile Couldn't be read.\n");
            exit(0);
            
        }
    }
    
    struct Queue* q;
    struct node* p = NULL;
    q = create_queue(graph->no_vertices);
    int **adj,*ptr,*status,ver_1,ver_2,v,w;
    float *bc,**sum;
    sum = sum_mat(ver);
    adj = dist_mat(graph,filename,2);
    bc = (float*)calloc(ver,sizeof(float));
    double time_spent = 0.0;
    clock_t begin =clock();
    for(int k=0;k<ver;k++)
    {
        status = (int*)calloc(ver,sizeof(int));
        enque(q,k);
        status[k] = 1;
        while(!Queue_empty(q))
        {
            v = deque(q);
            status[v] = 2;
            p = graph->adj_list[v];
            while(p)
            {
                int w = p->vertex;
                if(status[w]==2)
                {
                    p=p->next;
                    continue;
                }
                if(sum[k][w]==0)                                  //if (!visited)
                {
                    enque(q,w);
                    status[w] = 1;
                    if(k!=v)
                    {
                        sum[k][w] = sum[k][v];
                        adj[k][w] = adj[k][v]+adj[v][w];
                    }
                    else
                    {
                    sum[k][w] = 1; 
                    adj[k][w] = adj[k][v]+adj[v][w];
                    }
                }
                else if(adj[k][w]==(adj[k][v]+adj[v][w]))        //if(visited but same weight)
                {
                    sum[k][w] = sum[k][w]+sum[k][v];
                }
                else if(adj[k][w]>(adj[k][v]+adj[v][w]))         //if(visited with new small weight)
                {
                    sum[k][w] = sum[k][v];
                    adj[k][w]=(adj[k][v]+adj[v][w]);
                }
                p = p->next;
            }
        }
        free(status);
    }
    //BC Computation....
    for(int k=0;k<ver;k++)     
    {
        for(int i=0;i<ver;i++)
        {
            for(int j=i+1;j<ver;j++)
            {
                if(i!=j && j!=k && k!=i)
                {
                    if(adj[i][j]==(adj[i][k]+adj[k][j]))
                    {
                        bc[k] = bc[k] + (sum[i][k]*sum[k][j])/(sum[i][j]);
                    }
                }
            }
        }
    }
    clock_t end = clock();
    time_spent = (end-begin) / CLOCKS_PER_SEC;
    free_list(graph);
    free(adj);
    printf("\n\nTime spent by BFS : %lf\n",time_spent);
    printf("\nBetweenesss Centrality Using Breadth First Search --> \n");
    return bc;
}

/* This will free adj list part of the graph. */

void free_list(struct graph* graph)
{
    struct node *ptr,*temp;
    for(int i=0;i<graph->no_vertices;i++)
    {
        ptr=graph->adj_list[i];
        while(ptr)
        {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    } 
}