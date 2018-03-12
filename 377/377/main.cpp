#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
#define M 5005
//long long graph[M][M];
int visited[M];
int employeeNo,n;
long long total=0;
int fireNo;
struct Edge{
    int v;//to node, from node can be obtaind by using index in adjacent array
    long long flow;//flow of data in edge
    long long C;//capacity
    int rev;//index of reverse dge
};
// Residual Graph
class Graph{
    int V; // number of vertex
    int *level; // stores level of a node
    vector<Edge> *adj;
    public:
    Graph(int V){
        adj=new vector<Edge>[V];
        this->V=V;
        level=new int[V];
    }
    // add edge to the graph
    void addEdge(int u,int v,int C){
        //Forward edge : 0 flow and C capacity
        Edge a{v,0,C,(int)adj[v].size()};
        // Back edge : 0 flow and 0 capacity
        Edge b{u,0,0,(int)adj[u].size()};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }
    bool BFS(int s,int t);
    long long sendFlow(int s,long long flow,int t,int ptr[]);
    long long DinicMaxflow(int s,int t);
    void dfs(int s);
};
bool Graph::BFS(int s,int t){
    for(int i=0;i<V;i++)
        level[i]=-1;
    level[s]=0; //Level of source node
    queue<int>q;
    q.push(s);
    vector<Edge>::iterator i ;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(i=adj[u].begin();i!=adj[u].end();i++){
            Edge &e=*i;
            if(level[e.v]<0&&e.flow<e.C){
                level[e.v]=level[u]+1;
                q.push(e.v);
            }
        }
    }
    if(level[t]<0) return false;
    return true;
}
long long Graph::sendFlow(int u, long long flow, int t, int start[]){
    if (u==t)
        return flow;
    // Traverse all adjacent edges one -by - one.
    for(;start[u]<adj[u].size();start[u]++){
        Edge &e=adj[u][start[u]];
        if(level[e.v]==level[u]+1&&e.flow<e.C){
            //find minimum flow from u to t
            long long pathFlow;
            if(flow<e.C-e.flow) pathFlow=flow;
            else pathFlow=e.C-e.flow;
            long long tempFlow=sendFlow(e.v,pathFlow,t,start);
            if(tempFlow>0){
                e.flow+=tempFlow;
                adj[e.v][e.rev].flow-=tempFlow;
                return tempFlow;
            }
        }
    }
    return 0;
}

// Returns maximum flow in graph
long long Graph::DinicMaxflow(int s, int t){
    // Corner case
    if(s==t) return -1;
    long long total=0;//Initialize result
    //Augment the flow while there is path
    //from source to sink
    while(BFS(s,t)==true){
        // store how many edges are visited
        // from V {0 to V}
        int *start=new int[V+1];
        // while flow is not zero in graph from S to D
        while(long long flow=sendFlow(s, INT_MAX,t,start)){
            total+=flow;
        }
    }
    // return maximum flow
    return total;
}
void Graph::dfs(int s){
    visited[s]=1;
    fireNo+=1;
    vector<Edge>::iterator i ;
    for(i=adj[s].begin();i!=adj[s].end();i++){
        Edge &e=*i;
        //cout<<e.flow<<" "<<e.C<<endl;
        if(e.flow<e.C&&!visited[e.v]){
            dfs(e.v);
        }
    }
}
int main(){
    while(cin>>employeeNo>>n){
        total=0;
        fireNo=0;
        int temp;
        Graph g(employeeNo+2);
        for(int i=1;i<=employeeNo;i++){
            cin>>temp;
            //if it is net profit, connect it to the source node
            if(temp>0){
                g.addEdge(0,i,temp);
                total+=temp;
            }
            //if it is net loss, connect it to the sink node
            else g.addEdge(i,employeeNo+1,-temp);
        }
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            g.addEdge(x,y,9999999999);//if there is any underlining relationship, mark the edge capacity as INFINITE
        }
        memset(visited,0,sizeof(visited));
        long long res=total-g.DinicMaxflow(0,employeeNo+1);
        g.dfs(0);
        cout<<fireNo-1<<" "<<res<<endl;
    }
}
//#include <iostream>
//#include <stdio.h>
//#include <queue>
//#include <string>
//#include <cstring>
//#include <string.h>
//#include <vector>
//#include <limits.h>
//using namespace std;
//#define M 5005
//long long employees[M];
//long long graph[M][M];
//long long rGraph[M][M];
//int employeeNo,n;
//long long total=0;
//bool isVisited[M];
//int fireNo;
//bool bfs(long long rGraph[M][M],int s,int t,int parent[]){
//    bool visited[M];
//    memset(visited,0,sizeof(visited));
//    queue<int> q;
//    q.push(s);
//    visited[s]=true;
//    parent[s]=-1;
//    while(!q.empty()){
//        int u=q.front();
//        q.pop();
//        for (int v=0;v<employeeNo+2;v++){
//            if(visited[v]==false&&rGraph[u][v]>0){
//                q.push(v);
//                parent[v]=u;
//                visited[v]=true;
//            }
//        }
//    }
//    return (visited[t]==true);
//}
//void getFireNo(int s){
//    isVisited[s]=true;
//    fireNo+=1;
//    for (int i=0;i<M; i++){
//        if(rGraph[s][i]>0&&!isVisited[i]){
//            getFireNo(i);
//        }
//    }
//}
//void maxFlow(){
//    //use maxFlow to get the max flow
//    //create residue graph
//    for(int t=0;t<=(employeeNo+1);t++){
//        for(int j=0;j<=(employeeNo+1);j++){
//            rGraph[t][j]=graph[t][j];
//        }
//    }
//    int parent[M];
//    long long maxFlow = 0;
//    //when there is any augment path is the residue graph
//    while(bfs(rGraph,0,employeeNo+1,parent)){
//        long long pathFlow=9999999999;
//        //calculate the flow of the augment path
//        for(int v=employeeNo+1;v!=0;v=parent[v]){
//            int u=parent[v];
//            //if the residue capacity is less the path flow, set the path flow to the capacity
//            //get the maximum possible flow
//            if(pathFlow>rGraph[u][v]) pathFlow=rGraph[u][v];
//        }
//        //update the residue graph based on the path stored in the parent array with the previous max flow
//        for(int v=employeeNo+1;v!=0;v=parent[v]){
//            int u=parent[v];
//            rGraph[u][v]-=pathFlow;
//            rGraph[v][u]+=pathFlow;
//        }
//        //add the flow of the augment path to the total flow
//        maxFlow+=pathFlow;
//    }
//    memset(isVisited,false,sizeof(isVisited));
//    //use dfs to check how many edges are not fully used except the first one connect to the source node
//    getFireNo(0);
//    cout<<fireNo-1<<" "<<total-maxFlow<<endl;
//}
//int main(){
//    while(cin>>employeeNo>>n){
//        total=0;
//        fireNo=0;
//        for(int i=1;i<=employeeNo;i++){
//            cin>>employees[i];
//            //if it is net profit, connect it to the source node
//            if(employees[i]>0){
//                graph[0][i]=employees[i];
//                total+=employees[i];
//            }
//            //if it is net loss, connect it to the sink node
//            else graph[i][employeeNo+1]=-employees[i];
//        }
//        for(int i=0;i<n;i++){
//            int x,y;
//            cin>>x>>y;
//            //if there is any underlining relationship, mark the edge capacity as INFINITE
//            graph[x][y]=9999999999;
//        }
//        maxFlow();
//    }
//}
////run time error: if create a residue graph every time the funtion is invoked, in c++, the function has a limited size for
////memory allocation, so when the array size is bigger than the allocation memory, run time error
//
//
