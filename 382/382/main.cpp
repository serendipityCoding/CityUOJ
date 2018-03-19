#include <iostream>
#include <string.h>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 999999999
using namespace std;
int regulatorNo;
int graph[204][204];
int residue[204][204];
int linkNo;
int nodeNo;
int src, dest;
int srcNo, destNo;
int parent[204];
bool bfs(int s, int t){
    bool visited[204];
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<=dest;v++){
            if(visited[v]==false&&residue[u][v]>0){
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return (visited[t]==true);
}
int maxFlow(){
    int u, v;
    for(int u=0;u<=dest;u++){
        for(int v=0;v<=dest;v++){
            residue[u][v] = graph[u][v];
        }
    }
    int maxFlow=0;
    while (bfs(src,dest)){
        int pathFlow=INF;
        for(int v=dest;v!=src;v=parent[v]){
            u=parent[v];
            pathFlow=min(pathFlow, residue[u][v]);
        }
        for(v=dest;v!=src;v=parent[v]){
            u=parent[v];
            residue[u][v]-=pathFlow;
            residue[v][u]+=pathFlow;
        }
        maxFlow+=pathFlow;
    }
    return maxFlow;
}
int main(){
    while(scanf("%d\n",&regulatorNo)!=EOF){
        memset(graph,0,sizeof(graph));
        //treat regulator[0] as the start point (barisal)
        //treat regulator[2*regulatorNo+1] as the end point dhaka
        for(int i=1;i<=regulatorNo;i++){
            cin>>graph[i][regulatorNo+i];
        }
        cin>>linkNo;
        int u,v,c;
        for(int i=1;i<=linkNo;i++){
            cin>>u>>v>>c;
            graph[u+regulatorNo][v]+=c;
        }
        cin>>srcNo>>destNo;
        src=0;
        dest=2*regulatorNo+1;
        for(int i=1;i<=srcNo;i++){
            cin>>v;
            graph[0][v]=INF;
        }
        for(int i=1;i<=destNo;i++){
            cin>>v;
            graph[v+regulatorNo][dest]=INF;
        }
        cout<<maxFlow()<<endl;
    }
}
