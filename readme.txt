Instructions - 

1. Generate a graph using erdos renyi graph gen
			command: python3 arg_1 arg_2
	
	arg_1 - number of vertices in graph
	arg_2 - probability of edge formation
    
     NOTE - By default the graph will be saved in file named "gen_graph.txt".
	    The file name can be changed in main.c file under "#define filename <newfilename>".

2. Run the file using 'make' command.
3. The output interface will look like - 

			Enter no of vertices : 
			Betweenness Centrality using ...
			1.Floyd Warshall
			2.Breadth First Search
			3.Both
			Enter Value (1,2,3) : 


	NOTE : The vertice label starts from '0' onwards not '1'
		
 

