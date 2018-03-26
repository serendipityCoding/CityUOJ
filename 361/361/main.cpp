#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
set<unsigned long long> s;
int notPrime[50]={4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28,30,32,33,34,35,36,38,39,40,42,44,45,46,48,49,50,51,52,54,55,56,57,58,60,62,63,64};
unsigned long long power (unsigned long long s,unsigned long long n){
    unsigned long long  res=1;
    while (n>=1){
        if ((n%2)!=0) res*=s;
        n/=2;
        s=s*s;
    }
    return res;
}
int main (){
    printf("1\n");
    for(int i=2;i<65536;i++){
        int limit;
        if (i==2) limit=63;
        else limit=ceil( 64/(log(i)/log(2)) )-1;
        if (limit <4) break;
        for (int j=0;notPrime[j]<=limit;j++)
            s.insert(power(i,notPrime[j]) );
    }
    set<unsigned long long>::iterator it;
    for (it=s.begin();it!=s.end();it++)
        printf("%llu\n",*it);
    return 0;
}
