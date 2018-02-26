#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;
int categoryNo, problemNo;
int questionNoEachCategory[22];
int startIndex[22];
int graph[1002][105];
int totalQuestionNeeded=0;
bool visited[1002];
int matchR[100];
bool bpm(int question){
    for(int i=1;i<=totalQuestionNeeded;i++){
        if(graph[question][i]==1&&visited[i]==false){
            visited[i]=true;
            if(matchR[i]==-1||bpm(matchR[i])){
                matchR[i]=question;
                return true;
            }
        }
    }
    return false;
}
bool solve(){
    int result=0;
    memset(matchR,-1,sizeof(matchR));
    for(int i=1;i<=problemNo;i++){
        memset(visited,false,sizeof(visited));
        if(bpm(i)){
            result+=1;
        }
    }
    if(result==totalQuestionNeeded) return true;
    else return false;
}
int main(){
    while(cin>>categoryNo&&cin>>problemNo){
        if(categoryNo==0&&problemNo==0) break;
        for(int i=0;i<=problemNo;i++){
            memset(graph[i],0,sizeof(graph[i]));
        }
        totalQuestionNeeded=0;
        for(int i=1;i<=categoryNo;i++){
            cin>>questionNoEachCategory[i];
            startIndex[i]=totalQuestionNeeded+1;
            totalQuestionNeeded+=questionNoEachCategory[i];
        }
        for(int i=1;i<=problemNo;i++){
            int no;
            cin>>no;
            for(int j=0;j<no;j++){
                int temp;
                cin>>temp;
                for(int k=0;k<questionNoEachCategory[temp];k++){
                    graph[i][startIndex[temp]+k]=1;
                }
            }
        }
        bool res=solve();
        if(res==true) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}
