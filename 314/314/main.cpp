#include<iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <string.h>
using namespace std;
int failure[100005];
int length;
void getFailure(string s){
    failure[0]=-1;
    int count=-1;
    for(int i=1;i<length;i++){
        while(count>=0&&s[count+1]!=s[i]){
            count=failure[count];
        }
        if(s[count+1]==s[i]){
            count+=1;
        }
        failure[i]=count;
    }
}
int KMP(string s,string cpy){
    getFailure(cpy);
    int count=-1;
    for(int i=0;i<length;i++){
        while(count>=0&&cpy[count+1]!=s[i]){
            count=failure[count];
        }
        if(cpy[count+1]==s[i]){
            count+=1;
        }
    }
    return count;
}
int main(){
    string s;
    while(getline(cin,s)){
        length=s.length();
        string cpy=s;
        reverse(cpy.begin(),cpy.end());
        int flag=KMP(s,cpy);
        cout<<s;
        for(int i=flag+1;i<=length-1;i++){
            cout<<cpy[i];
        }
        cout<<endl;
    }
}
