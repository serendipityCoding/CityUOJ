#include <iostream>
#include <cmath>
#include <set>
using namespace std;
long long a,b;
set<long long> fa;
set<long long> fb;
void getAPrimeFactor(){
    for(long long i=2;i<=sqrt(a);i++){
        while(a%i==0){
            a/=i;
            fa.insert(i);
        }
    }
    if(a>=2) fa.insert(a);
}
void getBPrimeFactor(){
    for(long long i=2;i<=sqrt(b);i++){
        while(b%i==0){
            b/=i;
            fb.insert(i);
        }
    }
    if(b>=2) fb.insert(b);
}
int main(){
    while(cin>>a>>b){
        if(a==0&&b==0) return 0;
        getAPrimeFactor();
        getBPrimeFactor();
        long long largestA=0;
        long long sumA=0;
        for(const long long i:fa){
            if(i>largestA) largestA=i;
            sumA+=i;
        }
        long long resA=2*largestA-sumA;
        long long largestB=0;
        long long sumB=0;
        for(const long long i:fb){
            if(i>largestB) largestB=i;
            sumB+=i;
        }
        long long resB=2*largestB-sumB;
        if(resA<resB) cout<<"b"<<endl;
        else cout<<"a"<<endl;
        fa.clear();
        fb.clear();
    }
}
