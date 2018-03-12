#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int length;
vector<int> input;
vector<int> dp;
int main(){
    while(scanf("%d\n",&length)!=EOF){
        for(int i=1;i<=length;i++){
            int t;
            cin>>t;
            input.push_back(t);
            dp.push_back(1);
        }
        for (int i=1;i<length;i++){
            for (int j=0;j<i;j++){
                if (input[i]>=input[j]&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
        }
        int res=0;
        for (int i=0;i<length;i++){
            if (res<dp[i]){
                res=dp[i];
            }
        }
        cout<<res<<endl;
        input.clear();
        dp.clear();
    }
}
