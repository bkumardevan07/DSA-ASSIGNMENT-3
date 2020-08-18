#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void print_bc(float* bc,int no_ver)
{
    for(int q=0;q<no_ver;q++)
    {
        printf("Ver - %d - %.2f\n",q,bc[q]);
    }
}