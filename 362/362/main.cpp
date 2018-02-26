#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include <math.h>
#define INF 999999999
using namespace std;
int width, height;
int defenderNo, dist;
int defender[102][2];
struct edge{
    int from;
    int to;
    int length;
    
};
int main(){
    while(cin>>height>>width>>defenderNo>>dist){
        if(height==0&&width==0&&defenderNo==0&&dist==0) break;
        for(int i=1;i<=defenderNo;i++){
            cin>>defender[i][0]>>defender[i][1];
        }
    }
}
