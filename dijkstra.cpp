#include <bits/stdc++.h>
using namespace std;
void djk(vector<pair<int,int>> graph[],int nodes,int src,int end)
{
	bool visit[nodes];				// Initializing visited array

	memset(visit,false,sizeof(visit));		// filling visited array with FALSE

	vector<int> dist(nodes);			// initializing distance vector
	fill(dist.begin(),dist.end(),INT_MAX);
	dist[src]=0;				// distance of source node is 0


	multiset<pair<int,int>> m;		// using multiset as queue


	m.insert({0,src});			// Insertint the source node
	while(!m.empty())
	{
		pair<int,int> p=*m.begin();
		m.erase(*m.begin());
		int v=p.second;
		int w=p.first;
		if(visit[v]==false){   		// If the nodes are unvisited then we visit it
			visit[v]=true;

			for(int i=0;i<graph[v].size();++i){ 	// We visit the current nodes neighbouring nodes
				int q=graph[v][i].first;
				int r=graph[v][i].second;

				if(dist[v]+r < dist[q]){   //  We check that if distance of current node plus its weight is less than distance of its 						neighbouring node than we update neighbouring nodes distance


				  dist[q]=dist[v]+r;
				  m.insert({dist[q],q});
				}
			}
		}
		
	}
	if(dist[end]==INT_MAX)
	  cout<<"NONE"<<endl;
	else
	  cout<<dist[end]<<endl;
}
int main() {
   int n,m,ti,src,end; // Here we initiialize nodes ,edges , source and end node.

   	cin>>n>>m>>src>>end;
   	vector<pair<int,int>> graph[n]; // Here we initialize the adjacency list using a 2D vector
   	for(int i=0;i<m;++i){
   		int x,y;
   		cin>>x>>y>>ti;
   		x--;						// Here we take input for each vertex and edges
   		y--;
   		graph[x].push_back(make_pair(y,ti));
   		graph[y].push_back(make_pair(x,ti));
   	}
   	djk(graph,n,src-1,end-1);
	return 0;
}
