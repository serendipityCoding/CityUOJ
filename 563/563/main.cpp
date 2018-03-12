#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
using namespace std;
int padNo;
struct node{
    double freq;
    int x;
    int y;
    int r;
};
node pads[305];
int graph[305][305];
bool overlap(int n1, int n2){
    int d=(pads[n1].x-pads[n2].x)*(pads[n1].x-pads[n2].x)+(pads[n1].y-pads[n2].y)*(pads[n1].y-pads[n2].y);
    if(d<((pads[n1].r+pads[n2].r)*(pads[n1].r+pads[n2].r))) return true;
    return false;
}
bool bfs(int rGraph[305][305],int s,int t,int parent[]){
    bool visited[305];
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v=0;v<padNo+2;v++){
            if (visited[v]==false&&rGraph[u][v]>0){
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return (visited[t]==true);
}
int maxflow(){
    int rGraph[305][305];
    for (int u=0;u<padNo+2;u++)
        for (int v=0;v<padNo+2;v++)
            rGraph[u][v] = graph[u][v];
    int parent[305];
    int maxFlow = 0;
    while (bfs(rGraph,0,padNo+1,parent)){
        int pathFlow=99999999;
        for (int v=padNo+1;v!=0;v=parent[v]){
            int u=parent[v];
            pathFlow=min(pathFlow,rGraph[u][v]);
        }
        for (int v=padNo+1;v!=0;v=parent[v]){
            int u=parent[v];
            rGraph[u][v]-=pathFlow;
            rGraph[v][u]+=pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}
int main(){
    int testCase;
    cin>>testCase;
    for(int m=0;m<testCase;m++){
        cin>>padNo;
        for(int i=0;i<305;i++){
            memset(graph[i],0,sizeof(graph[i]));
        }
        for(int i=1;i<=padNo;i++){
            cin>>pads[i].freq>>pads[i].x>>pads[i].y>>pads[i].r;
            if(pads[i].freq==400.0){
                graph[i][padNo+1]=2;
            }
            if(pads[i].freq==789.0){
                graph[0][i]=2;
            }
        }
        //start node to all the other nodes
        for(int i=1;i<=padNo;i++){
            for(int j=0;j<=padNo;j++){
                if(i==j) continue;
                if(pads[i].freq>pads[j].freq&&overlap(i,j)){
                    graph[i][j]=1;
                }
            }
        }
        int res=maxflow();
        if(res==2) cout<<"Game is VALID"<<endl;
        else cout<<"Game is NOT VALID"<<endl;
    }
}
