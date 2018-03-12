#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int c[1000][1000];
int LCS(string s1, string s2){
    for(int i=0;i<=s1.length();i++) c[i][0]=0;
    for(int i=1;i<=s2.length();i++) c[0][i]=0;
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[i-1]==s2[j-1]){
                c[i][j]=c[i-1][j-1]+1;
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
            }
            else {
                c[i][j]=c[i][j-1];
            }
        }
    }
    return c[s1.length()][s2.length()];
}
int main(){
    string s1, s2;
    while(getline(cin,s1)&&getline(cin,s2)){
        cout<<LCS(s1,s2)<<endl;
    }
}
