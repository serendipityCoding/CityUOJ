#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <iterator>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
int** countries;
int* tax;
int* parent;
int size;
int getSize(char* input){
    char* temp=strtok(input," ");
    int n=0;
    while(temp!=NULL){
        n+=1;
        temp=strtok(NULL," ");
    }
    return n;
}
int getMin(int* arr){
    int min=arr[0];
    for(int i=1;i<size;i++){
        if(min>arr[i]) min=arr[i];
    }
    return min;
}
int findMinimum(int src, int dest){
    bool* visited=new bool[size];
    int* des=new int[size];
    parent=new int[size];
    set<int> s;
    for(int i=0;i<size;i++){
        visited[i]=false;
        des[i]=0xfffffff;
        parent[i]=-1;
    }
    visited[src]=true;
    des[src]=0;
    parent[src]=-1;
    s.insert(src);
    while(!s.empty()){
        int startNode=*s.begin();
        visited[startNode]=true;
        s.erase(s.begin());
        for(int c=0;c<size;c++){
            if(countries[startNode][c]!=-1&&c!=startNode){
                if(des[c]>des[startNode]+countries[startNode][c]+tax[c]){
                    int temp=des[startNode]+countries[startNode][c]+tax[c];
                    des[c]=temp;
                    parent[c]=startNode;
                    s.insert(c);
                }
            }
        }
    }
    if(dest==src) return 0;
    else return des[dest]-tax[dest];
}
void printPath(int src,int dest){
    vector<int> res;
    if(parent[dest]==-1) res.push_back(dest);
    else{
        int temp=dest;
        res.push_back(dest);
        do{
            res.push_back(parent[temp]);
            temp=parent[temp];
        }while(temp!=src);
    }
    for(int i=res.size();i>0;i--){
        int c;
        if(res[i-1]==-1) c=src;
        else c=res[i-1]+1;
        if(i!=1) cout<<c<<"-->";
        else cout<<c;
    }
    cout<<endl;
}
int main(){
    int testCases;
    scanf("%d\n\n",&testCases);
    string pu;

    for(int i=0;i<testCases;i++){
        char input[1000];
        gets(input);
        char t[1000];
        strcpy(t, input);
        size=getSize(t);
        countries=new int*[size];
        for(int j=0;j<size;j++){
            countries[j]=new int[size];
        }
        tax=new int[size];
        for(int k=0;k<size;k++){
            char* temp=strtok(input," ");
            int n=0;
            while(temp!=NULL){
                countries[k][n++]=stoi(temp);
                temp=strtok(NULL," ");
            }
            gets(input);
        }

        char* temp=strtok(input," ");
        int n=0;
        while(temp!=NULL){
            tax[n++]=stoi(temp);
            temp=strtok(NULL," ");
        }
        string srcdest;
        int cnt=0;
        while(getline(cin,srcdest)){
            if(cnt!=0)cout<<endl;
            if(!srcdest.compare("\0")) break;
            istringstream buf(srcdest);
            istream_iterator<string> beg(buf), end;
            vector<string> tokens(beg, end);
            cout<<"From "<<tokens[0]<<" to "<<tokens[1]<<" :"<<endl;
            int res=findMinimum(stoi(tokens[0])-1,stoi(tokens[1])-1);
            cout<<"Path: ";
            printPath(stoi(tokens[0])-1,stoi(tokens[1])-1);
            cout<<"Total cost : ";
            cout<<res<<endl;
            cnt++;
        }
    }
    return 0;
}
