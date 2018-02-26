#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;
int cityNo, roadNo;
int graph[103][103];
int main(){
    while(scanf("%d %d",&cityNo,&roadNo)!=EOF){
        for(int i=1;i<=cityNo;i++){
            for(int j=1;j<=cityNo;j++){
                if(i==j) graph[i][j]=0;
                else graph[i][j]=0xfffffff;
            }
        }
        for(int i=0;i<roadNo;i++){
            int n1,n2,d;
            scanf("%d %d %d\n",&n1,&n2,&d);
            if(graph[n1][n2]>d) graph[n1][n2]=d;
            if(graph[n2][n1]>d) graph[n2][n1]=d;
        }
        for(int k = 1; k <= cityNo; k++){
            for(int i = 1; i <= cityNo; i++){
                for(int j = 1; j <= cityNo; j++){
                    graph[i][j] = min( graph[i][j], graph[i][k] + graph[k][j] );
                }
            }
        }
        int min=0xfffffff;
        int res=cityNo;
        for(int i=cityNo;i>0;i--){
            int sum=0;
            for(int j=1;j<=cityNo;j++){
                sum+=graph[i][j];
            }
            if(sum<=min){
                min=sum;
                res=i;
            }
        }
        cout<<res<<endl;
    }
}
