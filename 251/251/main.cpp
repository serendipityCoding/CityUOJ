#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <utility>
#include <set>
using namespace std;
int width, height;
int graph[55][55];
bool visited[55][55];
bool visitedAll(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(visited[i][j]==false) return false;
        }
    }
    return true;
}
pair<int,int> getSrc(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(visited[i][j]==false) return make_pair(i,j);
        }
    }
    return make_pair(-1,-1);
}
int main(){
    while(cin>>width&&cin>>height){
        int islands=0;
        if(width==0&&height==0) break;

        memset(graph,-1,sizeof(graph));
        memset(visited,false,sizeof(visited));
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                cin>>graph[i][j];
                if(graph[i][j]==0) visited[i][j]=true;
            }
        }
        set<pair<int,int>> s;
        while(visitedAll()==false){
            pair<int,int> src=getSrc();
            s.insert(src);
            visited[src.first][src.second]=true;
            while(!s.empty()){
                pair<int,int> p=*s.begin();
                s.erase(s.begin());
                int x=p.first;
                int y=p.second;
                if(x-1>=0&&visited[x-1][y]==false) {
                    visited[x-1][y]=true;
                    s.insert(make_pair(x-1,y));
                }
                if(x+1<height&&visited[x+1][y]==false) {
                    visited[x+1][y]=true;
                    s.insert(make_pair(x+1,y));
                }
                if(x-1>=0&&y-1>=0&&visited[x-1][y-1]==false) {
                    visited[x-1][y-1]=true;
                    s.insert(make_pair(x-1,y-1));
                }
                if(x-1>=0&&y+1<width&&visited[x-1][y+1]==false) {
                    visited[x-1][y+1]=true;
                    s.insert(make_pair(x-1,y+1));
                }
                if(x+1<height&&y-1>=0&&visited[x+1][y-1]==false) {
                    visited[x+1][y-1]=true;
                    s.insert(make_pair(x+1,y-1));
                }
                if(x+1<height&&y+1<width&&visited[x+1][y+1]==false) {
                    visited[x+1][y+1]=true;
                    s.insert(make_pair(x+1,y+1));
                }
                if(y-1>=0&&visited[x][y-1]==false) {
                    visited[x][y-1]=true;
                    s.insert(make_pair(x,y-1));
                }
                if(y+1<width&&visited[x][y+1]==false) {
                    visited[x][y+1]=true;
                    s.insert(make_pair(x,y+1));
                }
            }
            islands+=1;
        }
        cout<<islands<<endl;
    }
}
