#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include"cc.h"
float** sum;

float** sum_mat(int ver)
{
    sum =(float**)malloc(ver*sizeof(float*));
    for(int q=0;q<ver;q++)
    {
        sum[q] = (float*)calloc(ver,sizeof(float));
    }
    return sum;
}

int** dist_mat(struct graph* graph,char* filename,int c)
{
    int **adj,*ptr,len,ver;
    struct node* pt;
    ver = graph->no_vertices;
    len = sizeof(int*)*ver + sizeof(int)*ver*ver;
    adj = (int**)malloc(len);
    ptr = (int*)(adj+ver);
    for(int p=0;p<ver;p++)
    {
        adj[p] = (ptr + ver*p);    
    }
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
            if(i==j)
            {
                adj[i][j] = 0;
            }
            else
            {
                adj[i][j]=INF;
                if(c==1)
                {
                    sum[i][j]=1;
                }    
            }
            
        }
    }

    int ver_1,ver_2;
    FILE *f = fopen(filename,"r");
    for(int i=0;i<graph->no_vertices;i++)
    {
        for(int j=0;j<graph->no_vertices;j++)
        {
            fscanf(f,"%d %d %*d",&ver_1,&ver_2);
            adj[ver_1][ver_2] = 1;
            adj[ver_2][ver_1] = 1;
        }
    }
    fclose(f);
    return adj;
}