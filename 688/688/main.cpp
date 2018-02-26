#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
char graph[8][8];
bool valid[8][8];
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int blackX, blackY;
int whiteX, whiteY;
int step[8][8];
bool isValid(int x,int y){
    if(x>=0&&x<8&&y>=0&&y<8) return true;
    return false;
}
void dfs(int currentX, int currentY, int step0){
    queue<pair<int,int>> s;
    valid[currentX][currentY]=false;
    s.push(make_pair(currentX,currentY));
    step[currentX][currentY]=step0;
    while(!s.empty()){
        pair<int,int> p=s.front();
        s.pop();
        valid[p.first][p.second]=false;
        for(int i=0;i<8;i++){
            int x=p.first+dx[i];
            int y=p.second+dy[i];
            if(isValid(x,y)&&valid[x][y]==true){
                step[x][y]=step[p.first][p.second]+1;
                s.push(make_pair(x,y));
            }
        }
    }
    if(step[whiteX][whiteY]!=-1) cout<<step[whiteX][whiteY]<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}
int main(){
    int testCases;
    scanf("%d",&testCases);
    for(int k=0;k<testCases;k++){
        getchar();
        memset(graph,'0',sizeof(graph));
        memset(valid,true,sizeof(valid));
        memset(step,-1,sizeof(step));
        for(int i=0;i<8;i++){
            string input="";
            getline(cin,input);
            for(int j=0;j<8;j++){
                graph[i][j]=input[j];
                if(input[j]=='#') {
                    blackX=i;
                    blackY=j;
                }
                if(input[j]=='@') {
                    whiteX=i;
                    whiteY=j;
                }
                if(input[j]=='*'){
                    valid[i][j]=false;
                }
            }
        }
        cout<<"Case "<<(k+1)<<": ";
        dfs(blackX,blackY,0);

    }
}
