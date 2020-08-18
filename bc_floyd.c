#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"header.h"
#include"ini_mat.h"

/*below floyd wrshall bc code uses distance matrix and graph to compute
  bc values. First it will form distance matrix from modified .txt file
  and then uses floyd warshall algorithm to compute bc values.*/

float* bc_flyd_wrshl(struct graph* graph,char* filename,bool connected)
{
    int ver,**adj;
    float *bc,**sum;
    ver = graph->no_vertices;
    sum = sum_mat(ver);                                //will store number of shortest paths among vertices
    adj = dist_mat(graph,filename,1);                  //will store minimum path distance between vertices 
    bc = (float*)calloc(ver,sizeof(float));
    double time_spent =0.0;
    clock_t begin = clock();

    //Floyd Warshall Algorithm...
    for(int k=0;k<ver;k++)        
    {
        for(int i=0;i<ver;i++)
        {
            for(int j=0;j<ver;j++)
            {
                if(i!=j && j!=k && k!=i)
                {
                    if(adj[i][j]>(adj[i][k]+adj[k][j]))
                    {                                               
                        adj[i][j]=(adj[i][k]+adj[k][j]);
                        sum[i][j]=sum[i][k]*sum[k][j];
                    }
                    else if(adj[i][j]==(adj[i][k]+adj[k][j]))
                    {
                        sum[i][j] = sum[i][j] + sum[i][k]*sum[k][j];
                    }
                }
            }
        }
    }
        
    //BC Computation...
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
    time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
    free(sum);
    free(adj);
    printf("\n\nTime spent by Floyd Warshall : %lf\n",time_spent);
    printf("\nBetweenesss Centrality Using Floyd Warshall --> \n");
    return bc;
}
