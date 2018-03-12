#include <iostream>
#include <stdio.h>
using namespace std;
int width, height;
int main(){
    while(cin>>height&&cin>>width){
        if(height==0&&width==0) break;
        bool isFound=false;
        for(int i=1;i<=height;i++){
            for(int j=1;j<=width;j++){
                int t;
                cin>>t;
                if(t==1){
                    if(i==1||j==1||i==height||j==width){
                        isFound=true;
                    }
                }
            }
        }
        if(isFound==true) cout<<2<<endl;
        else cout<<4<<endl;
    }
}
