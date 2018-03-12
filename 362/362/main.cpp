#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <math.h>
#define INF 999999999
using namespace std;
int width, height;
int defenderNo, dist;
struct Node{
    int x;
    int y;
};
Node defender[102];
int edges[102][102];
int ioEdges[204][204];
int getDistance(Node n1, Node n2){
    return (n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y);
}
bool bfs(int rGraph[204][204], int s, int t, int parent[]){
    bool isVisited[204];
    memset(isVisited, 0, sizeof(isVisited));
    queue <int> q;
    q.push(s);
    isVisited[s] = true;
    parent[s] = -1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v=0; v<defenderNo*2+2; v++){
            if (isVisited[v]==false && rGraph[u][v] > 0){
                q.push(v);
                parent[v] = u;
                isVisited[v] = true;
            }
        }
    }
    return (isVisited[t] == true);
}
int maxflow(){
    int residue[204][204];
    //check if there is any defender overlap with the south border
    for(int i=1;i<=defenderNo;i++){
        if(defender[i].y<=dist){
            ioEdges[i*2-1][0]=1;
            ioEdges[0][i*2-1]=1;
        }
        if((width-defender[i].y)<=dist){
            ioEdges[i*2][2*defenderNo+1]=1;
            ioEdges[2*defenderNo+1][i*2]=1;
        }
    }
    //set in out edge
    //for node[i], ioEdges[i*2-1][i*2] means i-in --> i-out has capacity 1
    for(int i=1;i<=defenderNo;i++){
        ioEdges[i*2-1][i*2]=1;
    }
    //if two node (i, j) are connected
    //set i-out --> j-in and j-out --> i-in
    for(int i=1;i<=defenderNo;i++){
        for(int j=(i+1);j<=defenderNo;j++){
            int d=getDistance(defender[i],defender[j]);
            if(d<=(4*dist*dist)){
                ioEdges[i*2][j*2-1]=INF;
                ioEdges[j*2][i*2-1]=INF;
            }
        }
    }
    //create residue graph
    for(int i=0;i<defenderNo*2+2;i++){
        for(int j=0;j<defenderNo*2+2;j++){
            residue[i][j]=ioEdges[i][j];
        }
    }
    int maxFlow=0;
    int parent[204];
    while(bfs(residue, 0, defenderNo*2+1, parent)){
        int pathFlow = INF;
        int u;
        for (int v=defenderNo*2+1; v!=0; v=parent[v]){
            u = parent[v];
            pathFlow = min(pathFlow, residue[u][v]);
        }
        for (int v=defenderNo*2+1; v != 0; v=parent[v]){
            u = parent[v];
            residue[u][v] -= pathFlow;
            residue[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}
//bool getPath(){
//    //visited[0] is the south, visited[defenderNo+1] is the north
//    bool visited[102];
//    memset(visited,false,sizeof(visited));
//    visited[0]=true;
//    queue <int> q;
//    q.push(0);
//    while(!q.empty()){
//        int fromNode=q.front();
//        q.pop();
//        if(fromNode==(defenderNo+1)) return true;
//        for(int i=0;i<=(defenderNo+1);i++){
//            if(edges[fromNode][i]==1){
//                if(visited[i]==false){
//                    q.push(i);
//                    visited[i]=true;
//                }
//            }
//        }
//    }
//    if(visited[defenderNo+1]==true) return true;
//    else return false;
//}
int main(){
    int count=1;
    while(cin>>height>>width>>defenderNo>>dist){
        if(height==0&&width==0&&defenderNo==0&&dist==0) break;
        for(int i=0;i<102;i++){
            //memset(edges[i],0,sizeof(edges[i]));
            memset(ioEdges[i],0,sizeof(ioEdges[i]));
        }
        //the north and south border are also nodes
        for(int i=1;i<=defenderNo;i++){
            cin>>defender[i].x>>defender[i].y;
        }
//        //check if there is any defender overlap with the south border
//        for(int i=1;i<=defenderNo;i++){
//            if(defender[i].y<=dist){
//                edges[i][0]=1;
//                edges[0][i]=1;
//            }
//            if((width-defender[i].y)<=dist){
//                edges[i][defenderNo+1]=1;
//                edges[defenderNo+1][i]=1;
//            }
//        }
        //check whether defender and defender are overlapped
//        for(int i=1;i<=defenderNo;i++){
//            for(int j=(i+1);j<=defenderNo;j++){
//                int d=getDistance(defender[i],defender[j]);
//                if(d<=(4*dist*dist)){
//                    edges[i][j]=1;
//                    edges[j][i]=1;
//                }
//            }
//        }
        //bool isReachable=getPath();
        //int res=0;
        //if there is a path from the south to north border
        //then maximum flow
//        if(isReachable==true){
//            res=maxflow();
//        }
//        else{
//            res=0;
//        }
        cout<<"Case "<<count++<<": "<<maxflow()<<endl;
    }
}
