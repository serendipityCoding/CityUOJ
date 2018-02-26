#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <string.h>
#include <set>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;
pair<int,pair<int,int>> graph[10000];
int roadNo, intersectionNo;
int id[10000];
void initialize(){
    for(int i=0;i<10000;i++){
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

int kruskal(){
    int x, y;
    int cost;
    int res=1000;
    for(int i=roadNo; i>0;i--){
        x=graph[i].second.first;
        y=graph[i].second.second;
        cost=graph[i].first;
        if(root(x)!=root(y)){
            union1(x,y);
            if(cost<res) res=cost;
        }
    }
    return res;
}
int main(){
    int testCases;
    scanf("%d\n",&testCases);
    for(int m=0;m<testCases;m++){
        initialize();
        scanf("%d %d\n",&intersectionNo,&roadNo);
        for(int i=0;i<roadNo;i++){
            int n1, n2, l;
            scanf("%d %d %d\n",&n1, &n2, &l);
            graph[i]=make_pair(l,make_pair(n1, n2));
        }
        sort(graph,graph+roadNo);
        cout<<"Case #"<<(m+1)<<": "<<kruskal()<<endl;
    }
}
