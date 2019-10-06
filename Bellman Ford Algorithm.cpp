#include <bits/stdc++.h>
#define ll long long int
using namespace std;
//Bellman ford
const ll INF=1e9;
struct weiedge
{
    int a;//Source
    int b;//To
    int weight;
};
int main()
{
    ll N,M;//number of vertex and edges respectively
    ll wei;//weight of each edge
    ll from,to;
    cin >> N >> M;
    ll dis[N+1];//shortest distance of each node from source
    ll par[N+1];//parent of each node to reconstruct the path
    par[1]=-1;//no parent of source node
    for(ll i=2;i<=N;++i)
        dis[i]=INF;
    dis[1]=0;
    weiedge edge[M];
    for(int i=0;i<M;++i)
    {
        cin >> from >> to >> wei;
        edge[i].a=from;
        edge[i].b=to;
        edge[i].weight=wei;
    }
    bool state=false;
    /*since at most n-1 phases are required
    so if there is no change during the current phase
    so we can exit from the algorithm*/
    for( ; ; )
    {
        state=false;
        for(int j=0;j<M;++j)
        {
            if(dis[edge[j].a]+edge[j].weight<dis[edge[j].b])
                {dis[edge[j].b]=dis[edge[j].a]+edge[j].weight;
                //To reconstruct the shortest path for a vertex
                //maintain a parent array for each vertex
                par[edge[j].b]=edge[j].a;
                state=true;
                }
        }
    if(!state)
        break;
    }
    //shortest distance for each vertex from source
    //if it is not reachable from source then print 1e9
    for(int i=2;i<=N;++i)
        cout << dis[i] << " ";
    cout << endl;
    //reconstructing the path for a particular vertex
    ll t;
    cout << "Enter vertex:";
    cin >> t;
    if(dis[t]==INF)
        cout << "No path from source" << endl;
    else
    {
        vector<ll> path;
        for(ll cur=t;cur!=-1;cur=par[cur])
            path.push_back(cur);
        reverse(path.begin(),path.end());
        for(ll i=0;i<path.size();++i)
            cout << path[i] << " ";
        cout << endl;
    }
}
