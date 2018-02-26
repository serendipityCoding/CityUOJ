#include <iostream>
#include <stdio.h>
using namespace std;
int groupSize;
int objNo;
int max(int d1, int d2){
    if(d1>d2) return d1;
    return d2;
}
int main(){
    int testCases;
    scanf("%d",&testCases);
    for(int i=0;i<testCases;i++){
        scanf("%d",&objNo);
        int dp[31]={0};
        for(int j=0;j<objNo;j++){
            int price,weight;
            scanf("%d %d",&price,&weight);
            for(int k=30;k>=weight;k--){
                if(dp[k]<dp[k-weight]+price){
                    dp[k]=dp[k-weight]+price;
                }
            }
        }
        scanf("%d",&groupSize);
        int sum=0;
        for(int j=0;j<groupSize;j++){
            int temp;
            scanf("%d",&temp);
            sum+=dp[temp];
        }
        cout<<sum<<endl;
    }
}
