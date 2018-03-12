#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
vector<int> notPrime;
bool isPrime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    for(int i=4;i<65;i++){
        if(isPrime(i)==false){
            notPrime.push_back(i);
        }
    }
    set<long long>res;
    for(int i=2;i<=65536;i++){
        int temp=ceil(64*log(2)/log(i))-1;
        for(int j=0;notPrime[j]<=temp;j++){
            
        }
    }
}
