#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
int moduleNo, pairNo;
int src,dest;
struct Edge {
    int from,to,cap,flow,next;
};
struct Dinic{
    Edge edge[42000];
    int head[220],top;
    void init(){
        memset(head,-1,sizeof(head));
        top=0;
    }
    void addEdge(int a,int b,int c){
        Edge e={a,b,c,0,head[a]};
        edge[top]=e;
        head[a]=top++;
        Edge ee={b,a,0,0,head[b]};
        edge[top]=ee;
        head[b]=top++;
    }
    bool vis[220];
    int dis[220];
    bool bfs(int st,int ed){
        memset(dis,0,sizeof(dis));
        queue<int>Q;
        memset(vis,false,sizeof(vis));
        Q.push(st);
        vis[st]=true;
        dis[st]=0;
        while(!Q.empty()){
            int now=Q.front();
            Q.pop();
            for(int i=head[now];i!=-1;i=edge[i].next){
                Edge e=edge[i];
                if(vis[e.to]) continue;
                if(e.cap-e.flow>0){
                    dis[e.to]=dis[now]+1;
                    vis[e.to]=true;
                    Q.push(e.to);
                }
            }
        }
        return dis[ed]>0 ;
    }
    int cur[220];
    int dfs(int now, int a,int ed){
        if(now==ed||a==0) return a;
        int flow=0;
        for(int& i=cur[now];i!=-1;i=edge[i].next){
            Edge& e=edge[i];
            if(dis[now]+1==dis[e.to]){
                int f=dfs(e.to,min(a,e.cap-e.flow),ed);
                if(f>0){
                    e.flow+=f;
                    edge[i^1].flow-=f;
                    flow+=f;
                    a-=f;
                    if(!a) break;
                }
            }
        }
        return flow;
    }
    int maxFlow(int st,int ed){
        int ans=0;
        while(bfs(st,ed)){
            memcpy(cur,head,sizeof(head));
            ans+=dfs(st,99999999,ed);
        }
        return ans;
    }
}dinic;

int main(){
    while(cin>>moduleNo>>pairNo){
        dinic.init();
        src=0;
        dest=moduleNo+1;
        int c1,c2;
        for(int i=1;i<=moduleNo;i++){
            cin>>c1>>c2;
            dinic.addEdge(0,i,c1);
            dinic.addEdge(i,dest,c2);
        }
        int u,v,c;
        for(int i=1;i<=pairNo;i++){
            cin>>u>>v>>c;
            dinic.addEdge(u,v,c);
            dinic.addEdge(v,u,c);
        }
        cout<<dinic.maxFlow(src,dest)<<endl;
    }
}
