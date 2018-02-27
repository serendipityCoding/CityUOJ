#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int m,n;
int b1, b2, b3, b4;
int dp[1000005];
int solve(){
    for(int i=0; i<n; i++){
        if(i==0) dp[i]=1;
        else {
            if(((i+1)%m)!=0){
                dp[i]=dp[i-1]%1000000007;
            }
            else{
                dp[i]=(dp[i-1]+dp[(i+1)/m-1])%1000000007;
            }
        }
    }
    return dp[n-1];
}
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        long arr[4]={1,m,m*m,m*m*m};
        int res=solve();
        cout<<res<<endl;
    }
}
