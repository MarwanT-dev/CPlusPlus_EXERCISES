#include<iostream>
#include<vector>

#include<map>
using namespace std;

typedef map<int,vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to) {
	graph[from].push_back(to);
}

void print_adjaceny_matrix(GRAPH &graph) {
	int nodes = graph.size();
	for (int from = 0; from < nodes; ++from) {
		cout << "Node " << from << " has neighbors: ";
		for (int to = 0; to < (int) graph[from].size(); ++to)
			cout << graph[from][to] << " ";
		cout << "\n";
	}
}

void dfs(GRAPH &graph, int node, vector<bool> &visited , vector<int>&res) {
	visited[node] = true;

	for (int neighbour : graph[node]) {
		if (!visited[neighbour]) { // Avoid cycling
			res.push_back(neighbour);
			dfs(graph, neighbour, visited,res);
		}
	}

}



vector<int> KillProcess(vector<int>&pid , vector<int>ppid , int kill){
    GRAPH graph;
    for(int i=0;i<pid.size();i++)
        add_directed_edge(graph,ppid[pid[i]],pid[i]);

    vector<int> res;
    res.push_back(kill);
    vector<bool> visted(graph.size());//u should make the size depends on the biggest id so use unordered set instead
    dfs(graph,kill,visted,res);
    return res;


}
int main() {

    vector<int> pid = {6,3,4,1,0,2,5};
    vector<int> ppid = {5,5,5,2,1,0,2};

	vector<int> res = KillProcess(pid,ppid,5);
    for(int val : res)
        cout<<val<<' ' ;
	return 0;
}
/*
 7 9
 2 0
 0 1
 1 4
 4 3
 3 1
 1 0
 0 3
 5 6
 6 6


Output
Reachable set of node 0
	We can reach 1
	We can reach 4
	We can reach 3
Reachable set of node 1
	We can reach 4
	We can reach 3
	We can reach 0
Reachable set of node 2
	We can reach 0
	We can reach 1
	We can reach 4
	We can reach 3
Reachable set of node 3
	We can reach 1
	We can reach 4
	We can reach 0
Reachable set of node 4
	We can reach 3
	We can reach 1
	We can reach 0
Reachable set of node 5
	We can reach 6
Reachable set of node 6

 */


