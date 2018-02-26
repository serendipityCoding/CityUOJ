#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <iterator>
#include <set>
using namespace std;
int keyNo;
string keys[500];
int id[500];
int k=0;
struct Edge{
    int n1;
    int n2;
    int l;
};
Edge graph[150000];
int move(char s1,char s2){
    int d1=int(s1);
    int d2=int(s2);
    if(abs(d1-d2)>5) return 10-abs(d1-d2);
    return abs(d1-d2);
}
int getDistance(string fromNode, string toNode){
    int d=0;
    for(int i=0;i<4;i++){
        d+=move(fromNode[i],toNode[i]);
    }
    return d;
}
void initialize()
{
    for(int i = 0;i < keyNo;++i)
        id[i] = i;
}

int root(int x){
    while(id[x] != x)
    {
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

int kruskal()
{
    int x,y;
    int minCost=0;
    for(int i=0;i<k;i++){
        x=graph[i].n1;
        y=graph[i].n2;
        if(root(x)!=root(y)){
            minCost+=graph[i].l;
            union1(x,y);
        }
    }
    return minCost;
}
bool acompare(Edge lhs, Edge rhs) { return lhs.l < rhs.l; }
int main(){
    int testCases;
    scanf("%d\n",&testCases);
    for(int m=0;m<testCases;m++){
        scanf("%d",&keyNo);
        getchar();
        initialize();
        int min=0xfffffff;
        for(int i=0;i<keyNo;i++){
            cin>>keys[i];
            int temp=getDistance("0000", keys[i]);
            if(temp<min) min=temp;
        }
        k=0;
        for(int i=0;i<keyNo;i++){
            for(int j=(i+1);j<keyNo;j++){
                struct Edge e;
                e.n1=i;
                e.n2=j;
                e.l=getDistance(keys[i], keys[j]);
                graph[k++]=e;
            }
        }
        sort(graph,graph+k,acompare);
        int miniCost=kruskal()+min;
        cout<<miniCost<<endl;
        
    }
}
