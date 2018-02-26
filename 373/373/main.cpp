#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <tuple>
#include <cstring>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
int cityNo, linkNo;
int id[1000];
struct Edge{
    int n1;
    int n2;
    long l;
};
bool acompare(Edge lhs, Edge rhs) { return lhs.l < rhs.l; }
void initialize(){
    for(int i=0;i<cityNo;i++){
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

Edge graph[25000];
int main(){
    while(cin>>cityNo&&cin>>linkNo){
        initialize();
        if(cityNo==0||linkNo==0) break;
        for(int i=0;i<linkNo;i++){
            int x,y;
            long length;
            scanf("%d %d %ld\n",&x,&y,&length);
            Edge e={x,y,length};
            graph[i]=e;
        }
        sort(graph,graph+linkNo,acompare);
        Edge unUsed[25000];
        int k=0;
        int count=0;
        int x,y;
        long long minCost=0;
        for(int i=0;i<linkNo;i++){
            int x=graph[i].n1;
            int y=graph[i].n2;
            if(root(x)!=root(y)){
                union1(x,y);
                count+=1;
                minCost+=graph[i].l;
            }
            else{
                unUsed[k++]=graph[i];
            }
        }
        if(count!=(cityNo-1)) cout<<"\\(^o^)/ pray to god";
        else{
            cout<<"Min Cost: "<<minCost<<endl;
            sort(unUsed,unUsed+k,acompare);
            for(int i=0;i<k;i++){
                cout<<unUsed[i].l;
                if(i!=(k-1)) cout<<" ";
            }
        }
        cout<<endl;
    }
}
