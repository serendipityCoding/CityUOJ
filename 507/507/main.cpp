#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <utility>
#define INFINITY 0x3f3f3f3f
using namespace std;
vector<pair<int,int>> corridors[500000];
vector<pair<char,int>> trap[1000];
set<int> weight;
bool* hasTrap;
int* dist;
bool* visited;
int roomNo, corridorNo, trapNo, entrance, initialRing, treasure,openRing;
int getRing(int absoluteRing){
    if(absoluteRing>=1&& absoluteRing<=12) return absoluteRing;
    if(absoluteRing>12){
        return absoluteRing%12;
    }
    else{
        absoluteRing*=-1;
        return 12-absoluteRing%12;
    }
}
int getCurrentRing(char c, int step, int r0){
    switch(c){
        case '+':
            return r0+step;
            break;
        case '-':
            return r0-step;
            break;
        case '=':
            return step;
            break;
        case '*':
            return step*r0;
            break;
        default:
            return -1;
            break;
    }
}
void findAllPath(int previousNode, int fromNode, int w, int currentRing){
    if(fromNode==treasure&&currentRing==openRing){
        weight.insert(w);
    }
    else if(fromNode==treasure&&currentRing!=openRing){
        visited[previousNode]=false;
    }
    else{
        visited[fromNode]=true;
        for(int i=0;i<corridors[fromNode].size();i++){
            pair<int,int> toNode=corridors[fromNode][i];
            int toNodeIndex=toNode.first;
            int toNodeWeight=toNode.second;
            if(visited[toNodeIndex]==false){
                if(hasTrap[toNodeIndex]==true){
                    int temp=getRing(getCurrentRing(trap[toNodeIndex][0].first,trap[toNodeIndex][0].second,currentRing));
                    findAllPath(fromNode,toNodeIndex, (w+toNodeWeight), temp);
                }
                else{
                    findAllPath(fromNode,toNodeIndex,(w+toNodeWeight),currentRing);
                }
            }
        }
    }
}
int main(){
    while(scanf("%d %d %d %d %d %d %d\n",&roomNo, &corridorNo, &trapNo, &entrance, &initialRing, &treasure, &openRing)!=EOF){
        for(int i=0;i<corridorNo;i++){
            int node1, node2, length;
            scanf("%d %d %d\n",&node1, &node2, &length);
            corridors[node1].push_back(make_pair(node2,length));
            corridors[node2].push_back(make_pair(node1,length));
        }
        dist=new int[roomNo+1];
        hasTrap=new bool[roomNo+1];
        visited=new bool[roomNo+1];
        for(int i=1;i<=roomNo;i++){
            dist[i]=INFINITY;;
            hasTrap[i]=false;
            visited[i]=false;
        }
        char t[100];
        for(int i=0;i<trapNo;i++){
            gets(t);
            char* temp=strtok(t," ");
            int c=stoi(temp);
            hasTrap[c]=true;
            temp=strtok(NULL," ");
            char m=*temp;
            temp=strtok(NULL," ");
            int l=stoi(temp);
            trap[c].push_back(make_pair(m,l));
        }
        int src=entrance;
        findAllPath(src, src,0,initialRing);
        if(weight.size()==0) cout<<"Pray!"<<endl;
        else cout<<*weight.begin()<<endl;
        weight.clear();
        delete[] dist;
        delete[] hasTrap;
        delete[] visited;
        //cout<<"testCase"<<endl;
    }
}
