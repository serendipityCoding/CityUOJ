#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;
struct Record{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    long long number;
    bool isImportant;
};
Record* arr;
int dp[1100];
int currentYear;
bool isEarlier(Record r1, Record r2){
    //return true if r2 is earlier than r1
    if(r2.month<r1.month) return true;
    else if (r2.month>r1.month) return false;
    else{
        if(r2.day<r1.day) return true;
        else if(r2.day>r1.day) return false;
        else{
            if(r2.hour<r1.hour) return true;
            else if(r2.hour>r1.hour) return false;
            else{
                if(r2.minute<r1.minute) return true;
                else if(r2.minute>r1.minute) return false;
                else return true;
            }
        }
    }
}
void getYear(int recordNo){
    arr[0].year=0;
    for(int i=1;i<recordNo;i++){
        if(isEarlier(arr[i-1],arr[i])) {
            arr[i].year=arr[i-1].year+1;
            currentYear+=1;
        }
        else arr[i].year=arr[i-1].year;
    }
}
int getMinimum(int recordNo){
    int firstImportant;
    for(int i=0;i<recordNo;i++){
        if(arr[i].isImportant==true){
            firstImportant=i;
            break;
        }
    }
    int lastImportant;
    for(int i=0;i<recordNo;i++){
        if(arr[i].isImportant==true){
            lastImportant=i;
        }
    }
    dp[firstImportant]=1;
    for(int i=firstImportant+1;i<recordNo;i++){
        dp[i]=dp[i-1]+1;
        for(int j=i-1;j>=0;j--){
            if(arr[i].year==arr[j].year) dp[i]=min(dp[i],dp[j]+1);
            else if(arr[i].year==(arr[j].year+1)&&isEarlier(arr[i], arr[j])==false) dp[i]=min(dp[i],dp[j]+1);
            else break;
            if(arr[j].isImportant==true) break;
        }
    }
    int res=dp[recordNo-1];
    for(int i=recordNo-2;i>=lastImportant&&arr[i].year==currentYear;i--){
        res=min(res,dp[i]);
    }
    return res;
}
int main(){
    int recordNo;
    while(scanf("%d",&recordNo)&&recordNo!=0){
        getchar();
        currentYear=0;
        arr=new Record[recordNo];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<recordNo;i++){
            int month0, day0, hour0, minute0;
            long long number0;
            char important;
            scanf("%d:%d:%d:%d %lld %c",&month0,&day0,&hour0,&minute0,&number0,&important);
            getchar();
            arr[i].month=month0;
            arr[i].day=day0;
            arr[i].hour=hour0;
            arr[i].minute=minute0;
            arr[i].number=number0;
            if(important=='+') arr[i].isImportant=true;
            else arr[i].isImportant=false;
        }
        getYear(recordNo);
        cout<<getMinimum(recordNo)<<endl;
        delete[] arr;
    }
}
