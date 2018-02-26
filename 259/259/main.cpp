#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;
int dp[105][105];
bool isRegularSeq(string s){
    stack<char> bin;
    if(s.length()==0) return true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='['||s[i]=='(') bin.push(s[i]);
        if(s[i]==']'){
            if(bin.empty()||bin.top()!='[') {
                return false;
            }
            bin.pop();
        }
        if(s[i]==')'){
            if(bin.empty()||bin.top()!='(') {
                return false;
            }
            bin.pop();
        }
    }
    if(bin.empty()) return true;
    else return false;
}
int getMinimum(string s){
    for(int i=0;i<s.length();i++){
        dp[i][i]=1;
    }
    for(int i=s.length()-1;i>=0;i--){
        for(int j=(i+1);j<s.length();j++){
                int min=dp[i][j-1]+1;
                int k=i;
                while(k<j){
                    if((s[k]=='('&&s[j]==')')||(s[k]=='['&&s[j]==']')){
                        if(i==k){
                            if(min>dp[i+1][j-1]) min=dp[i+1][j-1];
                        }
                        else if(k==(j-1)){
                            if(min>dp[i][k-1]) min=dp[i][k-1];
                        }
                        else{
                            if(min>dp[i][k-1]+dp[k+1][j-1]) min=dp[i][k-1]+dp[k+1][j-1];
                        }
                    }
                    k++;
                }
                dp[i][j]=min;
        }
    }
//    for(int i=0;i<s.length();i++){
//        for(int j=0;j<s.length();j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return dp[0][s.length()-1];
}
int main(){
    int testCases;
    cin>>testCases;
    getchar();
    getchar();
    for(int i=0;i<testCases;i++){
        memset(dp,0,sizeof(dp));
        string input="";
        getline(cin,input);
        if(i!=(testCases-1)) getchar();
        bool isRegular=isRegularSeq(input);
        if(isRegular){
            cout<<input.length()<<endl;
        }
        else cout<<getMinimum(input)+input.length()<<endl;
        if(i!=(testCases-1)) cout<<endl;
        
    }
}
