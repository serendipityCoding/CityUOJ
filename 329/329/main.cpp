#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <utility>
#include <tuple>
#include <vector>
using namespace std;
int getMin(int d1, int d2){
    if(d1<d2) return d1;
    return d2;
}
int shortestCommonSuperStr(string s1, string s2){
    int l1=int(s1.length());
    int l2=int(s2.length());
    int** dp=new int*[l1+1];
    for(int i=0;i<=l1;i++){
        dp[i]=new int[l2+1];
    }
    for (int i=0;i<=l1;i++){
        for (int j=0;j<=l2;j++){
            if (!i)
                dp[i][j]=j;
            else if (!j)
                dp[i][j]=i;
            else if (s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=1+getMin(dp[i-1][j], dp[i][j-1]);
        }
    }
    int res=dp[l1][l2];
    for(int i=0;i<=l1;i++){
        delete[] dp[i];
    }
    delete[] dp;
    return res;
}
int main(){
    int testCases;
    scanf("%d\n",&testCases);
    for(int i=0;i<testCases;i++){
        string s1;
        string s2;
        getline(cin,s1);
        getline(cin,s2);
        cout<<shortestCommonSuperStr(s1,s2)<<endl;
    }
}
