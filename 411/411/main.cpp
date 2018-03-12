#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <utility>
using namespace std;
long long rowNo, seatNo;
long long reservedNo;
long long reserve[48][2];
set<pair<long long,long long>> res;
set<long long> rowCount;
int main(){
    int testCase;
    cin>>testCase;
    for(int i=0;i<testCase;i++){
        cin>>rowNo>>seatNo;
        cin>>reservedNo;
        long long sum=0;
        for(long long j=0;j<reservedNo;j++){
            cin>>reserve[j][0];
            rowCount.insert(reserve[j][0]);
        }
        for(long long j=0;j<reservedNo;j++){
            cin>>reserve[j][1];
        }
        sum+=(seatNo-1)*(rowNo-rowCount.size());
        for(const long long l:rowCount){
            for(long long j=0;j<reservedNo;j++){
                if(reserve[j][0]==l){
                    if(reserve[j][1]==1&&reserve[j][1]+1<=seatNo){
                        res.insert(make_pair(reserve[j][1],reserve[j][1]+1));
                    }
                    else if(reserve[j][1]==seatNo&&reserve[j][1]-1>=1){
                        res.insert(make_pair(reserve[j][1]-1,reserve[j][1]));
                    }
                    else{
                        if(reserve[j][1]-1>=1){
                            res.insert(make_pair(reserve[j][1]-1,reserve[j][1]));
                        }
                        if(reserve[j][1]+1<=seatNo){
                            res.insert(make_pair(reserve[j][1],reserve[j][1]+1));
                        }
                    }
                }
            }
            sum+=(seatNo-1)-res.size();
            res.clear();
        }
        cout<<"Case #"<<(i+1)<<": "<<sum<<endl;
        rowCount.clear();
        res.clear();
    }
}
