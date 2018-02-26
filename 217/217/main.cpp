#include <iostream>
using namespace std;
int coins[5];
int n=5;
int dp(int t, int total){
    int table[total+1];
    for(int i=0;i<total+1;i++){
        table[i]=0;
    }
    table[0] = 1;
    for(int i=0; i<t; i++)
        for(int j=coins[i]; j<=total; j++)
            table[j] += table[j-coins[i]];
    return table[total];
}
int main(){
    int total;
    coins[0]=1;
    coins[1]=5;
    coins[2]=10;
    coins[3]=25;
    coins[4]=50;
    while(cin>>total){
        cout<<dp(n,total)<<endl;
    }
}
