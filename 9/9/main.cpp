#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <set>
#include <queue>
using namespace std;
int operation[27][27];
void output( int i, int j, char* s1, char* s2){
    if (i==0&&j==0) return;
    if(operation[i][j] ==1)
        output(i-1, j-1, s1, s2);
    else if(operation[i][j] == 2) {
        output(i-1, j, s1, s2);
        printf("D%c%02d", s1[i-1], j+1);
    }
    else if(operation[i][j] == 3) {
        output(i, j-1, s1, s2);
        printf("I%c%02d", s2[j-1], j);
    } else {
        output(i-1, j-1, s1, s2);
        printf("C%c%02d", s2[j-1], j);
    }
}
void getOperation(char* s1, char* s2){
    int SCS[27][27];
    int l1=strlen(s1);
    int l2=strlen(s2);
    memset(SCS,100,sizeof(SCS));
    SCS[0][0]=0;
    for(int i = 0; i <= l1; i++) {
        for(int j = 0; j <= l2; j++) {
            if(s1[i] == s2[j] && SCS[i+1][j+1] > SCS[i][j]){
                SCS[i+1][j+1] = SCS[i][j];
                operation[i+1][j+1] = 1;
            }
            if(SCS[i+1][j] > SCS[i][j]+1){
                SCS[i+1][j] = SCS[i][j]+1;
                operation[i+1][j] = 2;
            }
            if(SCS[i][j+1] > SCS[i][j]+1){
                SCS[i][j+1] = SCS[i][j]+1;
                operation[i][j+1] = 3;
            }
            if(SCS[i+1][j+1] > SCS[i][j]+1){
                SCS[i+1][j+1] = SCS[i][j]+1;
                operation[i+1][j+1] = 4;
            }
        }
    }
//    for(int i = 0; i <= l1; i++) {
//        for(int j = 0; j <= l1; j++) {
//            cout<<SCS[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    for(int i = 0; i <= l1; i++) {
//        for(int j = 0; j <= l1; j++) {
//            cout<<operation[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    output(l1,l2,s1,s2);
}
int main(){
    char s1[27];
    char s2[27];
    while(scanf("%s",s1)){
        if(s1[0]=='#') break;
        else{
            scanf("%s",s2);
            memset(operation,100,sizeof(operation));
            getOperation(s1, s2);
            cout<<endl;
        }
    }
}
