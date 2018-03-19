#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
using namespace std;
int cityNo;
int status[53][53];
int buildCost[53][53];
int destroyCost[53][53];
int id[53];
bool visited[53][53];
int sum;
int root(int x){
    while(id[x]!= x){
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
int kruskalDestroy(pair<int,pair<int, int>> destroy[], int l){
    int x, y;
    int cost, minimumCost = 0;
    for(int i=l;i>0;i--){
        x = destroy[i].second.first;
        y = destroy[i].second.second;
        cost = destroy[i].first;
        if(root(x)!=root(y)){
            union1(x,y);
        }
        else minimumCost+=cost;
    }
    return minimumCost;
}
int kruskalBuild(pair<int,pair<int, int>> build[],int l){
    int x, y;
    int cost, minimumCost = 0;
    for(int i=1;i<=l;i++){
        x=build[i].second.first;
        y=build[i].second.second;
        cost=build[i].first;
        if(root(x)!=root(y)){
            minimumCost+=cost;
            union1(x,y);
        }
    }
    return minimumCost;
}
int main(){
    while(cin>>cityNo){
        if(cityNo==0) break;
        sum=0;
        pair<int,pair<int,int>> build[2520];
        pair<int,pair<int,int>> destroy[2520];
        for(int i=0;i<=cityNo;i++){
            id[i]=i;
        }
        getchar();
        for(int i=1;i<=cityNo;i++){
            string s="";
            getline(cin,s);
            for(int j=1;j<=cityNo;j++){
                status[i][j]=s[j-1]-'0';
            }
        }
        for(int i=1;i<=cityNo;i++){
            for(int j=1;j<=cityNo;j++){
                cin>>buildCost[i][j];
                visited[i][j]=false;
            }
        }
        for(int i=1;i<=cityNo;i++){
            for(int j=1;j<=cityNo;j++){
                cin>>destroyCost[i][j];
            }
        }
        
        int index=1;
        for(int i=1;i<=cityNo;i++){
            for(int j=1;j<=cityNo;j++){
                if(status[i][j]==1&&visited[i][j]==false){
                    visited[i][j]=visited[j][i]=true;
                    destroy[index++]=make_pair(destroyCost[i][j],make_pair(i,j));
                }
            }
        }
        sort(destroy,destroy+index);
        sum+=kruskalDestroy(destroy,index);
        index=0;
        for(int i=1;i<=cityNo;i++){
            for(int j=1;j<=cityNo;j++){
                if(status[i][j]==false){
                    build[index++]=make_pair(buildCost[i][j],make_pair(i,j));
                }
            }
        }
        sort(build,build+index);
        sum+=kruskalBuild(build, index);
        cout<<sum<<endl;
    }
}

