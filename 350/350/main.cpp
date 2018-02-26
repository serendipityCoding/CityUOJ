#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
char grid[55][55];
int rowCount;
int length;
int dp[55][55][55][55];
int getMax(int d1, int d2, int d3, int d4){
    int max=d1;
    if(max<d2) max=d2;
    if(max<d3) max=d3;
    if(max<d4) max=d4;
    return max;
}
int solve(int x0, int xt, int y0, int yt){
    if(xt-x0<2||yt-y0<2) return 0;
    else{
        if(dp[x0][xt][y0][yt]==-1){
            bool possible=true;
            for(int j=y0;j<=yt;j++){
                if(grid[x0][j]=='.'||grid[xt][j]=='.'){
                    possible =false;
                    break;
                }
            }
            if(possible==true){
                for(int i=x0;i<=xt;i++){
                    if(grid[i][y0]=='.'||grid[i][yt]=='.'){
                        possible =false;
                        break;
                    }
                }
            }
            if(possible==true){
                dp[x0][xt][y0][yt]=1+solve(x0+1,xt-1,y0+1,yt-1);
            }
            else{
                dp[x0][xt][y0][yt]=max(solve(x0+1,xt,y0,yt),max(solve(x0,xt-1,y0,yt),max(solve(x0,xt,y0+1,yt),solve(x0,xt,y0,yt-1))));
            }
        }
        return dp[x0][xt][y0][yt];
    }
}
int main(){
    int testCases;
    scanf("%d\n",&testCases);
    for(int m=0;m<testCases;m++){
        memset(dp,-1,sizeof(dp));
        scanf("%d\n",&rowCount);
        string s;
        for(int i=0;i<rowCount;i++){
            getline(cin,s);
            for(int j=0;j<s.length();j++){
                grid[i][j]=s[j];
            }
        }
        length=s.length();
        printf("Case #%d: %d\n",(m+1),solve(0,length-1,0,rowCount-1));
    }
}

