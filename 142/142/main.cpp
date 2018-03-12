#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
int citizenNo, pairNo;
int friends[30000];
int size[30000];
int r[30000];
void initialize(){
    for(int i=0;i<citizenNo;i++){
        friends[i]=i;
        size[i]=1;
        r[i]=0;
    }
}
int root(int i){
    while(friends[i]!=i){
        i=friends[i];
    }
    return i;
}
void unionFriends(int n1,int n2){
    int root1=root(n1);
    int root2=root(n2);
    if(r[root1]>r[root2]){
        friends[root2]=root1;
        size[root1]+=size[root2];
    }
    else{
        friends[root1]=root2;
        size[root2]+=size[root1];
        if(r[root1]==r[root2]) r[root2]+=1;
    }
}
bool find(int n1,int n2){
    if(root(n1)==root(n2)) return true;
    else return false;
}
int main(){
    int testCase;
    cin>>testCase;
    for(int t=0;t<testCase;t++){
        cin>>citizenNo>>pairNo;
        initialize();
        int n1, n2;
        for(int i=0;i<pairNo;i++){
            cin>>n1>>n2;
            n1-=1;
            n2-=1;
            if(find(n1,n2)==true) continue;
            else unionFriends(n1,n2);
        }
        int max=0;
        for(int i=0;i<citizenNo;i++){
            if(max<size[i]) max=size[i];
        }
        cout<<max<<endl;
    }
}
