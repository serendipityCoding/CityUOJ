#include <iostream>
#include <string.h>
using namespace std;
int aNo, bNo, jobNo;
int graph[105][105];
bool visited[105];
int match[105];
bool dfs(int s){
    for(int i=1;i<bNo;i++){
        if(graph[s][i]==1&&visited[i]==false){
            visited[i]=true;
            if(match[i]==0||dfs(match[i])){
                match[i]=s;
                return true;
            }
        }
    }
    return false;
}
int main(){
    while(scanf("%d %d %d",&aNo,&bNo,&jobNo)!=EOF){
        memset(graph,0,sizeof(graph));
        memset(match,0,sizeof(match));
        int modeA, modeB;
        for(int i=1;i<=jobNo;i++){
            cin>>modeA>>modeB;
            if(modeA==0||modeB==0) continue;
            graph[modeA][modeB]=1;
        }
        int res=0;
        for(int i=1;i<aNo;i++){
            memset(visited,false,sizeof(visited));
            if(dfs(i)==true){
                res+=1;
            }
        }
        cout<<res<<endl;
    }
}
