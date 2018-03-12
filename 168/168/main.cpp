#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
pair<int,pair<int,int>> edge[2502];
int id[51];
int pointNo, routeNo;
void initialize(){
    for(int i=0;i<pointNo;i++)
        id[i]=i;
}
int root(int x){
    while(id[x]!=x){
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void union1(int x, int y){
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
}
int kruskal(){
    int x, y;
    int cost,minimumCost=0;
    for(int i=0;i<routeNo;++i){
        x=edge[i].second.first;
        y=edge[i].second.second;
        cost=edge[i].first;
        if(root(x)!=root(y)){
            minimumCost+=cost;
            union1(x,y);
        }
    }
    return minimumCost;
}
int main(){
    while(cin>>pointNo){
        if(pointNo==0) return 0;
        cin>>routeNo;
        initialize();
        int n1, n2, l;
        for(int i=0;i<routeNo;i++){
            cin>>n1>>n2>>l;
            n1-=1;
            n2-=1;
            edge[i]=make_pair(l,make_pair(n1,n2));
        }
        sort(edge,edge+routeNo);
        cout<<kruskal()<<endl;
    }
}
