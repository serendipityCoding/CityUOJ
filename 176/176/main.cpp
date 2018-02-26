#include <iostream>
#include <stdio.h>
#include <cstring>
#include <limits.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iomanip>
using namespace std;
int nodeNo, src, dest, edgeNo;
int graph[105][105];
int rGraph[105][105];
int parent[105];
bool bfs(int s, int t)
{
    bool visited[nodeNo];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v=0; v<nodeNo; v++){
            if (visited[v]==false && rGraph[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}
int fordFulkerson(int s, int t)
{
    int u, v;
    for (int u = 0; u < nodeNo; u++)
        for (v = 0; v < nodeNo; v++)
            rGraph[u][v] = graph[u][v];
    int max_flow = 0;
    while (bfs(s, t)){
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v]){
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v=t; v != s; v=parent[v]){
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main(){
    int count=0;
    while(cin>>nodeNo){
        getchar();
        if(nodeNo==0) break;
        scanf("%d %d %d\n",&src,&dest,&edgeNo);
        for(int i=0;i<nodeNo;i++){
            memset(graph[i],0,sizeof(graph[i]));
            memset(rGraph[i],0,sizeof(rGraph[i]));
        }
        memset(parent,-1,sizeof(parent));
        for(int i=0;i<edgeNo;i++){
            int n1, n2, l;
            scanf("%d %d %d\n",&n1, &n2, &l);
            n1--;
            n2--;
            graph[n1][n2]+=l;
            graph[n2][n1]=graph[n1][n2];
        }
        cout<<"Network "<<(++count)<<endl;
        cout<<"The bandwidth is "<<fordFulkerson(src-1,dest-1)<<"."<<endl<<endl;
    }
}
