/*  This program is based on the algorithm of ford fulkerson  which is nothing but find out the maximum flow in thr graph from one source vertex to sink vertex */

// this program is basically designed for a graph but u can use it by changing the matrix in the main function as well as the number of vertex in your graph

// In this graph no of vertex v define as 6 in line 11

#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#include<queue>
#define v 8       // total number of vertex  update accn to your graph

using namespace std;


// function which can search a suitable path which reach from source to sink vertex and return true if reached else return false and also store the parents of each node which come in the path


int bfs(int rgraph[v][v],int s,int t,int parent[v])
{
    bool visited[v];
    memset(visited,0,sizeof(visited));      // initialised all

    queue<int> Queue;         // Creating queue which is integer type and named as Queue
    Queue.push(s);
    visited[s]=true;           // if we reach a vertex then mark it visited sothat we not come to it again
    parent[s]=-1;              // parent of source vertex is alway -1
    //BFS loop

    while(!Queue.empty())       // doing BFS to searching path and update parents accordingly
    {
        int u=Queue.front();
        Queue.pop();

        for(int k=0;k<v;k++)
        {
            if(visited[k]==false && rgraph[u][k]>0)
            {
                Queue.push(k);
                parent[k]=u;
                visited[k]=true;
            }
        }
    }
//if we reach the sink element in graph
return visited[t]==true;
}

// #########################################################################################################################################################################


// main function which find out the maximum flow in the graph


int ford_fulkerson(int graph[v][v],int s,int t)         // s is the source vertex and t is the destination vertex
{
    int rgraph[v][v],u,x,y;                      // residual graph  which store the graph after using some path

    int parent[v];
    int max_flow=0;   // store the max flow
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            rgraph[i][j]=graph[i][j];               // initially value of residual is same as original graph
        }
    }

    while(bfs(rgraph,s,t,parent))     // this will find the path and minimum path_flow and update the residual graph and max_flow
    {
        int path_flow=INT_MAX;
		for (x=t; x!=s; x=parent[x])
		{
			u = parent[x];
			path_flow = min(path_flow, rgraph[u][x]);
		}

		for(int y=t; y!=s ;y=parent[y] )
        {
            u=parent[y];
            rgraph[u][y]=rgraph[u][y]-path_flow;
            rgraph[y][u]=rgraph[y][u]+path_flow;
        }

        max_flow=max_flow+path_flow;

    }

return max_flow;
}


// Main function

int main()
{
    // update this matrix According to your graph and also update the v which is define above my graph has 5 vertex so our matrix 5*5 and v is 5

    int graph[v][v]={ {0,3,0,5,0,2,0,0},{0,0,2,0,0,0,0,4},{0,0,0,0,2,0,0,5}, {0,0,0,0,4,3,0,0}, {0,5,0,0,0,0,0,0},{0,0,0,0,0,0,4,0},{0,0,0,0,2,0,0,3},{0,0,0,0,0,0,0,0} };
    int max_flow=ford_fulkerson(graph,0,7);

    cout<<"Maximum flow of the graph is  : "<<max_flow<<endl;

    // for this graph max_flow is 9 but for your graph it may vary accn to the nature of the graph
}


// contributed by Mohit Raj  IIIT Kalyani
