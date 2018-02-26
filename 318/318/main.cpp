#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int graph[125][125];
bool visited[125][125];
int dist[125][125];
int size;
struct Node{
    int x;
    int y;
    int d;
};
bool compare(Node n1,Node n2)
{
    return n1.d>n2.d;
}
int getMinCost(){
    vector<Node> s;
    dist[0][0]=graph[0][0];
    s.push_back({0,0,dist[0][0]});
    while(!s.empty()){
        sort(s.begin(),s.end(),compare);
        Node n=s.back();
        s.pop_back();
        int x=n.x;
        int y=n.y;
        if(visited[x][y]==true) continue;
        visited[x][y]=true;
        if(x-1>=0&&visited[x-1][y]==false){
            if(dist[x-1][y]>dist[x][y]+graph[x-1][y]){
                dist[x-1][y]=dist[x][y]+graph[x-1][y];
                s.push_back({x-1,y,dist[x-1][y]});
            }
        }
        if(x+1<size&&visited[x+1][y]==false){
            if(dist[x+1][y]>dist[x][y]+graph[x+1][y]){
                dist[x+1][y]=dist[x][y]+graph[x+1][y];
                s.push_back({x+1,y,dist[x+1][y]});
            }
        }
        if(y+1<size&&visited[x][y+1]==false){
            if(dist[x][y+1]>dist[x][y]+graph[x][y+1]){
                dist[x][y+1]=dist[x][y]+graph[x][y+1];
                s.push_back({x,y+1,dist[x][y+1]});
            }
        }
        if(y-1>=0&&visited[x][y-1]==false){
            if(dist[x][y-1]>dist[x][y]+graph[x][y-1]){
                dist[x][y-1]=dist[x][y]+graph[x][y-1];
                s.push_back({x,y-1,dist[x][y-1]});
            }
        }
    }
    return dist[size-1][size-1];
}
int main(){
    int count=1;
    while(cin>>size){
        if(size==0) break;
        getchar();
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                visited[i][j]=false;
                dist[i][j]=0xfffffff;
                cin>>graph[i][j];
                getchar();
            }
        }
        cout<<"Problem "<<count++<<": "<<getMinCost()<<endl;
    }
}
