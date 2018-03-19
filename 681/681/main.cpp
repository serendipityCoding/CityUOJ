#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
#define MAX 1000001
vector<vector<int>> nodes;
int employeeNo;
int boss[MAX];
int ranking[MAX];
int maxLevel=0;
long d[MAX][2];
void giveRank(int n, int level){
    ranking[n]=level;
    for(int i=0;i<nodes[n].size();i++){
        giveRank(nodes[n][i],level+1);
    }
    if(level>maxLevel) maxLevel=level;
}
void dp(int currentLevel){
    for(int i=1;i<=employeeNo;i++){
        if(ranking[i]==currentLevel){
            if(boss[i]!=-1){
                d[boss[i]][0] += max(d[i][0],d[i][1]);
                d[boss[i]][1] += d[i][0];
            }
        }
    }
    if(currentLevel==0){
        return;
    }
    currentLevel--;
    dp(currentLevel);
}
int main(){
    while(cin>>employeeNo){
        memset(boss,-1,sizeof(boss));
        memset(ranking,-1,sizeof(ranking));
        memset(d,0,sizeof(d));
        vector<int> dummy;
        nodes.push_back(dummy);
        for(int i=1;i<=employeeNo;i++){
            cin>>d[i][1];
            nodes.push_back(dummy);
        }
        int u,v;
        for(int i=1;i<employeeNo;i++){
            cin>>u>>v;
            nodes[u].push_back(v);
            boss[v]=u;
        }
        int i;
        for(i=1;i<=employeeNo;i++){
            if(boss[i]==-1){
                giveRank(i,0);
                break;
            }
        }
        dp(maxLevel);
        cout<<max(d[i][0],d[i][1])<<endl;
        for(int i=0;i<=employeeNo;i++){
            nodes[i].clear();
        }
        nodes.clear();
    }
}
