#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int m,n;
long dp(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    
}
int main(){
    while(scanf("%d %d",&m,&n)!=EOF){
        long result=dp(n);
        cout<<result%1000000007<<endl;
    }
}
