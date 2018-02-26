#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;
vector<pair<int,int> > graph[505];
bool visited[505]={false};
int m=-2147483648;
int dfs(int fromNode){
    int c=1;
    for(int i=0;i<graph[fromNode].size();i++){
        int toNode=graph[fromNode][i].first;
        int length=graph[fromNode][i].second;
        if(visited[toNode]==true||length!=m) continue;
        visited[toNode]=true;
        c+=dfs(toNode);
    }
    return c;
}
int main(){
    int roadNo, cityNo;
    while(cin>>roadNo&&cin>>cityNo){
        memset(visited,false,sizeof(visited));
        m=-2147483648;
        if(roadNo==0 && cityNo==0) break;
        for(int i=0;i<cityNo;i++){
            int n1, n2, l;
            scanf("%d %d %d",&n1,&n2,&l);
            graph[n1].push_back(make_pair(n2,l));
            graph[n2].push_back(make_pair(n1,l));
            m=max(m,l);
        }
        int res=0;
        for(int i=1;i<=roadNo;i++){
            if(visited[i]==false){
                visited[i]=true;
                res=max(res,dfs(i));
            }
        }
        cout<<res<<endl;
        for(int i=0;i<505;i++){
            graph[i].clear();
        }
    }
}
