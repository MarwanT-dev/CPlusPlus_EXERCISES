#include<iostream>
#include<vector>
using namespace std;
#include "unweighted_adjacency_list.h"

void print_chain(GRAPH &graph,int from){
    cout<<from<<' ';
    if(graph[from].size()>0)
    print_chain(graph,graph[from][0]);

}
int main() {
	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph(nodes);	// observe: empty lists

	for (int e = 0; e < edges; ++e) {
		int from, to;
		cin >> from >> to;
		add_directed_edge(graph, from, to);
	}
	int from;cin>>from;
	print_chain(graph,from);
	return 0;
}

/*

6 7
2 1 10
2 5 20
2 0 77
2 3 33
0 5 45
1 4 60
5 4 10

Output
Node 0 has neighbors: (to 5 cost 45)
Node 1 has neighbors: (to 4 cost 60)
Node 2 has neighbors: (to 1 cost 10) (to 5 cost 20) (to 0 cost 77) (to 3 cost 33)
Node 3 has neighbors:
Node 4 has neighbors:
Node 5 has neighbors: (to 4 cost 10)

 */

