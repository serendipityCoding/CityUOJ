#include <stdio.h>
#include <vector>
#include <cmath>
#define MAX 1299709
using namespace std;
int primes[MAX]={0};
void Sieve(){
    int n=MAX;
    int nNew=sqrt(n);
    //produce the primes smaller than MAX/2+500
    int marked[MAX/2+500]={0};
    //separate numbers of the form i+j+2ij
    // mark all numbers of the form i + j + 2ij as true
    // where 1 <= i <= j
    for(int i=1;i<=(nNew-1)/2;i++)
        for(int j=(i*(i+1))<<1;j<=n/2;j=j+2*i+1)
            marked[j]=1;
    primes[1]=1;
    primes[2]=1;
    for(int i=1;i<=n/2;i++)
        if(marked[i]==0)
            primes[2*i+1]=1;
}
int main()
{
    Sieve();
    int input;
    //printf("%d\n",primes[2]);
    while(scanf("%d",&input)){
        if(input==0) break;
        if(primes[input]==1) printf("0\n");
        else{
            int left, right;
            for(int i=input;;i--){
                if(primes[i]==1){
                    left=i;
                    break;
                }
            }
            for(int i=input;;i++){
                if(primes[i]==1){
                    right=i;
                    break;
                }
            }
            printf("%d\n",right-left);
        }
    }
    return 0;
}
