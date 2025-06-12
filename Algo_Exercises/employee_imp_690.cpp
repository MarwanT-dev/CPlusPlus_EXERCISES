#include<iostream>
#include<vector>

#include<map>
using namespace std;
struct Employee{
    int id;
    int importance ;
    vector<int>subordinates;
    Employee(int id , int importance , vector<int>subordinates):id(id) , importance(importance),subordinates(subordinates){}
};
typedef map<int,vector<Employee>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, Employee to) {
	graph[from].push_back(to);
}



void dfs(GRAPH &graph, int node, vector<bool> &visited , int &res) {
	visited[node] = true;
    res+=graph[node][0].importance;
	for (auto neighbour : graph[node][0].subordinates) {
		if (!visited[neighbour]) { // Avoid cycling
			dfs(graph, neighbour, visited,res);
		}
	}

}



int getImportance(vector<Employee*>employees , int id){
    GRAPH graph;
    for(auto emp : employees)
        add_directed_edge(graph,emp->id,*emp);

    int res{};
    vector<bool> visted(graph.size());
    dfs(graph,id,visted,res);
    return res;


}
int main() {

    Employee *emp1 = new Employee{101,3,{}};
    Employee *emp2 = new Employee{2,5,{101}};
    Employee *emp3 = new Employee{3,3,{}};
    vector<Employee*>emps{emp1,emp2};
	cout<< getImportance(emps,101);

	return 0;
}
