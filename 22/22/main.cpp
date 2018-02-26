#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream>
#include <utility>
#include <set>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;
bool primes[10000];
void generatePrimes(){
    int low=1000;
    int high=9999;
    int flag;
    while (low < high){
        flag = 0;
        for(int i = 2; i <= low/2; ++i){
            if(low % i == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            primes[low]=true;
        ++low;
    }
}
int replaceFirst(string s, int i){
    s[0]='0'+i;
    return stoi(s);
}
int replaceSecond(string s, int i){
    s[1]='0'+i;
    //cout<<s<<endl;
    return stoi(s);
}
int replaceThird(string s, int i){
    s[2]='0'+i;
    return stoi(s);
}
int replaceFourth(string s, int i){
    s[3]='0'+i;
    return stoi(s);
}
int main(){
    memset(primes,false,sizeof(primes));
    generatePrimes();
    int testCases;
    scanf("%d",&testCases);
    for(int i=0;i<testCases;i++){
        int src,dest;
        scanf("%d %d",&src,&dest);
        bool visited[10000];
        memset(visited,false,sizeof(visited));
        int dist[10000];
        memset(dist,0xffffffff,sizeof(dist));
        int parent[10000]={-2};
        queue<int> s;
        s.push(src);
        visited[src]=true;
        dist[src]=0;
        parent[src]=-2;
        bool isFound=false;
        while(!s.empty()){
            int q=s.front();
            if(q==dest) {
                isFound=true;
                break;
            }
            s.pop();
            string n1=to_string(q);
            int n2;
            for(int i=0;i<10;i++){
                if(i!=0&&('0'+i)!=n1[0]){
                    n2=replaceFirst(n1,i);
                    if(primes[n2]==true){
                        if(visited[n2]==false){
                            visited[n2]=true;
                            dist[n2]=dist[q]+1;
                            parent[n2]=q;
                            s.push(n2);
                        }
                    }
                }
                if(('0'+i)!=n1[1]){
                    n2=replaceSecond(n1,i);
                    if(primes[n2]==true){
                        if(visited[n2]==false){
                            visited[n2]=true;
                            dist[n2]=dist[q]+1;
                            parent[n2]=q;
                            s.push(n2);
                        }
                    }
                }
                if(('0'+i)!=n1[2]){
                    n2=replaceThird(n1,i);
                    if(primes[n2]==true){
                        if(visited[n2]==false){
                            visited[n2]=true;
                            dist[n2]=dist[q]+1;
                            parent[n2]=q;
                            s.push(n2);
                        }
                    }
                }
                if(('0'+i)!=n1[3]){
                    n2=replaceFourth(n1,i);
                    if(primes[n2]==true){
                        if(visited[n2]==false){
                            visited[n2]=true;
                            dist[n2]=dist[q]+1;
                            parent[n2]=q;
                            s.push(n2);
                        }
                    }
                }
            }
//            cout<<q<<endl;
//            cout<<"---------------------------------"<<endl;
//            queue<int> copy = s;
//            while (!copy.empty())
//            {
//                cout << copy.front() << " ";
//                copy.pop();
//            }
//            std::cout << std::endl;
//            cout<<"---------------------------------"<<endl;
        }
        int d=dest;
        cout<<d<<endl;;
        while(parent[d]!=-2){
            cout<<parent[d]<<endl;
            d=parent[d];
        }
        if(isFound==true) cout<<dist[dest]<<endl;
        else cout<<"Impossible"<<endl;
    }
}
