#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
using namespace std;
bool isPrime(int n){
    if(n<=1) return false;
    else if(n<=3) return true;
    else if(n%2==0||n%3==0) return false;
    int i=5;
    while(i*i<=n){
        if(n%i==0||n%(i+2)==0){
            return false;
        }
        i+=6;
    }
    return true;
}
int main(){
    int n;
    //getPrime();
    while(scanf("%d\n",&n)!=EOF){
        if(n==1||n==2) cout<<n<<" is not the sum of two primes!"<<endl;
        else if(n%2!=0){
            if(isPrime(n-2)==true) cout<<n<<" is the sum of 2 and "<<n-2<<"."<<endl;
            else cout<<n<<" is not the sum of two primes!"<<endl;
        }
        else{
            int half=n/2;
            bool found=false;
            for(int i=1;i<half;i++){
                if(isPrime(half-i)==true&&isPrime(half+i)==true){
                    cout<<n<<" is the sum of "<<half-i<<" and "<<half+i<<"."<<endl;
                    found=true;
                    break;
                }
            }
            if(found==false) cout<<n<<" is not the sum of two primes!"<<endl;
        }
    }
}
