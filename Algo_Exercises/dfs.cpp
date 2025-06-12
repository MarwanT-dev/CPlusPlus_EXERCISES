#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int value{INT_MIN};
    bool visted{0};
    Node(int value):value(value){}
    Node(){}
};

#include "unweighted_adjacency_list.h"
vector<int>visted(100);
void DFS(GRAPH &graph,int node ,bool first = 1,int idx = 0 ){


    if((int)graph[node].size()<0||visted[node]==1)
        return ;

    visted[node] = 1;


    for(int i = 0;i<graph[node].size();i++){
        DFS(graph,graph[node][i],0);
    }
    if(!first)
        cout<<node<<' ' ;





}

int main() {
	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph(nodes);	// observe: empty lists

	for (int e = 0; e < edges; ++e) {
		int from, to;
		cin >> from >> to;

		add_directed_edge(graph, from,to);
	}
	int node;cin>>node;
	DFS(graph,node,1);
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

