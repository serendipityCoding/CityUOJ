#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <queue>
using namespace std;
int aCap,bCap,cCap,dCap,T;
bool visited[27][27][27][27]={false};
int level[27][27][27][27]={0};
set<int> res;
queue<int> qA, qB, qC, qD;
bool withinCap(int a1, int b1, int c1, int d1){
    if(a1<=aCap && b1<=bCap && c1<=cCap&&d1<=dCap) return true;
    else return false;
}
void addToQueue(int a1, int b1, int c1, int d1){
    //cout<<a1<<" "<<b1<<" "<<c1<<" "<<d1<<endl;
    visited[a1][b1][c1][d1]=true;
    qA.push(a1);
    qB.push(b1);
    qC.push(c1);
    qD.push(d1);
}
void bfs(int a, int b, int c, int d){
    qA.push(a);
    qB.push(b);
    qC.push(c);
    qD.push(d);
    level[a][b][c][d]=0;
    visited[a][b][c][d]=true;
    while(!qA.empty()||!qB.empty()||!qC.empty()||!qD.empty()){
        int a0=qA.front();
        qA.pop();
        int b0=qB.front();
        qB.pop();
        int c0=qC.front();
        qC.pop();
        int d0=qD.front();
        qD.pop();
        //cout<<"-------------------------------------"<<endl;
        //cout<<a0<<" "<<b0<<" "<<c0<<" "<<d0<<endl;
        //cout<<level[a0][b0][c0][d0]<<endl;
        //cout<<"......................................"<<endl;
        if(a0==T||b0==T||c0==T||d0==T){
            //cout<<"############################"<<endl;
            //cout<<a0<<" "<<b0<<" "<<c0<<" "<<d0<<endl;
            //cout<<level[a0][b0][c0][d0]<<endl;
            res.insert(level[a0][b0][c0][d0]);
            //cout<<"----------------------------"<<endl;
            break;
        }
        if(a0<=aCap&&a0>=0){
            //fill a
            if(visited[aCap][b0][c0][d0]==false&&withinCap(aCap,b0,c0,d0)){
                //cout<<"fill a"<<endl;
                addToQueue(aCap, b0, c0, d0);
                level[aCap][b0][c0][d0]=level[a0][b0][c0][d0]+1;
            }
            //empty a
            if(visited[0][b0][c0][d0]==false&&withinCap(0, b0, c0, d0)){
                //cout<<"empty a"<<endl;
                addToQueue(0, b0, c0, d0);
                level[0][b0][c0][d0]=level[a0][b0][c0][d0]+1;
            }
            //a-->b
            if(a0+b0>bCap){
                if(visited[a0+b0-bCap][bCap][c0][d0]==false&&withinCap(a0+b0-bCap, bCap, c0, d0)){
                    //cout<<"a-->b(>bCap)"<<endl;
                    addToQueue(a0+b0-bCap, bCap, c0, d0);
                    level[a0+b0-bCap][bCap][c0][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[0][a0+b0][c0][d0]==false&&withinCap(0, a0+b0, c0, d0)){
                    //cout<<"a-->b(<bCap)"<<endl;
                    addToQueue(0, a0+b0, c0, d0);
                    visited[0][a0+b0][c0][d0]=true;
                    level[0][a0+b0][c0][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            //a-->c
            if(a0+c0>cCap){
                if(visited[a0+c0-cCap][b0][cCap][d0]==false&&withinCap(a0+c0-cCap, b0, cCap, d0)){
                    //cout<<"a-->c(>cCap)"<<endl;
                    addToQueue(a0+c0-cCap, b0, cCap, d0);
                    level[a0+c0-cCap][b0][cCap][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[0][b0][a0+c0][d0]==false&&withinCap(0, b0, a0+c0, d0)){
                    //cout<<"a-->c(<cCap)"<<endl;
                    addToQueue(0, b0, a0+c0, d0);
                    level[0][b0][a0+c0][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            //a-->d
            if(a0+d0>dCap){
                if(visited[a0+d0-dCap][b0][c0][dCap]==false&&withinCap(a0+d0-dCap, b0, c0, dCap)){
                    //cout<<"a-->d(>dCap)"<<endl;
                    addToQueue(a0+d0-dCap, b0, c0, dCap);
                    level[a0+d0-dCap][b0][c0][dCap]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[0][b0][c0][a0+d0]==false&&withinCap(0, b0, c0, a0+d0)){
                    //cout<<"a-->d(<dCap)"<<endl;
                    addToQueue(0, b0, c0, a0+d0);
                    level[0][b0][c0][a0+d0]=level[a0][b0][c0][d0]+1;
                }
            }
        }
        if(b0<=bCap&&b0>=0){
            //fill b
            if(visited[a0][bCap][c0][d0]==false&&withinCap(a0, bCap, c0, d0)){
                //cout<<"fill b"<<endl;
                addToQueue(a0, bCap, c0, d0);
                level[a0][bCap][c0][d0]=level[a0][b0][c0][d0]+1;
            }
            //empty b
            if(visited[a0][0][c0][d0]==false&&withinCap(a0, 0, c0, d0)){
                //cout<<"empty b"<<endl;
                addToQueue(a0, 0, c0, d0);
                level[a0][0][c0][d0]=level[a0][b0][c0][d0]+1;
            }
            //b-->a
            if(a0+b0>aCap){
                if(visited[aCap][a0+b0-aCap][c0][d0]==false&&withinCap(aCap, a0+b0-aCap, c0, d0)){
                    //cout<<"b-->a(>aCap)"<<endl;
                    addToQueue(aCap, a0+b0-aCap, c0, d0);
                    level[aCap][a0+b0-aCap][c0][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[a0+b0][0][c0][d0]==false&&withinCap(a0+b0, 0, c0, d0)){
                    //cout<<"b-->a(<aCap)"<<endl;
                    addToQueue(a0+b0, 0, c0, d0);
                    level[a0+b0][0][c0][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            //b-->c
            if(c0+b0>cCap){
                if(visited[a0][c0+b0-cCap][cCap][d0]==false&&withinCap(a0, b0+c0-cCap, cCap, d0)){
                    //cout<<"b-->c(>cCap)"<<endl;
                    addToQueue(a0, b0+c0-cCap, cCap, d0);
                    level[a0][c0+b0-cCap][cCap][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[a0][0][b0+c0][d0]==false&&withinCap(a0, 0, b0+c0, d0)){
                    //cout<<"b-->c(<cCap)"<<endl;
                    addToQueue(a0, 0, b0+c0, d0);
                    level[a0][0][b0+c0][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            //b-->d
            if(b0+d0>dCap){
                if(visited[a0][d0+b0-dCap][c0][dCap]==false&&withinCap(a0, d0+b0-dCap, c0, dCap)){
                    //cout<<"b-->d(>dCap)"<<endl;
                    addToQueue(a0, d0+b0-dCap, c0, dCap);
                    level[a0][d0+b0-dCap][c0][dCap]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[a0][0][c0][b0+d0]==false&&withinCap(a0, 0, c0, b0+d0)){
                    //cout<<"b-->d(<dCap)"<<endl;
                    addToQueue(a0, 0, c0, b0+d0);
                    level[a0][0][c0][b0+d0]=level[a0][b0][c0][d0]+1;
                }
            }
        }
        if(c0<=cCap&&c0>=0){
            //fill c
            if(visited[a0][b0][cCap][d0]==false&&withinCap(a0, b0, cCap, d0)){
                //cout<<"fill c"<<endl;
                addToQueue(a0, b0, cCap, d0);
                level[a0][b0][cCap][d0]=level[a0][b0][c0][d0]+1;
            }
            //empty c
            if(visited[a0][b0][0][d0]==false&&withinCap(a0, b0, 0, d0)){
                //cout<<"empty c"<<endl;
                addToQueue(a0, b0, 0, d0);
                level[a0][b0][0][d0]=level[a0][b0][c0][d0]+1;
            }
            //c-->a
            if(a0+c0>aCap){
                if(visited[aCap][b0][c0+a0-aCap][d0]==false&&withinCap(aCap, b0, c0+a0-aCap, d0)){
                    //cout<<"c-->a(>aCap)"<<endl;
                    addToQueue(aCap, b0, c0+a0-aCap, d0);
                    level[aCap][b0][c0+a0-aCap][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[c0+a0][b0][0][d0]==false&&withinCap(a0, b0, cCap, d0)){
                    //cout<<"c-->a(<aCap)"<<endl;
                    addToQueue(a0+c0, b0, 0, d0);
                    level[c0+a0][b0][0][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            //c-->b
            if(b0+c0>bCap){
                if(visited[a0][bCap][c0+b0-bCap][d0]==false&&withinCap(a0, bCap, c0+b0-bCap, d0)){
                    //cout<<"c-->b(>bCap)"<<endl;
                    addToQueue(a0, bCap, c0+b0-bCap, d0);
                    level[a0][bCap][c0+b0-bCap][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[a0][c0+b0][0][d0]==false&&withinCap(a0, b0+c0, 0, d0)){
                    //cout<<"c-->b(<bCap)"<<endl;
                    addToQueue(a0, b0+c0, 0, d0);
                    level[a0][c0+b0][0][d0]=level[a0][b0][c0][d0]+1;
                }
            }
            //c-->d
            if(d0+c0>dCap){
                if(visited[a0][b0][c0+d0-dCap][dCap]==false&&withinCap(a0, b0, c0+d0-dCap, dCap)){
                    //cout<<"c-->d(>dCap)"<<endl;
                    addToQueue(a0, b0, c0+d0-dCap, dCap);
                    level[a0][b0][c0+d0-dCap][dCap]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[a0][b0][0][c0+d0]==false&&withinCap(a0, b0, 0, c0+d0)){
                    //cout<<"c-->d(<dCap)"<<endl;
                    addToQueue(a0, b0, 0, c0+d0);
                    level[a0][b0][0][c0+d0]=level[a0][b0][c0][d0]+1;
                }
            }
        }
        if(d0<=dCap&&d0>=0){
            //fill d
            if(visited[a0][b0][c0][dCap]==false&&withinCap(a0, b0, c0, dCap)){
                //cout<<"fill d"<<endl;
                addToQueue(a0, b0, c0, dCap);
                level[a0][b0][c0][dCap]=level[a0][b0][c0][d0]+1;
            }
            //empty d
            if(visited[a0][b0][c0][0]==false&&withinCap(a0, b0, c0, 0)){
                //cout<<"empty d"<<endl;
                addToQueue(a0, b0, c0, 0);
                level[a0][b0][c0][0]=level[a0][b0][c0][d0]+1;
            }
            //d-->a
            if(a0+d0>aCap){
                if(visited[aCap][b0][c0][d0+a0-aCap]==false&&withinCap(aCap, b0, c0, d0+a0-aCap)){
                    //cout<<"d-->a(>aCap)"<<endl;
                    addToQueue(aCap, b0, c0, d0+a0-aCap);
                    level[aCap][b0][c0][d0+a0-aCap]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[d0+a0][b0][c0][0]==false&&withinCap(d0+a0, b0, c0, 0)){
                    //cout<<"d-->a(<aCap)"<<endl;
                    addToQueue(d0+a0, b0, c0, 0);
                    level[d0+a0][b0][c0][0]=level[a0][b0][c0][d0]+1;
                }
            }
            //d-->b
            if(b0+d0>bCap){
                if(visited[a0][bCap][c0][d0+b0-bCap]==false&&withinCap(a0, bCap, c0, d0+b0-bCap)){
                    //cout<<"d-->b(>bCap)"<<endl;
                    addToQueue(a0, bCap, c0, d0+b0-bCap);
                    level[a0][bCap][c0][d0+b0-bCap]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[a0][b0+d0][c0][0]==false&&withinCap(a0, b0+d0, c0, 0)){
                    //cout<<"d-->b(<aCap)"<<endl;
                    addToQueue(a0, b0+d0, c0, 0);
                    level[a0][b0+d0][c0][0]=level[a0][b0][c0][d0]+1;
                }
            }
            //d-->c
            if(c0+d0>cCap){
                if(visited[a0][b0][cCap][d0+c0-cCap]==false&&withinCap(a0, b0, cCap, d0+c0-cCap)){
                    //cout<<"d-->c(>cCap)"<<endl;
                    addToQueue(a0, b0, cCap, d0+c0-cCap);
                    level[a0][b0][cCap][d0+c0-cCap]=level[a0][b0][c0][d0]+1;
                }
            }
            else{
                if(visited[a0][b0][c0+d0][0]==false&&withinCap(a0, b0, c0+d0, 0)){
                    //cout<<"d-->c(>cCap)"<<endl;
                    addToQueue(a0, b0, c0+d0, 0);
                    level[a0][b0][c0+d0][0]=level[a0][b0][c0][d0]+1;
                }
            }
        }
        ////cout<<"-------------------------------------"<<endl;
    }
    
}
int main(){
    char input[30];
    while(gets(input)){
        for(int i=0;i<27;i++){
            for(int j=0;j<27;j++){
                for(int m=0;m<27;m++){
                    for(int k=0;k<27;k++){
                        visited[i][j][m][k]=false;
                        level[i][j][m][k]=-1;
                    }
                }
            }
        }
        char* temp=strtok(input," ");
        aCap=stoi(temp);
        temp=strtok(NULL," ");
        bCap=stoi(temp);
        temp=strtok(NULL," ");
        cCap=stoi(temp);
        temp=strtok(NULL," ");
        dCap=stoi(temp);
        temp=strtok(NULL," ");
        T=stoi(temp);
        //cout<<aCap<<" "<<bCap<<" "<<cCap<<" "<<dCap<<endl;
        bfs(0,0,0,0);
        //cout<<"**************************"<<endl;
        //cout<<res.size()<<endl;
        if(res.size()==0) cout<<-1<<endl;
        else cout<<*res.begin()<<endl;
        res.clear();
        queue<int> emptyA;
        swap(qA, emptyA );
        queue<int> emptyB;
        swap(qB, emptyB );
        queue<int> emptyC;
        swap(qC, emptyC );
        queue<int> emptyD;
        swap(qD, emptyD);
    }
}

