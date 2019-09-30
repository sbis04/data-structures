#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int nodes;
	cout << "\nEnter vertices: ";
	cin >> nodes;
	vector< pair<int, int> > graph[nodes+1];
	vector<int> dist(nodes+1, INT_MAX);
	set< pair<int, int> > minDis;
	int edges;
	cout << "\nEnter edges: ";
	cin >> edges;
	int t = edges;
	while(t--) {
		int a, b, w;
		cout << "\na\tb\td";
		cin >> a >> b >> w;
		graph[a].push_back(make_pair(b, w));
		graph[b].push_back(make_pair(a, w));
	}
	int src;
	cout << "\nEnter source: ";
	cin >> src;
	minDis.insert(make_pair(0, src));
	dist[src] = 0;

	while(!minDis.empty()) {
		pair<int, int> temp = *(minDis.begin());
		minDis.erase(minDis.begin());

		int u = temp.second;

		for(int i = 0; i < graph[u].size(); i++) {
			pair<int, int> info = graph[u][i];

			int v = info.first;

			int w = info.second;

			if(dist[v] > dist[u] + w) {
				if(dist[v] != INT_MAX) {
					minDis.erase(minDis.find(make_pair(dist[v], v)));
				}
				dist[v] = dist[u] + w;
				minDis.insert(make_pair(dist[v], v));
			}
		}
	}

	for(int i = 1; i < dist.size(); i++) {
		cout << dist[i] << " ";
	}
	return 0;
}