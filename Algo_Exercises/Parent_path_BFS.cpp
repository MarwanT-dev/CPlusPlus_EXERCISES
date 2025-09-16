#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
struct Node{
    int value{INT_MIN};
    bool visted{0};
    Node(int value):value(value){}
    Node(){}
};

#include "unweighted_adjacency_list.h"

const int OO = 10000000;

vector<int> BFS_v2(GRAPH &adjList, int start) {
	vector<int> len(adjList.size(), OO);
	queue<int> q;
	q.push(start);
	len[start] = 0;

	for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
		while (sz--) {
			int cur = q.front();
			q.pop();
			for (int neighbour : adjList[cur])
				if (len[neighbour] == OO) {	// never visited
					q.push(neighbour);
					len[neighbour] = cur;
				}
		}
	}
	return len;
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
	vector<int>len = BFS_v2(graph,node);

	for(int i=1;i<len.size();i++){
        cout<<"Path from 0 to "<<i<<' ';
        stack<int> path;
        path.push(i);
        bool exist = 1;
        int parent = i;
        while(path.top()!=0){
            if(len[parent]==OO){
                exist = 0;
                break;
            }
            parent = len[parent];
            path.push(parent);

        }
        if(!exist){
            cout<<"NOT EXIST\n";
            continue;
        }

        while(!path.empty()){
            cout<<path.top()<<' ';
            path.pop();
        }
        cout<<endl;

	}
	return 0;
}


