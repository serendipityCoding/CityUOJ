#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
#include <sstream>
#include <iterator>
#include <stdlib.h>
using namespace std;
int placeNo;
int roadNo;
vector<string> places;
int office;
int hall;
int graph[200][200];
vector<string> officeToHall;
vector<string> hallToOffice;
int getNodeID(string s){
    int i;
    for(i=0;i<placeNo;i++){
        if(!s.compare(places[i])) {
            return i;
        }
    }
    return 0;
}
int getNode2ID(int start, string s){
    for(int i=0;i<placeNo;i++){
        string p=places[i];
        int count=0;
        for(int j=(start+1);j<s.length();j++){
            if(s[j]!=p[count]) break;
            if(s[j]==p[count]) count+=1;
            if(count==p.length()) break;
        }
        if(count==p.length()) return i;
    }
    return 0;
}
vector<string> split(const string& s, char delimiter)
{
    vector<std::string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}
int getPathOfficeToHall(){
    bool visited[200];
    memset(visited,false,sizeof(visited));
    int dist[200];
    int parent[200];
    memset(dist,0x3f,sizeof(dist));
    memset(parent,-2,sizeof(parent));
    dist[office]=0;
    parent[office]=-1;
    vector<int> s;
    s.push_back(office);
    while(!s.empty()){
        int fromNode=s.front();
        int min=dist[fromNode];
        int pos=0;
        for(int i=0;i<s.size();i++){
            if(dist[s[i]]<min){
                min=dist[s[i]];
                fromNode=s[i];
                pos=i;
            }
        }
        s.erase(s.begin()+pos);
        if(visited[fromNode]==true) continue;
        else visited[fromNode]=true;
        for(int i=0;i<200;i++){
            if(graph[fromNode][i]!=-1){
                int toNode=i;
                int length=graph[fromNode][i];
                if(dist[toNode]>length+dist[fromNode]){
                    parent[toNode]=fromNode;
                    dist[toNode]=length+dist[fromNode];
                    s.push_back(toNode);
                }
            }
        }
    }
    int c=hall;
    while(parent[c]!=-1){
        officeToHall.push_back(places[c]);
        c=parent[c];
    }
    officeToHall.push_back("office");
    return dist[hall];
}
int getPathHalltoOffice(){
    bool visited[200];
    memset(visited,false,sizeof(visited));
    int dist[200];
    int parent[200];
    memset(dist,0x3f,sizeof(dist));
    memset(parent,-2,sizeof(parent));
    dist[hall]=0;
    parent[hall]=-1;
    vector<int> s;
    s.push_back(hall);
    while(!s.empty()){
        int fromNode=s.front();
        int min=dist[fromNode];
        int pos=0;
        for(int i=0;i<s.size();i++){
            if(dist[s[i]]<min){
                min=dist[s[i]];
                fromNode=s[i];
                pos=i;
            }
        }
        s.erase(s.begin()+pos);
        if(visited[fromNode]==true) continue;
        else visited[fromNode]=true;
        for(int i=0;i<200;i++){
            if(graph[fromNode][i]!=-1){
                int toNode=i;
                int length=graph[fromNode][i];
                if(dist[toNode]>length+dist[fromNode]){
                    parent[toNode]=fromNode;
                    dist[toNode]=length+dist[fromNode];
                    s.push_back(toNode);
                }
            }
        }
    }
    int c=office;
    while(parent[c]!=-1){
        hallToOffice.push_back(places[c]);
        c=parent[c];
    }
    return dist[office];
}
int main(){
    while(scanf("%d\n",&placeNo)!=EOF){
        memset(graph,-1,sizeof(graph));
        string p="";
        for(int i=0;i<placeNo;i++){
            getline(cin,p);
            if(!p.compare("office")) office=i;
            if(!p.compare("hall")) hall=i;
            places.push_back(p);
        }
        scanf("%d\n",&roadNo);
        string r="";
        for(int i=0;i<roadNo;i++){
            getline(cin,r);
            string node1="";
            for(int j=0;j<r.length();j++){
                if(r[j]!=':') node1+=r[j];
                else break;
            }
            int n1=getNodeID(node1);
            int n2=getNode2ID(node1.length(),r);
            int s0=places[n1].length()+places[n2].length()+2;
            string lengthTemp="";
            for(int j=s0;j<r.length();j++){
                lengthTemp+=r[j];
            }
            vector<string> temp=split(lengthTemp,' ');
            if(temp.size()==1){
                int l=stoi(temp[0]);
                graph[n1][n2]=l;
            }
            else if(temp.size()==2){
                int l1=stoi(temp[0]);
                int l2=stoi(temp[1]);
                graph[n1][n2]=l1;
                graph[n2][n1]=l2;
            }
        }
        int d1=getPathOfficeToHall();
        int d2=getPathHalltoOffice();
        cout<<d1+d2<<endl;
        for(int m=officeToHall.size();m>0;m--){
            cout<<officeToHall[m-1]<<" -> ";
        }
        for(int m=hallToOffice.size();m>0;m--){
            cout<<hallToOffice[m-1];
            if(m!=1) cout<<" -> ";
        }
        cout<<endl;
        cout<<endl;
        places.clear();
        officeToHall.clear();
        hallToOffice.clear();
    }
}

