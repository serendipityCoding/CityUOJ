#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int m,n;
int dp[1000005];
int solve(){
    dp[1]=1;
    for(int i=2; i<=n; i++){
        //when i can be divided by m, the number of ways is the
        //same as the last one (lets say some k*m) which can be divided by m plus (k*m-i) boxes with capacity 1
        if((i%m)!=0){
            dp[i]=dp[i-1]%1000000007;
        }
        //when i can be divided by m
        //one way is the same the first case, use box with capacity 1 to fill the gap
        //another way is not using box with one, so just need to multiple all the combinations of dp[i/m] with m
        //therefore it is guarantee that there is no box of capacity 1 in this combination
        else{
            dp[i]=(dp[i-1]+dp[i/m])%1000000007;
        }
    }
    return dp[n];
}
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        int res=solve();
        cout<<res<<endl;
    }
}
