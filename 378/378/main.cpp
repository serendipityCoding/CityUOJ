#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <vector>
#include <utility>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;
int maxDiff;
int* parent;
struct Monster{
    int id;
    int cost;
    int level;
    int ruleNo;
    int** rules=new int*[100+5];
};
Monster* monsters;
int getMinLevel(int id){
    int t=id;
    int minLevel=monsters[t].level;
    while(t>0){
        if(monsters[t].level<minLevel) minLevel=monsters[t].level;
        t=parent[t];
    }
    return minLevel;
}
int getMaxLevel(int id){
    int t=id;
    int maxLevel=monsters[t].level;
    while(t>0){
        if(monsters[t].level>maxLevel) maxLevel=monsters[t].level;
        t=parent[t];
    }
    return maxLevel;
}
int main(){
    int monsterNo;
    while(scanf("%d %d",&maxDiff,&monsterNo)!=EOF){
        monsters=new Monster[100+5];
        bool* visited=new bool[100+5];
        for(int i=0;i<monsterNo;i++){
            Monster m;
            m.id=i+1;
            visited[i]=false;
            scanf("%d %d %d",&m.cost,&m.level,&m.ruleNo);
            for(int i=0;i<105;i++){
                m.rules[i]=new int[2];
            }
            for(int j=0;j<m.ruleNo;j++){
                int tempM, tempCost;
                scanf("%d %d",&tempM,&tempCost);
                m.rules[j][0]=tempM;
                m.rules[j][1]=tempCost;
            }
            monsters[i+1]=m;
        }
        int src=1;
        visited[src]=true;
        int* dest=new int[monsterNo+1];
        parent=new int[monsterNo+1];
        for(int i=0;i<=monsterNo;i++){
            dest[i]=0xfffffff;
            parent[i]=-1;
        }
        dest[src]=0;
        parent[src]=0;
        visited[src]=true;
        multiset<pair<int,int>> s;
        s.insert({dest[src],src});
        while(!s.empty()){
            pair<int,int> p=*s.begin();
            int id=p.second;
            int maxL=getMaxLevel(id);
            int minL=getMinLevel(id);
            Monster m=monsters[id];
            int level=m.level;
            s.erase(s.begin());
            for(int i=0;i<m.ruleNo;i++){
                int fromMonster=m.rules[i][0];
                int fromMonsterCost=m.rules[i][1];
                int fromMonsterLevel=monsters[fromMonster].level;
                if(abs(fromMonsterLevel-maxL)<=maxDiff&&abs(fromMonsterLevel-minL)<=maxDiff){
                    if(visited[fromMonster]==false){
                        if(dest[fromMonster]>dest[m.id]+fromMonsterCost){
                            parent[fromMonster]=m.id;
                            dest[fromMonster]=dest[m.id]+fromMonsterCost;
                            visited[fromMonster]=true;
                            s.insert({dest[fromMonster],fromMonster});
                        }
                    }
                }
            }
        }
        for(int i=1;i<=monsterNo;i++){
            cout<<dest[i]<<" "<<endl;
        }
        int res=monsters[1].cost;
        for(int i=1;i<=monsterNo;i++){
            int t=i;
            int maxLevel=monsters[i].level;
            int minLevel=monsters[i].level;
            while(t>0){
                if(monsters[t].level>maxLevel) maxLevel=monsters[t].level;
                if(monsters[t].level<minLevel) minLevel=monsters[t].level;
                t=parent[t];
            }
            if((maxLevel-minLevel)<=maxDiff){
                if(res>(dest[i]+monsters[i].cost)) res=dest[i]+monsters[i].cost;
            }
        }
        printf("%d\n",res);
    }
}
