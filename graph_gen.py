import networkx as nx
import random 
import sys
n=int(sys.argv[1])
p=float(sys.argv[2])
G = nx.erdos_renyi_graph(n,p) 
file = open("gen_graph.txt","w")
l = list(range(1,88))
for edge in G.edges:
	str_1 = str(edge[0])
	str_2 = str(edge[1])
	st = str_2+" "+str_1+" "+str(random.choice(l))
	file.write(st+"\n")
file.close()

