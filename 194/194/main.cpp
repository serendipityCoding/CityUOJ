#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
#include <set>
using namespace std;
bool col[8];
bool row[8];
bool leftToRight[15];
bool rightToLeft[15];
int res[8];
int r,c,count;
int t;
int s;
void eightQueens(int currentCol){
    if(currentCol==8){
        cout<<setw(2)<<s;
        s+=1;
        cout<<"      ";
        for(int i=0;i<8;i++){
            if(i==7) cout<<(res[i]+1);
            else cout<<(res[i]+1)<<" ";
        }
        cout<<endl;
    }
    else{
        if(col[currentCol]==false){
            for(int i=0;i<8;i++){
                if(row[i]==true||leftToRight[i+currentCol]==true||rightToLeft[i-currentCol+7]==true){
                    continue;
                }
                else{
                    row[i]=true;
                    leftToRight[i+currentCol]=true;
                    rightToLeft[i-currentCol+7]=true;
                    res[currentCol]=i;
                    eightQueens(currentCol+1);
                    row[i]=false;
                    leftToRight[i+currentCol]=false;
                    rightToLeft[i-currentCol+7]=false;
                }
            }
        }
        else eightQueens(currentCol+1);
    }
}
int main(){
    int testCases;
    scanf("%d\n",&testCases);
    for(t=0;t<testCases;t++){
        memset(col,false,sizeof(col));
        memset(row,false,sizeof(row));
        memset(res,0,sizeof(res));
        memset(leftToRight,false,sizeof(leftToRight));
        memset(rightToLeft,false,sizeof(rightToLeft));
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        scanf("%d %d",&r,&c);
        r-=1;
        c-=1;
        col[c]=true;
        row[r]=true;
        res[c]=r;
        leftToRight[r+c]=true;
        rightToLeft[r-c+7]=true;
        int currentCol=0;
        s=1;
        eightQueens(currentCol);
        if(t!=(testCases-1)) cout<<endl;
    }
}
