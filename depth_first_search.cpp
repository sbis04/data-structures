//c++ program for Depth First Search traversal
#include <iostream>
#include <vector>
using namespace std;

vector <int> adj[100];			

bool visited[100];					//Initialising the visited vector

void dfs(int s) {			
        visited[s] = true;

		cout<<s<<" ";			        //Printing node
	for(int i = 0;i < adj[s].size();++i){	        //If the nodes are unvisited then we visit the neighbouring node		
		if(visited[adj[s][i]] == false)	
			dfs(adj[s][i]);		

        }
}

void initialize() {					//Initialize all nodes as not visited
        for(int i = 0;i < 100;++i)
         visited[i] = false;
}

int main() {
        int nodes, edges, x, y;
	cout << "Enter the number of nodes\n" ;
        cin >> nodes;                       		//Number of nodes
	cout << "Enter the number of edges\n" ;
        cin >> edges;                       		//Number of edges
        for(int i = 0;i < edges;++i) {
        	 cin >> x >> y;    			//Undirected Graph 
         	adj[x].push_back(y);                    //Edge from vertex x to vertex y
         	adj[y].push_back(x);                    //Edge from vertex y to vertex x
        }

        initialize();                           	//Initialize all nodes as not visited

	cout<<"Nodes are visited in the order\n";
        for(int i = 1;i <= nodes;++i) {
         if(visited[i] == false)     {
             dfs(i);
         }
}
        
        return 0;
    }
