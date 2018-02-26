#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <queue>
#include <utility>
#include <tuple>
#include <map>
#include <iomanip>
using namespace std;
int verticeNo, edgeNo;
int id[100];
struct Edge{
    int n1;
    int n2;
    int l;
    bool operator<(const Edge& x)const {
        return l<x.l;
    }
};
Edge graph[10000];
void initialize(){
    for(int i=0;i<=verticeNo;i++){
        id[i]=i;
    }
}
int root(int x){
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int x, int y){
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}
int kruskal(int src){
    int x,y;
    int maxEgde=0;
    int count=0;
    for(int i=src;i<edgeNo;i++){
        x=graph[i].n1;
        y=graph[i].n2;
        if(root(x)!=root(y)){
            union1(x,y);
            count+=1;
            maxEgde=graph[i].l;
        }
    }
    if(count!=(verticeNo-1)) return -2;
    return maxEgde;
}
int main(){
    while(cin>>verticeNo&&cin>>edgeNo){
        if(verticeNo==0&&edgeNo==0) break;
        for(int i=0;i<edgeNo;i++){
            scanf("%d %d %d\n",&graph[i].n1,&graph[i].n2,&graph[i].l);
        }
        initialize();
        sort(graph,graph+edgeNo);
        int slim=kruskal(0);
        if(slim==-2){
            cout<<-1<<endl;
        }
        else{
            int minSlim=slim-graph[0].l;
            for(int i=1;i<edgeNo;i++){
                initialize();
                int k=kruskal(i);
                if(k==-2)  break;
                int temp=k-graph[i].l;
                minSlim=min(temp,minSlim);
            }
            cout<<minSlim<<endl;
        }
    }
}
