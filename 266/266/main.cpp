#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <queue>
#include <stdio.h>
using namespace std;

int main(){
    int cowNo, resultNo;
    while(scanf("%d %d\n",&cowNo,&resultNo)!=EOF){
        bool graph[101][101]={false};
        for(int i=0;i<resultNo;i++){
            int c1, c2;
            scanf("%d %d\n",&c1,&c2);
            graph[c1][c2]=true;
        }
        for(int i=1;i<=cowNo;i++){
            for(int j=1;j<=cowNo;j++){
                for(int k=1;k<=cowNo;k++){
                    if (graph[j][k]==true)  graph[j][k]=true;
                    else{
                        if(graph[j][i]==true&&graph[i][k]==true){
                            graph[j][k]=true;
                        }
                        else graph[j][k]=false;
                    }
                }
            }
        }
        int res=0;
        for(int i=1;i<=cowNo;i++){
            int sum=0;
            for(int j=1;j<=cowNo;j++)
                if(graph[i][j]==true||graph[j][i]==true){
                    sum+=1;
                }
            if(sum==(cowNo-1)) res++;
        }
        cout<<res<<endl;
    }
}
