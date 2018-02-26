#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <set>
#include <tuple>
using namespace std;
/**
    start with walking
    end with riding
    can only ride one road --> no consecutive ride
 **/
#define SIZE 500+5
//road[startNode]=[<endNode, weight>,<endNode,weight>...]
vector<pair<int,int>> roads[SIZE*SIZE];
//withFootDist withoutFootDist
int dist[SIZE][2];
//withFoot withoutFoot
bool visited[SIZE][2];
int n,r;
void dijkstra(){
    //memset(visited,false,sizeof (visited));
    //memset(dist,0xfffffff,sizeof (dist));
    for(int i=0;i<SIZE;i++){
        visited[i][0]=visited[i][1]=false;
        dist[i][0]=dist[i][1]=1000000000;
    }
    dist[0][0]=0;
    //from withFoot(true==0)
    multiset<tuple<int,int>> s;
    s.insert(make_tuple(0,0));
    while(!s.empty()){
        tuple<int,int> p=*s.begin();
        int fromNode=get<0>(p);
        int withFoot=get<1>(p);
        s.erase(s.begin());
        visited[fromNode][withFoot]=true;
        for(int i=0;i<roads[fromNode].size();i++){
            int toNode=roads[fromNode][i].first;
            int w=roads[fromNode][i].second;
            if(dist[toNode][1-withFoot]>w+dist[fromNode][withFoot]){
                dist[toNode][1-withFoot]=w+dist[fromNode][withFoot];
                if(visited[toNode][1-withFoot]==false) {
                    visited[toNode][1-withFoot]=true;
                    s.insert(make_tuple(toNode,1-withFoot));
                }
            }
        }
    }
    if(dist[n-1][0]!=1000000000)cout<<dist[n-1][0]<<endl;
    else cout<<"?"<<endl;
}
int main(){
    int caseNo=1;
    while(scanf("%d %d",&n,&r)!=EOF){
        for(int i=0;i<r;i++){
            int s,e,l;
            scanf("%d %d %d",&s,&e,&l);
            pair<int,int> edge1=make_pair(s,l);
            roads[e].push_back(edge1);
            pair<int,int> edge2=make_pair(e,l);
            roads[s].push_back(edge2);
        }
        printf("Set #%d\n",caseNo++);
        dijkstra();
        for(int i=0;i<SIZE;i++){
            roads[i].clear();
        }
    }
}
