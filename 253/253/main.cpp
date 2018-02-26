#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
int cityNo, roadNo;
int op[3]={-1,0,1};
int src, dest;
struct Edge{
    int toNode;
    int d;
    int speedLimit;
};
vector<Edge> graph[35];
struct Node{
    int node;
    int speed;
    double time;
    int previousNode;
    bool operator>(const Node &n) const{
        return time > n.time;
    }
};

double getMinTime(){
    priority_queue<Node,vector<Node>,greater<Node> > s;
    bool visited[35][35][35]={false};
    double time[35][35][35];
    for(int i=0;i<35;i++){
        for(int j=0;j<35;j++){
            for(int k=0;k<35;k++){
                visited[i][j][k]=false;
                time[i][j][k]=0xfffffff;
            }
        }
    }
    //fromNode toNode speed
    time[src][src][0]=0;
    s.push({src,0,0,0});
    while(!s.empty()){
        Node n=s.top();
        s.pop();
        int fromNode=n.node;
        int currentSpeed=n.speed;
        double currentTime=n.time;
        int previousNode=n.previousNode;
        if(fromNode==dest&&currentSpeed==1) return currentTime;
        if(visited[previousNode][fromNode][currentSpeed]==true) continue;
        visited[previousNode][fromNode][currentSpeed]=true;
        for(int i=0;i<graph[fromNode].size();i++){
            int toNode=graph[fromNode][i].toNode;
            if(toNode!=previousNode){
                int speedLimit=graph[fromNode][i].speedLimit;
                double distance=(double)graph[fromNode][i].d;
                for(int j=0;j<3;j++){
                    if(currentSpeed+op[j]<=speedLimit&&currentSpeed+op[j]>0&&visited[fromNode][toNode][currentSpeed+op[j]]==false){
                        if(time[fromNode][toNode][currentSpeed+op[j]]>currentTime+distance/(double)(currentSpeed+op[j])){
                            double c=(double)(currentSpeed+op[j]);
                            time[fromNode][toNode][currentSpeed+op[j]]=currentTime+distance/c;
                            s.push({toNode,currentSpeed+op[j],time[fromNode][toNode][currentSpeed+op[j]],fromNode});
                            
                        }
                    }
                }
            }
        }
    }
    return -1;
}
int main(){
    while(cin>>cityNo&&cin>>roadNo){
        if(cityNo==0&&roadNo==0) break;
        for(int i=0;i<=cityNo;i++){
            graph[i].clear();
        }
        getchar();
        scanf("%d %d\n",&src,&dest);
        for(int i=0;i<roadNo;i++){
            int x,y,d,c;
            scanf("%d %d %d %d\n",&x,&y,&d,&c);
            graph[x].push_back({y,d,c});
            graph[y].push_back({x,d,c});
        }
        double res=getMinTime();
        if(res==-1) cout<<"unreachable"<<endl;
        else printf("%.5lf\n",res);
    }
}
