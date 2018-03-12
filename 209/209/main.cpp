#include <iostream>
using namespace std;
int rectNo;
int rect[102][4];

bool collide(int l1, int l2){
    int x1=rect[l1][0];
    int y1=rect[l1][1];
    int x2=rect[l1][2];
    int y2=rect[l1][3];
   
    
}
int main(){
    int testCase;
    cin>>testCase;
    for(int i=0;i<testCase;i++){
        cin>>rectNo;
        for(int i=0;i<rectNo;i++){
            cin>>rect[i][0]>>rect[i][1]>>rect[i][2]>>rect[i][3];
        }
        int res=0;
        for(int i=0;i<rectNo;i++){
            bool isCollide=false;
            for(int j=0;j<rectNo;j++){
                if(i==j) continue;
                if(collide(i,j)==true){
                    isCollide=true;
                    break;
                }
            }
            if(isCollide==false) res+=1;
        }
        cout<<res<<endl;
    }
}
