#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
double dist[200][200];
vector<pair<double, double>> graph[200];
int stoneNo;
double getMax(double d1, double d2){
    if(d1>d2) return d1;
    return d2;
}
double getMin(double d1, double d2){
    if(d1<d2) return d1;
    return d2;
}
int main(){
    int caseNo=0;
    while(cin>>stoneNo){
        if(stoneNo==0) break;
        getchar();
        for(int i=0;i<200;i++){
            for(int j=0;j<200;j++){
                dist[i][j]=100000000;
            }
        }
        for(int i=0;i<200;i++)
            graph[i].clear();
        for(int i=0;i<stoneNo;i++){
            double x, y;
            scanf("%lf %lf\n",&x, &y);
            graph[i].push_back(make_pair(x,y));
        }
        for(int i=0;i<stoneNo;i++){
            for(int j=0;j<stoneNo;j++){
                dist[i][j]=sqrt(pow((graph[i][0].first-graph[j][0].first),2)+pow((graph[i][0].second-graph[j][0].second),2));
            }
        }
        for(int k=0;k<stoneNo;k++)
            for(int i=0;i<stoneNo;i++)
                for(int j=0;j<stoneNo;j++)
                {
                    dist[i][j] =getMin(dist[i][j], getMax(dist[i][k], dist[k][j]));
                }
        
        cout<<"Scenario #"<<(++caseNo)<<endl;
        double res=dist[0][1];
        printf("Frog Distance = %.3f\n\n",res);
    }
}

