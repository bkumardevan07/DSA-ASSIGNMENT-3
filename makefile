a.out : main.o bc_bfs.o bc_floyd.o dfs_cc.o dist_mat.o graph_read.o graph_comp.o bc_print.o que.o
	gcc main.o bc_bfs.o bc_floyd.o dfs_cc.o dist_mat.o graph_read.o graph_comp.o bc_print.o que.o 
main.o : main.c header.h graph.h cc.h
	gcc -c main.c 
bc_bfs.o : bc_bfs.c header.h que.h cc.h ini_mat.h graph.h
	gcc -c bc_bfs.c
bc_floyd.o : bc_floyd.c header.h ini_mat.h
	gcc -c bc_floyd.c
dfs_cc.o : dfs_cc.c header.h cc.h
	gcc -c dfs_cc.c 
dist_mat.o : dist_mat.c header.h cc.h 
	gcc -c dist_mat.c 
graph_read.o : graph_read.c header.h graph.h
	gcc -c graph_read.c
graph_comp.o : graph_comp.c header.h cc.h
	gcc -c graph_comp.c 
bc_print.o : bc_print.c header.h
	gcc -c bc_print.c 
que.o : que.c header.h que.h
	gcc -c que.c 
clean:
	rm -f *.o a.out




